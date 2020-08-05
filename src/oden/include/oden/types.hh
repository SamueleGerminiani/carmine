#pragma once

#include "oden/classes/atom/Atom.hh"

//==== external libraries ===================================================
#include "oden/odenUtils/rapidxml/rapidxml_utils.hh" // RAPIDXML headers
//---------------------------------------------------------------------------

namespace oden {

using XmlNode = rapidxml::xml_node<>;
using XmlNodeList = std::vector<XmlNode *>;

} // namespace oden
