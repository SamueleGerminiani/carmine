#include "oden/odenEnums.hh"

namespace oden {

template <typename ET, typename RT>
TypeCast<ET, RT>::TypeCast(ET *e, VarType type, uint8_t size)
    : RT(type, size), _e(e) {
  // ntd
}

template <typename ET, typename RT> TypeCast<ET, RT>::~TypeCast() { delete _e; }

template <typename ET, typename RT> ET &TypeCast<ET, RT>::getItem() {
  return *_e;
}

} // namespace oden
