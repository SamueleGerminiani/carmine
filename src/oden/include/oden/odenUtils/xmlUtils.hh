#pragma once

#include "oden/types.hh"
#include <string>

namespace oden {

/// @brief Fill a xml list with all xml nodels having a specific name.
/// @param node The starting xml node of the function search.
/// @param name The name of wanted xml nodes.
/// @param node A list of wanted xml nodes.
void getNodesFromName(XmlNode *node, const std::string &nanme,
                      XmlNodeList &list);

/// @brief Return as string the attribute's value of a xml node.
/// @param node A xml node.
/// @param node The attribute's name of the given node.
/// @param node The default string if the attribute has not been set.
/// @return A string containing the attribute's value or the defaultValue
std::string getAttributeValue(XmlNode *node, const std::string &attributeName,
                              const std::string &defaultValue = "");
} // namespace oden
