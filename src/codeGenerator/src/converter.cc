#include "converter.hh"

namespace codeGenerator {

namespace converter {

SpotAutomata generateAutomata(const PSLformula &formula) {
  spot::parsed_formula pf = spot::parse_infix_psl(formula);
  messageErrorIf(pf.format_errors(std::cerr),
                 "SpotLTL: Syntax errors in assertion:\n" +
                     formula);


  spot::translator trans;
  trans.set_pref(spot::postprocessor::Complete);

  auto res = trans.run(pf.f);

  //    DEBUG
  // print_hoa(std::cout, res) << '\n';

  return res;
}

//Generate and print checker
void generateChecker(const std::string& inputFormula,const std::unordered_map<std::string,std::string>& map){
 spot::parsed_formula pf = spot::parse_infix_psl(inputFormula);

  if (pf.format_errors(std::cerr)){
     std::cout<<"Error during parsing"<<std::endl;
	 return;
  }
  spot::translator trans;
  trans.set_type(spot::postprocessor::Monitor);
  trans.set_pref(spot::postprocessor::Deterministic);
  spot::twa_graph_ptr aut = trans.run(pf.f);

  std::cout<<"const int ERROR = -1;"<<std::endl;
  std::cout<<"void checker(bool const reset, bool& param_fail, bool& param_fail_if_last_cycle";


  //Add all input variables (atomic propositions and placeholders) 
  for(auto f: aut->ap()){
	std::cout<<", bool "<<f;
  }

	std::cout<<"){"<<std::endl;
	
	std::cout<<"static int NEXT_STATE = "<<aut->get_init_state_number()<<";"<<std::endl;

  std::cout<<"if(reset){\nNEXT_STATE = "<<aut->get_init_state_number()<<";\n return;\n}"<<std::endl;
  
  //Set param_fail to false, will be eventually set to true in sink error state
  std::cout<<"param_fail = false;"<<std::endl;

  std::cout<<"switch(NEXT_STATE){"<<std::endl;
  const spot::bdd_dict_ptr &dict = aut->get_dict();
  unsigned num_states = aut -> num_states();

	for(unsigned state = 0; state < num_states; state++){
		std::cout<< "\ncase " << state <<":"<<std::endl;
		for(auto &edge : aut->out(state)){
			spot::formula f = spot::parse_formula(spot::bdd_format_formula(dict,edge.cond));
			//Convert formula to string format
			std::string stringF = formulaToString(f, map);		
			std::cout<<"if("<<stringF<<"){"<<std::endl;
			std::cout<<"NEXT_STATE = "<<edge.dst<<";"<<std::endl;
			std::cout<<"}"<<std::endl;

		}

		std::cout<<"else{\nNEXT_STATE = ERROR;\n param_fail = true; \n}"<<std::endl;
		std::cout<<"break;"<<std::endl;
	}

	//Sink state error
	std::cout<<"\ncase ERROR: \n param_fail = true;\nbreak;"<<std::endl;
	
	std::cout<<"}"<<std::endl; //close switch
	std::cout<<"}"<<std::endl; //close function
}

std::string formulaToString(const spot::formula f, const std::unordered_map<std::string,std::string>& map){

	//And
	if(f.is(spot::op::And)){
		return "(" + formulaToString(f[0], map) + " && " + formulaToString(f[1], map) + ")";
	}
	
	//Or
	if(f.is(spot::op::Or)){
		return "(" + formulaToString(f[0] , map) + " || " + formulaToString(f[1], map) + ")";
	}

	//Not
	if(f.is(spot::op::Not)){
		if(f[0].is(spot::op::ap)){
			return "!" + f[0].ap_name();
		}
		else{
			return "!" + formulaToString(f[0], map);
		}
	}

	//Atomic proposition
	if(f.is(spot::op::ap)){
			return f.ap_name();
		}
	}


//Given an LTL formula, replace expressions between a delimiter, e.g. '' with placeholders like p0. 
//Use a map to keep trace of the raplecements for later use
void insertPlaceholders(std::string& inputFormula, const char delimiter, std::unordered_map<std::string,std::string>& map){

	std::string newFormula;
	std::string subFormula;
	bool insideDelimiter = false;
	int count = 0;
	
	for(char &c: inputFormula){
		if(c == delimiter){
			if(insideDelimiter){ //Found trailing delimiter, stop replacing subFormula
				insideDelimiter = false;
				auto const placeholder = "p" + std::to_string(count);
				map.insert(make_pair(placeholder, subFormula));
				newFormula+=placeholder;
				count++;
			}
			else{ //Found leading delimiter, start replacing subFormula
				insideDelimiter = true;
				subFormula = "";
			}
		}

		else if(insideDelimiter){ //Replace subFormula
			subFormula+=c;
		}

		else{ //Outside delimiters, don't replace subFormula
			newFormula+=c;
		}
	}

	inputFormula = newFormula;
}


} // namespace Converter
} // namespace codeGenerator
