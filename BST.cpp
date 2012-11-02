#include "BST.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

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
  if (curr==0) 
    return 0;   
  else if (curr->getLeftChild()==0)
    return 0;
  else {
    parent=curr;
    curr=curr->getLeftChild();
  }
    
  while (curr->getRightChild()!=0) {
    parent=curr;
    curr=curr->getRightChild();
  }
  
  return curr;
}

template <typename T>
Node<T>* BST<T>::findIOS(Node<T>* curr,Node<T>* &parent) {
  if (curr==0) 
    return 0;   
  else if (curr->getRightChild()==0)
    return 0;
  else {
    parent=curr;
    curr=curr->getRightChild();
  }

  while (curr->getLeftChild()!=0) {
    parent=curr;
    curr=curr->getLeftChild();
  }

  return curr;
}

template <typename T>
void BST<T>::removeTree(Node<T>* curr) {
  if (curr!=0) {
    removeTree(curr->getLeftChild());
    removeTree(curr->getRightChild());
    delete curr;
  }
}

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  removeTree(root);  
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
  else if (curr->getValue()==v) {
    delete newNode;
    return;
  }
  while (curr!=0) {
    if (v<curr->getValue()) {
      prev=curr;
      curr=curr->getLeftChild();
    }
    else if (v>curr->getValue()) {
      prev=curr;
      curr=curr->getRightChild();
    }
    else {  // if v==curr->getValue()
      delete newNode;
      return;
    }
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

/*
template <typename T>
void BST<T>::removeNode(Node<T>* remNode) {

}
*/

template <typename T>
void BST<T>::remove(T v) {

  bool isLC=false;  // remNode is LC of parent?
  bool isRC=false;  // remNode is RC of parent?
  Node<T>* parent=0;
  Node<T>* remNode=findNode(v,root,parent,isLC,isRC); // node to be removed
  
  if (remNode==0) // remNode not in BST
    return;

  Node<T>* remLCNode=remNode->getLeftChild();  // LC of node to be removed
  Node<T>* remRCNode=remNode->getRightChild(); // RC of node to be removed

/*  
  if (parent!=0) cout<<"parent: " << parent->getValue()<<endl;
  if (remNode!=0) {
    cout<<"remNode: " << remNode->getValue()<<endl;
  }
  cout << "isLC: " << isLC << endl;
  cout << "isRC: " << isRC << endl;
  if (remLCNode!=0) cout << "remLCNode: " << remLCNode->getValue() << endl;
  if (remRCNode!=0) cout << "remRCNode: " << remRCNode->getValue() << endl;
*/


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

  else {  // remNode has two children (need to use IOS or IOP)
    Node<T>* iopParent=0;
    Node<T>* iop=findIOP(remNode,iopParent);
    Node<T>* newIOP=new Node<T>(iop->getValue());

    // cout << "IOP: " << iop->getValue() << endl;
    remove(iop->getValue());
    // cout << "Past 2nd remove." << endl;    
    

    if (isLC) {
      parent->setLeftChild(newIOP);
      newIOP->setLeftChild(remNode->getLeftChild());
      newIOP->setRightChild(remNode->getRightChild());
      delete remNode;
    }
    else {
      parent->setRightChild(newIOP);
      newIOP->setLeftChild(remNode->getLeftChild());
      newIOP->setRightChild(remNode->getRightChild());
      delete remNode;
    }
  }
}

template <typename T>
void BST<T>::print() {
  printTree(); 

  // traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template <typename T>
void BST<T>::printTree() {

  bool isEmptyLevel=false; 
  int numLevels=0;

  vector<vector<Node<T>* > > levelVector;
  vector<Node<T>* > currLevel(1,root);

  // currLevel[0]=root;
  if (currLevel[0]==0) {
    isEmptyLevel=true;
  }
  else {
    levelVector.push_back(currLevel);
    numLevels++;
  }

  // int numLevels=1;
  // int numEmptyNodes=0;
  
  while (isEmptyLevel==false) {  

    currLevel.resize(2*levelVector[numLevels-1].size());
    for (unsigned int i=0;i<levelVector[numLevels-1].size();i++) {
      if (levelVector[numLevels-1][i]!=0) {
        currLevel[2*i]=levelVector[numLevels-1][i]->getLeftChild();
        currLevel[2*i+1]=levelVector[numLevels-1][i]->getRightChild();
      }
      else {
        currLevel[2*i]=0;
        currLevel[2*i+1]=0;
      } 
    }
  
    // bool isEmptyLevel=false;
    for (unsigned int i=0;i<currLevel.size();i++) {
      if (currLevel[i]!=0) {
        isEmptyLevel=false;
        break;
      }
    isEmptyLevel=true;
    }
  
    if (isEmptyLevel==false) {
      levelVector.push_back(currLevel);
      numLevels++;
    }
  }   

  // now print it out

  for (unsigned int i=0;i<levelVector.size();i++) {
    for (unsigned int j=0;j<levelVector[i].size();j++) {
      if (levelVector[i][j]!=0)
        cout << levelVector[i][j]->getValue() << " ";
      else
        cout << "X ";
    }
    cout << endl;
  }

}

template class BST<int>;
template class BST<double>;
//template class BST<std::string>;
