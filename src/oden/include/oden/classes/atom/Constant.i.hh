
#include "oden/odenEnums.hh"

namespace oden {

template <typename T>
Constant<T>::Constant(T value, VarType type, uint8_t size)
    : Atom<T>(type, size), _value(value) {}

template <typename T>
Constant<T>::Constant(const Constant &other) : Atom<T>(), _value(other._value) {
  // ntd
}

template <typename T>
NamedConstant<T>::NamedConstant(std::string name, T value, VarType type,
                                uint8_t size)
    : Constant<T>(value, type, size), _name(name) {
  // ntd
}
} // namespace oden
