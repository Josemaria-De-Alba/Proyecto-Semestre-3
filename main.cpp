#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include "info.h"

template <class T>
void printInfo(std::vector<T> data){
  for (unsigned int i = 0; i < data.size(); i++){
    std::cout<<data[i]<<std::endl;
  }
}

template <class T>
string arrayToString(const vector<T> &v) {
  stringstream aux;

  aux << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    aux << ", " << v[i];
  }
  aux << "]";
  return aux.str();
}



int main(){
  std::cout << "Start of Double List Test" << std::endl;
  DList<int> Damage;
  Damage.insertion(5);
  Damage.insertion(10);
  Damage.insertion(8);
  Damage.insertion(2);
  Damage.insertion(20);
  std::cout << Damage.toStringForward() << std::endl;
  Damage.update(3, 15);
  std::cout << Damage.toStringForward() << std::endl;
  std::cout << Damage.toStringBackward() << std::endl;
  DList<std::string>Names;
  Names.insertion("Ace");
  Names.insertion("Ghallarhorn");
  Names.insertion("Final Warning");
  Names.insertion("Sunshot");
  std::cout << Names.toStringForward() << endl;
  
  std::vector<int> damageV = Damage.toVector();
  DList<int> prueba;
  std::vector<int> j = prueba.sort(damageV);

  std::cout << arrayToString(j) << endl;

  std::vector<string>nameV = Names.toVector();
  DList<string> prueba2;
  std::vector<string>k = prueba2.sort(nameV);

  std::cout << arrayToString(k) << endl;;

  std::cout << Damage.search(10) << std::endl;

  Damage.deleteAt(3);
  
  std::cout << Damage.toStringForward() << std::endl << std::endl;


  std::cout << "Start of Binary Tree Tests" << std::endl;
  //Binary Tree

  BSTInfo<int> treeNumbers;
  treeNumbers.add(5);
  treeNumbers.add(10);
  treeNumbers.add(20);
  treeNumbers.add(3);
  treeNumbers.add(4);
  treeNumbers.add(6);

  std::cout << treeNumbers.inorder() << endl;
  std::cout << treeNumbers.preorder() << endl;
  std::cout << treeNumbers.postorder() << endl;

  std::cout << "Height is: " << treeNumbers.height() << endl;
  
  BSTInfo<std::string> treeNames;
  treeNames.add("Trinity Ghoul");
  treeNames.add("Burried Bloodlines");
  treeNames.add("Verglas Curve");
  treeNames.add("Choir of One");
  treeNames.add("Red Death Reformed");
  treeNames.add("Quicksilver Storm");
  
  std::cout << treeNames.inorder() << endl;
  std::cout << treeNames.preorder() << endl;
  std::cout << treeNames.postorder() << endl;

}
