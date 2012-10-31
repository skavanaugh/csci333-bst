#include <string>
#include <cassert>
#include "Node.h"

template <typename T>
Node<T>::Node(T v) {
  value = v;
  leftChild = 0;
  rightChild = 0;
}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template <typename T>
Node<T>*& Node<T>::getLeftChild() {
  assert(this!=0);
  return leftChild;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>& lc) {
  assert(this!=0);
  leftChild = &lc;
}

template <typename T>
Node<T>*& Node<T>::getRightChild() {
  assert(this!=0);
  return rightChild;
}

template <typename T>
void Node<T>::setRightChild(Node<T>& rc) {
  assert(this!=0);
  rightChild = &rc;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

