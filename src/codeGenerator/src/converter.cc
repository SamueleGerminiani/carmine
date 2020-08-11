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
  //print_hoa(std::cout, res) << '\n';


  //Check if automata is deterministic

  if(! (spot::is_universal(res))){
	std::cout<<"WARNING: could not generate deterministic automata for formula "<<formula<<std::endl;
  }

  return res;
}

//Generate and print checker
void generateChecker(const SpotAutomata& aut, std::ofstream& outstream ){
  outstream<<"//Return true if checker did not fail"<<std::endl;
  outstream<<"bool checker(";

  //Add all input variables (atomic propositions and placeholders) 
  for(auto f: aut->ap()){
	outstream<<"bool "<<f<<", ";
  }

  outstream<<"bool const reset = false";

	outstream<<"){"<<std::endl;
	
	outstream<<codeGenerator::ident1<<"static int NEXT_STATE = "<<aut->get_init_state_number()<<";"<<std::endl;

  outstream<<codeGenerator::ident1<<"if(reset){\n"<<codeGenerator::ident2<<"NEXT_STATE = "<<aut->get_init_state_number()<<";\n    }"<<std::endl;
  
  outstream<<codeGenerator::ident1<<"switch(NEXT_STATE){"<<std::endl;
  const spot::bdd_dict_ptr &dict = aut->get_dict();
  unsigned num_states = aut -> num_states();

	for(unsigned state = 0; state < num_states; state++){
		//Don't process error states
		if ( aut->state_is_accepting(state)){ //Current state is not an error state
		
			outstream<<"\n"<<codeGenerator::ident2<<"case " << state <<":"<<std::endl;
			for(auto &edge : aut->out(state)){
				spot::formula f = spot::parse_formula(spot::bdd_format_formula(dict,edge.cond));
				//Convert formula to string format
				std::string stringF = formulaToString(f);	

				//Skip self loops
				if(! (stringF.compare("1") == 0 && state == edge.dst)){
					
					outstream<<codeGenerator::ident3<<"if("<<stringF<<"){"<<std::endl;

					//Don't go in error state but stay in current state and return false
					if( aut->state_is_accepting(edge.dst) == false){ //Next state is error state
						outstream<<codeGenerator::ident4<<"return false;"<<std::endl;
					}

					else{
						outstream<<codeGenerator::ident4<<"NEXT_STATE = "<<edge.dst<<";"<<std::endl;
					}
					
					outstream<<codeGenerator::ident3<<"}"<<std::endl;

			}
			
		}
         outstream<<codeGenerator::ident3<<"break;"<<std::endl;
		}
  }

	
	
	outstream<<"\n"<<codeGenerator::ident2<<"return true;"<<std::endl; 
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
