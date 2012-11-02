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
  bst->insert(18);
  bst->insert(23);
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

  bst->remove(20);
  bst->print();
  cout<<endl;

  bst->remove(23);
  bst->print();
  cout<<endl;
 
  bst->remove(7);
  bst->print(); 
}
