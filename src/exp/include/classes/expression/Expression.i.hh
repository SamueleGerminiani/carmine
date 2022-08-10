
namespace expression {

template <BinaryOperator O, typename OT, typename ET>
Expression<O, OT, ET>::Expression() : ET(), _items() {
  // ntd
}

template <BinaryOperator O, typename OT, typename ET>
void Expression<O, OT, ET>::addItem(OT *item) {
  _items.push_back(item);
}

template <BinaryOperator O, typename OT, typename ET>
std::vector<OT *> &Expression<O, OT, ET>::getItems() {
  return _items;
}

template <BinaryOperator O, typename OT, typename ET>
size_t Expression<O, OT, ET>::size() {
  return _items.size();
}

template <BinaryOperator O, typename OT, typename ET>
bool Expression<O, OT, ET>::empty() {
  return _items.empty();
}

} // namespace expression
