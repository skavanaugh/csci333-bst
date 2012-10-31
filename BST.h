#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>
#include <cassert>

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);

  Node<T>* find(T v,Node<T>* curr,Node<T>*& parent);
  Node<T>* findIOP(Node<T>* curr, Node<T>*& parent);

 public:
  BST<T>();
  ~BST<T>();

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
};


#endif
