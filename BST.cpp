#include "BST.h"
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
Node<T>* BST<T>::find(T val,Node<T>* curr,Node<T>*& parent) {
  if (curr==0)
    return 0;
  else if (curr->getValue()==val)
    return curr;
  else if (curr->getValue()<val)
    return find(val,curr->getLeftChild(),curr);
  else
    return find(val,curr->getRightChild(),curr);
}

template <typename T>
Node<T>* BST<T>::findIOP(Node<T>* curr,Node*& parent) {
  Node* curr=0;
  if (curr==0) // should this be an assertion??
    return 0;   
  else if (curr->getLeftChild()==0)
    return 0;
  else {
    parent=curr;
    curr=curr->getLeftChild();
  }

  while (curr!=0) {
    parent=curr;
    curr=curr->getRightChild();
  }

  return curr;
}

template <typename T>
Node<T>* BST<T>::findIOS(Node<T>* curr,Node*& parent) {
  Node* curr=0;
  if (curr==0) // should this be an assertion??
    return 0;   
  else if (curr->getRightChild()==0)
    return 0;
  else {
    parent=curr;
    curr=curr->getRightChild();
  }

  while (curr!=0) {
    parent=curr;
    curr=curr->getLeftChild();
  }

  return curr;
}

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
//  Node<T>* temp = new Node<T>(v);
//  root = temp;  
//  return true;

  Node<T>* fNode=0;
  Node<T>* parent=0;

  fNode=find(v,root,parent);
  
  if (fNode==0)
    return false;
  else 
    return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
//  Node<T>* temp = new Node<T>(v);
//  root = temp;

  Node* parent=0;
  Node* remNode=find(v,root,parent); // node to be removed
  Node* remLCNode=remNode->getLeftChild();
  Node* remRCNode=remNode->getRightChild();

  if (remLCNode==0 && remRCNode==0) {
    if (parent->getLeftChild()==v) {
      parent->setLeftChild(0);
      delete remNode;
    }
    else {
      parent->setRightChild(0);
      delete remNode;
    }
  }
  else if (remLCNode==0 && remRCNode!=0) {
    if (parent->getLeftChild()==v) {
      parent->setLeftChild(remRCNode);
      delete remNode;
    }
    else {
      parent->setRightChild(remRCNode);
      delete remNode;
    }
  }
  else if (remLCNode!=0 && remRCNode==0) {
    if (parent->getLeftChild()==v) {
      parent->setLeftChld(remLCNode);
      delete remNode;
    }
    else {
      parent->setLeftChild(remRCNode);
      delete remNode;
    }
  }


}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
