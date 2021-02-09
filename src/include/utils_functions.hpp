 //Struct used to parse variables informations from the xml specification
  struct checkerVar{
    std::string type;
    std::string varName;
    std::string msgType;
    std::string topicName;
    std::string msgField;
  };

  //Map used to store the binding between the addEvent_varx function of the checkers 
  //and the variable it refers to
  //Key = checker's name
  //Value = vector of checkerVar
  //If vector[0] = "msg.a" then the function addEvent_var0 of the checker 
  //will take msg.a as a parameter
  std::map<std::string,std::vector<checkerVar>> bindings;

//Trim string
inline std::string trim(const std::string &s)
{
   auto wsfront=std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
   auto wsback=std::find_if_not(s.rbegin(),s.rend(),[](int c){return std::isspace(c);}).base();
   return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}

//Given a variable declaration split its type and its name
//eg int a gets splitted into "int" and "a" 
void getVarName(std::string& name,std::string& type,std::string& decl){
    decl = trim(decl); 
    auto p = decl.find_last_of(" ");
    type = decl.substr(0,p);
    name = decl.substr(p+1);
}

//Parse variables and for each variable fill checkerVar struct
  void parseVariables(std::vector<checkerVar>& parsed,rapidxml::XmlNodeList& variables){
    
    for (auto v: variables){
      checkerVar var;
      auto decl = rapidxml::getAttributeValue(v,"decl","");
      getVarName(var.varName,var.type,decl);
      rapidxml::XmlNodeList list;
      rapidxml::getNodesFromName(v,"msgType",list);
      var.msgType = list[0]->value();
      list.clear();
      rapidxml::getNodesFromName(v,"rosTopic",list);
      var.topicName = list[0]->value();
      list.clear();
      rapidxml::getNodesFromName(v,"msgField",list);
      var.msgField = list[0]->value();
      parsed.push_back(var);
    } 
   

  }

  //Return a map with a type as key and as value the number of variables of that type
  std::map<std::string, int> countVarTypes(std::vector<checkerVar>& varList){
    std::map<std::string, int> res;

    for(auto v: varList){
      if(res.count(v.type) == 0){
        res.insert(std::pair<std::string, int>(v.type,1));
      }
      else{
        res[v.type]+=1;
      }
    }
    return res;
  }


  //Given a XmlNodeList of variable nodes return a map having the msgType as key
  //and as value a vector of checkerVar representing the variables that are updated from that topic
  void groupVariablesByMsgType(std::map<std::string,std::vector<checkerVar>>& parsedVars,std::vector<checkerVar>& varList){
    
    for (auto var: varList){

      if(parsedVars.count(var.msgType) == 0){
        parsedVars.insert(std::pair<std::string,std::vector<checkerVar>>(var.msgType, std::vector<checkerVar>()));
      }

      parsedVars[var.msgType].push_back(var);
    } 

  } 

  //Return a map with a placeholder as key and a vector of variables names as value
  void groupVariablesByPlaceholders(std::pair<std::string,std::unordered_map<std::string,oden::Proposition*>>& parsedFormula,
    std::map<std::string, std::vector<std::string>>& varsPH){
    for (auto p : parsedFormula.second) {

        //Get variables of the expression replaced by the placeholder
        auto vars = oden::prop2Vars(*p.second);
        varsPH[p.first] = vars;
      }
  }


  //Get parameters to pass to assign<bool>(order, index_p,...) in reorder()
  //E.g if we have p0,p1,p2 and p0,p2 are updated then getOrderEntries will return 1,0,1
  std::string getOrderEntries(std::vector<std::string>& placeholders, int totPlaceholders){
    std::string ret="";
    int indexVector = 0;
    for(int i = 0;i<totPlaceholders;i++){
      if(indexVector < placeholders.size() && placeholders[indexVector].compare("p"+std::to_string(i)) == 0){
        ret+=", 1";
        indexVector++;
      }
      else{
        ret+=", 0";
      }
    }
    return ret;
  }
 
 //Get parameters to pass to assign<bool>(pbuff, index_p,...) in reorder()
 std::string getPbuffEntries(std::vector<std::string>& placeholders, int totPlaceholders){
    std::string ret="";
    int indexVector = 0;
    for(int i = 0;i<totPlaceholders;i++){
      if(indexVector < placeholders.size() && placeholders[indexVector].compare("p"+std::to_string(i)) == 0){
        ret+=", "+placeholders[indexVector];
        indexVector++;
      }
      else{
        ret+=", 0";
      }
    }
    return ret;
  }

//Return a map having a pair <message type,topic> as key and as value a vector of the checkers that 
  //listen to that type and topic
  std::map<std::pair<std::string,std::string>,std::set<std::string>> groupCheckersByMsgTopic(rapidxml::XmlNodeList& checkers){
    std::map<std::pair<std::string,std::string>,std::set<std::string>> output;

    rapidxml::XmlNodeList variables,msg;
    for(auto ch: checkers){
      std::string name = rapidxml::getAttributeValue(ch,"name","");

      
      variables.clear();
      rapidxml::getNodesFromName(ch,"variable",variables);

      for(auto v: variables){

        rapidxml::getNodesFromName(v,"msgType",msg);
        
        std::string msgType = msg[0]->value();
        msg.clear();
        rapidxml::getNodesFromName(v,"rosTopic",msg);
        std::string rosTopic = msg[0]->value();

       
        //If the msg type is not already in the map instert it as key and create a new vector as value
        if(output.count(make_pair(msgType,rosTopic)) == 0){
          output.insert(std::pair<std::pair<std::string,std::string>,std::set<std::string>>(make_pair(msgType,rosTopic), std::set<std::string>()));
        }

        //Add checker's name to the vector
        output[make_pair(msgType,rosTopic)].insert(name);
        msg.clear();
      }
      
    }

    return output;

  }



