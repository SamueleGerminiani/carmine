#include "oden/odenEnums.hh"

namespace oden {

template <typename T>
Atom<T>::Atom(VarType type, uint8_t size) : _type(type), _size(size) {}

} // namespace oden
