#include "propositionUtils.hh"

namespace oden {

template <typename T1> void addItems(__attribute__((unused)) T1 &base) {
  // ntd. base case for variadic function.
}

template <typename T1, typename T2, typename... T3>
void addItems(T1 &base, T2 arg1, T3... args) {
  base.addItem(arg1);
  addItems(base, args...);
}

template <typename T1, typename... T2> T1 *makeExpression(T2... args) {
  auto *ret = new T1();
  addItems(*ret, args...);
  return ret;
}

} // namespace oden
