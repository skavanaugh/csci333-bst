#include "BST.h"
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
Node<T>* BST<T>::findNode(T val,Node<T>* curr,Node<T>* &parent,bool &isLC, bool &isRC) {
  // if (parent!=0) cout<<parent->getValue()<<endl;
  if (curr==0)
    return 0;
  else if (curr->getValue()==val)
    return curr;
  else if (curr->getValue()>val) {
    isLC=true;
    isRC=false;
    parent=curr;
    return findNode(val,curr->getLeftChild(),parent,isLC,isRC);
  }
  else {
    isLC=false;
    isRC=true;
    parent=curr;
    return findNode(val,curr->getRightChild(),parent,isLC,isRC);
  }
}

template <typename T>
Node<T>* BST<T>::findIOP(Node<T>* curr,Node<T>* &parent) {
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
Node<T>* BST<T>::findIOS(Node<T>* curr,Node<T>* &parent) {
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

  Node<T>* fNode=0;
  Node<T>* parent=0;
  bool isLC=false;
  bool isRC=false;

  fNode=findNode(v,root,parent,isLC,isRC);

  /*
  if (fNode!=0)
    cout << "fNode: " << fNode->getValue() << endl;
  if (parent!=0)
    cout << "parent: " << parent->getValue() << endl;
  cout << "isLC: " << isLC << endl;
  cout << "isRC: " << isRC << endl;  
  */

 
  if (fNode==0)
    return false;
  else 
    return true;
}

template <typename T>
void BST<T>::insert(T v) {

  Node<T>* newNode=new Node<T>(v);
  Node<T>* curr=root;
  Node<T>* prev=0;

  if (curr==0) {
    root=newNode;
    return;
  }
  else if (curr->getValue()==v)
    return;

  while (curr!=0) {
    if (v<curr->getValue()) {
      prev=curr;
      curr=curr->getLeftChild();
    }
    else if (v>curr->getValue()) {
      prev=curr;
      curr=curr->getRightChild();
    }
    else   // if v==curr->getValue()
      return;
  }

  if (v<prev->getValue())
    prev->setLeftChild(newNode);
  else
    prev->setRightChild(newNode);

/*  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
 */
}

template <typename T>
void BST<T>::remove(T v) {

  bool isLC=false;
  bool isRC=false;
  Node<T>* parent=0;
  Node<T>* remNode=findNode(v,root,parent,isLC,isRC); // node to be removed
  Node<T>* remLCNode=remNode->getLeftChild();  // left child of node to be removed
  Node<T>* remRCNode=remNode->getRightChild(); // right child of node to be removed
  
  if (parent!=0) cout<<"parent: " << parent->getValue()<<endl;
  if (remNode!=0) {
    cout<<"remNode: " << remNode->getValue()<<endl;
  }
  cout << "isLC: " << isLC << endl;
  cout << "isRC: " << isRC << endl;
  if (remLCNode!=0) cout << "remLCNode: " << remLCNode->getValue() << endl;
  if (remRCNode!=0) cout << "remRCNode: " << remRCNode->getValue() << endl;


  if (remLCNode==0 && remRCNode==0) {
    if (isLC) {
      parent->setLeftChild(0);
      delete remNode;
    }
    else {
      parent->setRightChild(0);
      delete remNode;
    }
  }
  else if (remLCNode==0 && remRCNode!=0) {
    if (isLC) {
      parent->setLeftChild(remRCNode);
      delete remNode;
    }
    else {
      parent->setRightChild(remRCNode);
      delete remNode;
    }
  }
  else if (remLCNode!=0 && remRCNode==0) {
    if (isLC) {
      parent->setLeftChild(remLCNode);
      delete remNode;
    }
    else {
      parent->setRightChild(remRCNode);
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
//template class BST<std::string>;
