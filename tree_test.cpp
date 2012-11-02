#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(5);
  bst->insert(6);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
  bst->insert(12);
  bst->insert(4);

  bst->print();
  
  cout<<bst->find(2)<<endl;
  cout<<bst->find(12)<<endl;
  cout<<bst->find(4)<<endl;
  cout<<bst->find(1)<<endl;

  bst->remove(4);
  bst->print();
  bst->remove(7);
  bst->print();

}
