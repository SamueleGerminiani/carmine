#include "oden/odenUtils/xmlUtils.hh"

namespace oden {

void getNodesFromName(XmlNode *root, const std::string &name,
                      XmlNodeList &list) {
    XmlNode *node;
    node = root->first_node(name.c_str(), name.size());

  while (node != nullptr) {
    list.push_back(node);
    node = node->next_sibling(name.c_str());
  }
}

std::string getAttributeValue(XmlNode *node, const std::string &attributeName,
                              const std::string &defaultValue) {
  auto ret = node->first_attribute(attributeName.c_str());
  return ret==nullptr ? defaultValue : ret->value();
}

} // namespace oden

