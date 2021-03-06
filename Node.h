#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
 private:
  T value;
  Node<T>* leftChild;
  Node<T>* rightChild;

 public:
  Node<T>(T v);
  T getValue();
  void setValue(T v);

  Node<T>* getLeftChild();
  void setLeftChild(Node<T>* n);

  Node<T>* getRightChild();
  void setRightChild(Node<T>* n);
};
#endif
