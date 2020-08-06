#include "converter.hh"

namespace codeGenerator {

namespace converter {

SpotAutomata generateAutomata(const PSLformula &formula) {
  spot::parsed_formula pf = spot::parse_infix_psl(formula);
  messageErrorIf(pf.format_errors(std::cerr),
                 "SpotLTL: Syntax errors in assertion:\n" +
                     formula);


  spot::translator trans;
  trans.set_type(spot::postprocessor::Monitor);
  trans.set_pref(spot::postprocessor::Deterministic);
  trans.set_pref(spot::postprocessor::Complete);

  auto res = trans.run(pf.f);

  //    DEBUG
  // print_hoa(std::cout, res) << '\n';

  return res;
}

//Generate and print checker
void generateChecker(const SpotAutomata& aut, std::ofstream& outstream ){

  outstream<<"const int ERROR = -1;"<<std::endl;
  outstream<<"void checker(bool const reset, bool& param_fail, bool& param_fail_if_last_cycle";


  //Add all input variables (atomic propositions and placeholders) 
  for(auto f: aut->ap()){
	outstream<<", bool "<<f;
  }

	outstream<<"){"<<std::endl;
	
	outstream<<codeGenerator::ident1<<"static int NEXT_STATE = "<<aut->get_init_state_number()<<";"<<std::endl;

  outstream<<codeGenerator::ident1<<"if(reset){\n"<<codeGenerator::ident2<<"NEXT_STATE = "<<aut->get_init_state_number()<<";\n      return;\n    }"<<std::endl;
  
  //Set param_fail to false, will be eventually set to true in sink error state
  outstream<<codeGenerator::ident1<<"param_fail = false;"<<std::endl;

  outstream<<codeGenerator::ident1<<"switch(NEXT_STATE){"<<std::endl;
  const spot::bdd_dict_ptr &dict = aut->get_dict();
  unsigned num_states = aut -> num_states();

	for(unsigned state = 0; state < num_states; state++){
		outstream<<"\n"<<codeGenerator::ident2<<"case " << state <<":"<<std::endl;
		for(auto &edge : aut->out(state)){
			spot::formula f = spot::parse_formula(spot::bdd_format_formula(dict,edge.cond));
			//Convert formula to string format
			std::string stringF = formulaToString(f);		
			outstream<<codeGenerator::ident3<<"if("<<stringF<<"){"<<std::endl;
			outstream<<codeGenerator::ident4<<"NEXT_STATE = "<<edge.dst<<";"<<std::endl;
			outstream<<codeGenerator::ident3<<"}"<<std::endl;

		}

		outstream<<codeGenerator::ident3<<"else{\n"<<codeGenerator::ident4<<"NEXT_STATE = ERROR;\n";
        outstream<<codeGenerator::ident4<< "param_fail = true;\n"<<codeGenerator::ident3<<"}"<<std::endl;
		outstream<<codeGenerator::ident3<<"break;"<<std::endl;
	}

	//Sink state error
	outstream<<"\n"<<codeGenerator::ident2<<"case ERROR: \n"<<codeGenerator::ident3<< "param_fail = true;\n"<<codeGenerator::ident3<<"break;"<<std::endl;
	
	outstream<<codeGenerator::ident1<<"}"<<std::endl; //close switch
	outstream<<"}"<<std::endl; //close function
}

std::string formulaToString(const spot::formula f){

	//And
	if(f.is(spot::op::And)){
		return "(" + formulaToString(f[0]) + " && " + formulaToString(f[1]) + ")";
	}
	
	//Or
	if(f.is(spot::op::Or)){
		return "(" + formulaToString(f[0]) + " || " + formulaToString(f[1]) + ")";
	}

	//Not
	if(f.is(spot::op::Not)){
		if(f[0].is(spot::op::ap)){
			return "!" + f[0].ap_name();
		}
		else{
			return "!" + formulaToString(f[0]);
		}
	}

	//Atomic proposition
	if(f.is(spot::op::ap)){
			return f.ap_name();
		}
	}

} // namespace Converter
} // namespace codeGenerator
