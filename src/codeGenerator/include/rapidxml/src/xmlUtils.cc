//#include "oden/odenUtils/xmlUtils.hh"
//
//namespace rapidxml {
//
//void getNodesFromName(XmlNode *root, const std::string &name,
//                      XmlNodeList &list) {
//    XmlNode *node = root->first_node(name.c_str(), name.size());
//    while (node != nullptr) {
//        list.push_back(node);
//        node = node->next_sibling(name.c_str());
//    }
//}
//
//std::string getAttributeValue(XmlNode *node, const std::string &attributeName,
//                              const std::string &defaultValue) {
//    std::string ret = node->first_attribute(attributeName.c_str())->value();
//    return ret.empty() ? defaultValue : ret;
//}
//
//} // namespace oden
