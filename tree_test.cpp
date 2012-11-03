#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

  BST<int>* bst = new BST<int>();

  bst->insert(10);
  bst->insert(5);
  bst->insert(15);
  bst->insert(20);
  bst->insert(16);
  bst->insert(17);
  bst->insert(23);
  // bst->insert(18);
  bst->insert(24);
  bst->insert(15);
  bst->insert(21);

  bst->print();
  
  cout<<endl;
  cout<<bst->find(10)<<endl;
  cout<<bst->find(17)<<endl;
  cout<<bst->find(18)<<endl;
  cout<<bst->find(1)<<endl;
  cout<<endl;

  bst->removeMutable(20);
  bst->print();
  cout<<endl;

  bst->removeMutable(23);
  bst->print();
  cout<<endl;
 
  bst->removeMutable(10);
  bst->print();

  delete bst;

  BST<double>* db=new BST<double>();
  db->insert(7.5);
  db->insert(12.98);
  db->insert(3.45);
  db->insert(-2.58);
  db->insert(99.1);
  db->print();
  db->removeStd(12.98);
  db->removeStd(7.5);
  db->removeStd(5.34353);
  db->print();
  delete db;

  BST<int>* b=new BST<int>();
  b->insert(10);
  b->insert(5);
  b->insert(15);
  b->insert(1);
  b->insert(7);
  b->insert(11);
  b->insert(17);
  b->insert(18);
  b->insert(12);
  b->insert(14);
  b->insert(19);
  b->insert(8);
  b->insert(9);

  b->print();
 
  b->remove(15);
  b->remove(12);
  b->remove(10);
  b->print();
  b->remove(19);
  b->print();

  delete b;
}
