#ifndef INFO_H_
#define INFO_H_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

template <class T> class DList;

template <class T>
class Info {
private:
  Info(T);
  Info(T, Info<T>*);
  Info(const Info<T>&);

  T	    data;
  Info<T> *next;
  Info<T> *prev;

  friend class DList<T>;
};

template <class T>
Info<T>::Info(T dat) :data(dat), next(0), prev(0){}

template <class T>
Info<T>::Info(T dat, Info* nxt): data(dat), next(next),prev(prev) {}

template <class T>
Info<T>::Info(const Info<T> &source):data(source.data), next(source.next),prev(source.previous) {}

template <class T>
class DList{
  private:
    Info <T> *head;
    Info <T> *tail;
    int size;
  public:
    std::string toString() const;
    DList();
    T insertion(T dat);
    T search(T dat);
    void update(T pos, T newdat);
    T deleteAt(int pos);
    std::string toStringForward();
    std::string toStringBackward();
    std::vector<T> sort(vector<T> &vinfo);
    std::vector<T> toVector();
};

template <class T>
DList<T>::DList():head(NULL),tail(NULL),size(0){}

template <class T>
T DList <T>::insertion(T dat){

  Info<T> *newInfo = new Info<T>(dat);
  if (tail == NULL){
    head = newInfo;
    tail = newInfo;
  }
  else {
    tail -> next = newInfo;
    newInfo -> prev = tail;
    tail = newInfo;
  }
  size++;
  return dat;
}

template <class T>
T DList <T>::search(T dat){
  Info<T> *p;
  p = head;
  int cont = 0;
  while (p != 0){
    if(p -> data == dat){
      return cont;
    }
    cont++;
    p = p -> next;
  }
  return -1;
}

template <class T>
void DList <T>::update(T pos, T newdat){
  Info<T> *p;
  p = head;
  int cont = 0;
  while (cont != pos){
    p = p -> next;
    cont ++;
  }
  p -> data = newdat;
}

template <class T>
T DList <T>::deleteAt(int pos){

  Info<T> *p, *q;
  p = head;
  q = NULL;
  T remove;
  int i = 0;
  if(pos == 0){
    remove = head -> data;
    p = head;
    head = head -> next;
    if(head != NULL){
      head -> prev = NULL;
    }
    else{
      tail = NULL;
    }
    delete p;
    size--;
    return remove;
  }
  while(p != NULL && i < pos){
    q = p;
    p = p -> next;
    i++;
  }
  remove = p -> data;
  q -> next = p -> next;
  if (p -> next != NULL){
    p -> next -> prev = q;
  }
  else{
    tail = q;
  }
  delete p;
  size--;
  return remove;

}

template <class T>
std::string DList<T>::toString() const {
  std::stringstream aux;
  Info<T> *p;

  p = head;
  aux << "[";
  while (p != 0) {
    aux << p->data;
    if (p->next != 0) {
      aux << ", ";
    }
    p = p->next;
  }
  aux << "]";
  return aux.str();
}

template <class T>
std::string DList<T>::toStringForward(){
  std::stringstream aux;
  Info<T> *p;

  p = head;
  aux << "[";
  while (p != 0) {
    aux << p->data;
    if (p->next != 0) {
      aux << ", ";
    }
    p = p->next;
  }
  aux << "]";
  return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward(){
  std::stringstream aux;
  Info<T> *p = tail;
  aux << "[";

  while (p != 0) {
    aux << p -> data;
    if (p -> prev!= 0) {
      aux << ", ";
    }
    p = p -> prev;
  }

  aux << "]";
  return aux.str();
}


template <class T>
std::vector<T> DList<T>::toVector(){
  std::vector<T> vec_info;
  Info<T> *current = head;

  while(current!= NULL){
    vec_info.push_back(current->data);
    current = current -> next;
  }
  return vec_info;
}

template <class T>
void swap(vector<T> &v, int i, int j){
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
std::vector<T> DList<T>::sort(vector<T> &vinfo){
  for(int i = vinfo.size() - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(vinfo[j] > vinfo[j+1]){
        swap(vinfo,j,j+1);
      }
    }
  }
  return vinfo;
}

//Binary Tree
template <class T> class BSTInfo;

template <class T>
class TreeNode {
private:
  T data;
  TreeNode *left, *right;

  TreeNode<T>* succesor();

public:
  TreeNode(T);
  TreeNode(T, TreeNode<T>*, TreeNode<T>*);
  void add(T);
  bool find(T);

  int counter = 1;

  void inorder(std::stringstream&) const;
  void preorder(std::stringstream&) const;
  void postorder(std::stringstream&) const;

  int getLevel(T dat, int level);

  friend class BSTInfo<T>;
};

template <class T>
TreeNode<T>::TreeNode(T dat) : data(dat), left(0), right(0) {}

template <class T>
TreeNode<T>::TreeNode(T dat, TreeNode<T> *le, TreeNode<T> *ri) : data(dat), left(le), right(ri) {}

template <class T>
void TreeNode<T>::add(T dat) {
  if (dat < data){
    if(left != 0){
      left -> add(dat);
    }else{
      left = new TreeNode<T>(dat);
    }
  } else{
    if(right != 0){
      right -> add(dat);
    } else{
      right = new TreeNode<T>(dat);
    }
  }
}

template <class T>
bool TreeNode<T>::find(T dat) {
  if (dat == data){
    return true;
  } else if (dat < data) {
    return (left != 0 && left->find(dat));
  } else if (dat > data) {
    return (right != 0 && right->find(dat));
  }
  return false;
} 

template <class T>
TreeNode<T>* TreeNode<T>::succesor() {
  TreeNode<T> *le, *ri, *parent, *child;
  le = left;
  ri = right;

  if (left == 0) {
    if (right != 0) {
      right = 0;
    }
    return ri;
  }

  if (left->right == 0) {
    left = left->left;
    le->left = 0;
    return le;
  }

  parent = left;
  child = left->right;
  while (child->right != 0) {
    parent = child;
    child = child->right;
  }
  parent->right = child->left;
  child->left = 0;
  return child;
}

template <class T>
void TreeNode<T>::inorder(std::stringstream &aux) const {
  if (left != 0) {
    left->inorder(aux);
  }
  if (aux.tellp() != 1) {
    aux << ", " ;
  }
  aux << data;
  if (right != 0) {
    right->inorder(aux);
  }
}

template <class T>
void TreeNode<T>::preorder(std::stringstream &aux) const {
  aux << data;
  if (left != 0) {
    aux << ", ";
    left->preorder(aux);
  }
  if (right != 0) {
    aux << ", ";
    right->preorder(aux);
  }
}

template <class T>
void TreeNode<T>::postorder(std::stringstream &aux) const {
  if (left != 0) {
    left->postorder(aux);
  }
  if (right != 0) {
    right->postorder(aux);
  }
  if (aux.tellp() != 1) {
    aux << ", ";
  }
  aux << data;
}

template <class T>
int TreeNode<T>::getLevel(T dat, int level){
  if (data == dat) {
            return level;
        }
        if (dat < data && left != 0) {
            return left->getLevel(dat, level + 1);
        }
        if (dat > data && right != 0) {
            return right->getLevel(dat, level + 1);
        }
        return 0;
}

template <class T>
class BSTInfo{
    private:
  TreeNode<T> *root;
  

    public:
    BSTInfo();
    T add(T dat);
    T height();
    bool empty() const;

  std::string inorder() const;
  std::string preorder() const;
  std::string postorder() const;
};

template <class T>
BSTInfo<T>::BSTInfo() : root(0) {}

template <class T>
bool BSTInfo<T>::empty() const {
  return (root == 0);
}

template <class T>
T BSTInfo<T>::add(T dat){
  if(root != 0){
    if (!root -> find(dat)){
      root -> add(dat);
    }
  }else{
    root = new TreeNode<T>(dat);
  }
  return dat;
}

template <class T>
T BSTInfo<T>::height(){
  if (root == NULL) {
      return 0;
  }

  TreeNode<T>* current = root; 
    int maxHeight = 0, currentHeight = 0;

  while (current != NULL) {
        if (current->left == NULL) {
            currentHeight++; 
            if (currentHeight > maxHeight) {
                maxHeight = currentHeight;
            }
            current = current->right; 
        } else {
            TreeNode<T>* pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = current;
                currentHeight++; 
                current = current->left; 
            } else {
                pre->right = NULL;
                current = current->right; 
                currentHeight--;
            }
        }
    }
    return maxHeight;
}

template <class T>
std::string BSTInfo<T>::inorder() const {
  std::stringstream aux;
  aux << "Data Start: ";
  if (!empty()) {
    root->inorder(aux);
  }
  aux << ".";
  return aux.str();
}

template <class T>
std::string BSTInfo<T>::preorder() const {
  std::stringstream aux;
  aux << "Data Start: ";
  if (!empty()) {
    root->preorder(aux);
  }
  aux << ".";
  return aux.str();
}

template <class T>
std::string BSTInfo<T>::postorder() const {
  std::stringstream aux;
  aux << "Data Start: ";
  if (!empty()) {
    root->postorder(aux);
  }
  aux << ".";
  return aux.str();
}

#endif
