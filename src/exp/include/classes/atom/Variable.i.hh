
namespace expression {

template <typename T>
Variable_Base<T>::Variable_Base(const std::string &name, VarType type,
                                uint8_t size)
    : Atom<T>(type, size), _name(name) {
  // ntd
}

template <typename T> const std::string &Variable_Base<T>::getName() {
  return _name;
}

} // namespace expression
