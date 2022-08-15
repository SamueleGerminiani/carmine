#pragma once
#include "types.hh"
#include "utils_functions.hh"
#include "xmlUtils.hh"
namespace codeGenerator {
inline strHandler parseSpecifications(const std::string &pathToSpec) {
  strHandler tmpHandler;
  // Parse xml file
  rapidxml::file<> *_xmlFile;
  rapidxml::xml_document<> *_doc;

  // find root node
  try {
    _xmlFile = new rapidxml::file<>(pathToSpec.c_str());
    _doc = new rapidxml::xml_document<>();
    _doc->parse<0>(_xmlFile->data());
  } catch (rapidxml::parse_error &e) {
    std::stringstream ss;
    ss << "Parsing error in " << /*configFile <<*/ " "
       << "\n"
       << e.m_what << " at line " << e.m_lineNumber << std::endl;
    if (!reinterpret_cast<char *>(e.m_where)[0]) {
      ss << "Hint: you probably forgot to close a tag\n";
    }
  }

  // the current machine handler
  auto root = _doc->first_node("handler");
  rapidxml::XmlNodeList monitors;

  // the monitors in the current machine handler
  rapidxml::getNodesFromName(root, "monitor", monitors);
  messageErrorIf(monitors.empty(),"No monitors found in specification file!");

  for (auto &ch : monitors) {
    strMonitor tmpMonitor;
    // parse the monitor's name
    tmpMonitor._name = rapidxml::getAttributeValue(ch, "name", "");
    tmpMonitor._LTLformula = rapidxml::getAttributeValue(ch, "LTLformula", "");
    rapidxml::XmlNodeList variables;
    rapidxml::getNodesFromName(ch, "variable", variables);
    for (auto &var : variables) {
      strVariable tmpVariable;
      tmpVariable._decl = rapidxml::getAttributeValue(var, "decl", "");
      rapidxml::XmlNodeList list;
      rapidxml::getNodesFromName(var, "filter", list);
      if (!list.empty()) {
        std::string val = list[0]->value();
        std::string option = "";
        if (val == "ma") {
          tmpVariable._filter.second =
              rapidxml::getAttributeValue(list[0], "window", "10");
          tmpVariable._filter.first = "ma";
        }
      } else {
        tmpVariable._filter.first = "none";
      }
      messageErrorIf(list.size() > 1, "Multiple filters defines for variable " +
                                          tmpVariable._decl);
      messageErrorIf(tmpVariable._filter.first != "ma" &&
                         tmpVariable._filter.first != "none",
                     "Uknown filter option");
      list.clear();
      rapidxml::getNodesFromName(var, "msgType", list);
      tmpVariable._msgType = list[0]->value();
      list.clear();
      rapidxml::getNodesFromName(var, "rosTopic", list);
      tmpVariable._rosTopic = list[0]->value();
      list.clear();
      rapidxml::getNodesFromName(var, "msgField", list);
      tmpVariable._msgField = list[0]->value();
      splitNameType(tmpVariable._name, tmpVariable._type, tmpVariable._decl);
      tmpMonitor._variables.push_back(tmpVariable);
    }

    rapidxml::XmlNodeList ovearheads;
    rapidxml::getNodesFromName(ch, "overhead", ovearheads);
    if (!ovearheads.empty()) {
      messageErrorIf(ovearheads.size() > 1,
                     "Multiple ovearheads defines for monitor " +
                         tmpMonitor._name);
      tmpMonitor._overhead =
          rapidxml::getAttributeValue(ovearheads[0], "us", "0");
    }else{
        tmpMonitor._overhead="none";
    
    }
    tmpHandler._monitors.push_back(tmpMonitor);
  }

  return tmpHandler;
}
} // namespace codeGenerator
