#ifndef INFO_H_
#define INFO_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct character_info{
 float percent;
 string name;
};

template <class T> class AVL;
template <class T> class Node;

template <class T>
class Sort{
private:
  vector<character_info> datos;
  int size = datos.size();
public:
  Sort(float pe, string na){
    datos.push_back({pe, na});
    size = datos.size();
  }
 /*
Agrega un porcentaje y un nombre al vector
@param float con el porcentaje de uso del personaje/arma
float con el nombre del personaje/arma
@return
 */
  void add(float percent, string name){
    datos.push_back({percent, name});
  }
  void swap(int i, int j){
    T aux = datos[i];
    datos[i] = datos[j];
    datos[j] = aux;
  }
/*
Organiza los datos dentro del vector de manera alfabeticamente
@param
@return
*/
  vector<character_info> MergeSort() {
    vector<character_info> tmp(datos.size());

    mergeSplit(datos, tmp, 0, datos.size() - 1);
    return datos;
  }
/*
Separa el vector en dos para hacerlo mas facil de organizar en el futuro
@param vector<character_info> el vector compuesto de los nombres y porcentajes
vector<character_info> otro vector compuesto de nombres y porcentajes
int low la posicion mas baja del vector
int high la posicion mas alta del vecor
@return
*/
  void mergeSplit(vector<character_info> &A, vector<character_info> &B, int low, int high){
    int mid;
  
    if((high - low < 1)){
      return;
    }
  
    mid=(high + low)/2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
  }
/*
Junta dos de los vectores que previamente estaban separados
@param vector<character_info> el vector compuesto de los nombres y porcentajes
vector<character_info> otro vector compuesto de nombres y porcentajes
int low la posicion mas baja del vector
int mid la posicion entermedia del vector
int high la posicion mas alta del vecor
@return
*/
  void mergeArray(vector<character_info> &A, vector<character_info> &B, int low, int mid, int high){
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;

  while (i<=mid && j<=high){
    if (A[i].name < A[j].name){
      B[k] = A[i];
      i++;
    }
    else{
      B[k] = A[j];
      j++;
    }
    k++;
  }
  if (i > mid){
    for(; j <= high; j++){
      B[k++] = A[j];
    }
  }
  else{
    for(; i <= mid; i++){
      B[k++] = A[i];
    }
  }
}
/*
Crea una copia del vector que contiene toda la informacion
@param vector<character_info> el vector compuesto de los nombres y porcentajes
vector<character_info> otro vector compuesto de nombres y porcentajes
int low la posicion mas baja del vector
int high la posicion mas alta del vecor
@return
*/
  void copyArray(vector<character_info> &A, vector<character_info> &B, int low, int high){
  for (int i = low; i <= high; i++) {
    A[i] = B[i];
  }
}

  void printArray(){
    for(int i = 0; i < datos.size(); i++){
      cout << "Name: " << datos[i].name << endl;
      cout << "Win/Use rate: " << datos[i].percent << endl;
    }
  }

  void find(float per){
    int confirm = 0;
      for(int i = 0; i < datos.size(); i++){
        if(datos[i].percent == per){
          cout << "The number " << per << " can be found in spot";
          cout << " number " << i << " with the name: ";
          cout << datos[i].name << endl;
          confirm = 1;
        }
      }
    if(confirm == 0){
      cout << "The number could not be found." << endl;
    }
  }
/*
Busca y elimina un dato dado por el usuario
@param float El dato que se busca para eliminar del vector.
@return
*/
  void remove(float per){
    int confirm = 0;
      for(int i = 0; i < datos.size(); i++){
        if(datos[i].percent == per){
          datos.erase(datos.begin() + i);
          confirm = 1;
        }
      }
    if(confirm == 0){
      cout << "The percent could not be found." << endl;
    }
  }
};

template <class T>
class Node{
private:
  Node *left, *right;
  int level, balance;
  Node<T>* predecesor();
  character_info data;

public:
  Node(float pe, string na){
    data.percent = pe;
    data.name = na;
    left = 0;
    right = 0;
    level = 0; 
    balance = 0;
  };

  Node(float pe, string na, Node<T> *le, Node<T> *ri, int lev, int bal){
    data.percent = pe;
    data.name = na;
    left = le;
    right = ri;
    level = lev; 
    balance = bal;
  }

  void add(float, string);
  bool find(float);
  void remove(float);
  void removeChilds();
  void inorder(std::stringstream&) const;
  int max_depth();
  Node<T>* check_tree(T*, Node<T>*, bool*);
  Node<T>* balance_tree();
  Node<T>* rot_left(Node<T>* );
  Node<T>* rot_right(Node<T>* );
  Node<T>* rot_left_right(Node<T>* );
  Node<T>* rot_right_left(Node<T>* );
  void smallest(std::stringstream &aux);
  void biggest(std::stringstream &aux);
  void save_data(std::stringstream &aux, ofstream &saving);

  friend class AVL<T>;
};
/*
Agrega un nodo dentro de la estructura AVL que contiene un valor float y un string
@param float Porcentaje dado por el usuario de que tanto se utiliza algo
string Nombre dado por el usuario para un arma/personaje
@return
*/
template <class T>
void Node<T>::add(float per, string na) {
  if (per < data.percent) {
    if (left != 0) {
      left->add(per, na);
    } else {
      left = new Node<T>(per, na);
    }
  } else {
    if (right != 0) {
      right->add(per, na);
    } else {
      right = new Node<T>(per, na);
    }
  }
}

/*
Busca si esta un elemento y confirma si esta dentro del arbol
@param float El valor que se busca dentro del arbol
@return float Confirma si el valor se encuentra dentro del arbol
*/
template <class T>
bool Node<T>::find(float per) {
  if (per == data.percent) {
    return true;
  } else if (per < data.percent) {
    return (left != 0 && left->find(per));
  } else if (per > data.percent) {
    return (right != 0 && right->find(per));
  }
  return 0;
}
/*
Ayuda a guardar que valores van antes de un nodo
@param
@return Node<T> Valor de un nodo previo 
*/
template <class T>
Node<T>* Node<T>::predecesor() {
  Node<T> *le, *ri;

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

  Node<T> *parent, *child;
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
/*
Elimina un nodo del arbol
@param float El valor que sera buscado dentro del arbol para ser 
eliminado
@return
*/
template <class T>
void Node<T>::remove(float per) {
  Node<T> * succ, *old;

  if (per < data.percent) {
    if (left != 0) {
      if (left->data.percent == per) {
        old = left;
        succ = left->predecesor();
        if (succ != 0) {
          succ->left = old->left;
          succ->right = old->right;
        }
        left = succ;
        delete old;
      } else {
        left->remove(per);
      }
    }
  } else if (per > data.percent) {
    if (right != 0) {
      if (right->data.percent == per) {
        old = right;
        succ = right->predecesor();
        if (succ != 0) {
          succ->left = old->left;
          succ->right = old->right;
        }
        right = succ;
        delete old;
      } else {
        right->remove(per);
      }
    }
  }
}
/*
Elimina los nodos hijos de un nodo
@param
@return
*/
template <class T>
void Node<T>::removeChilds() {
  if (left != 0) {
    left->removeChilds();
    delete left;
    left = 0;
  }
  if (right != 0) {
    right->removeChilds();
    delete right;
    right = 0;
  }
}
/*
Imprime todos los valores dentro del arbol
@param stringstream Una variable auxiliar donde se va guardando todo
lo que se debe de imprimir
@return
*/
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
  if (left != 0) {
    left->inorder(aux);
  }
  if (aux.tellp() != 1) {
    aux << " " << endl;
  }
  aux << "Character name: " << data.name << endl << "Character use rate (in%): " << data.percent;
  if (right != 0) {
    right->inorder(aux);
  }
}

/*
Funcion para encontrar cuanto es el camino mas largo desde la raiz
hasta el nodo hijo mas bajo
@param
@return int Valor del camino
*/
template <class T>
int Node<T>::max_depth() {
  int le =0 , ri = 0;
  if (left != 0)
    le = left->max_depth() + 1;
  if (right != 0)
    ri = right->max_depth() + 1;
  if(le > ri)
    level = le;
  else
    level = ri;
  balance = le - ri;
  return level;
}
/*
Checa el arbol para ver que este balanceado y llama la funcion
necesaria si necesita balancearse
@param T valor que se esta checando dentro del arbo
Node<T> parent node que va antes del nodo actual
bool confirmacion si ya fue checado el nodo
@return Node<T> El nodo que ha sido balanceado
*/
template <class T>
Node<T>* Node<T>::check_tree(T *check_val, Node<T> *parent, bool *checked) {
 
  Node<T>*le = 0, *ri = 0, *a = 0;
  if (left != 0)
    le = left->check_tree(check_val,this,checked);
  if (right != 0)
    ri = right->check_tree(check_val,this,checked);
  if (*checked == false){
    if (balance > 1){
      a = balance_tree();
      *check_val = data.percent;
      *checked = true;
      if(parent != 0){
        cout<< "parent  " << parent->data.percent <<" parent->left "<< parent->left->data.percent<< endl;
        parent->left = a;
      }
    }else if (balance < -1){
      a = balance_tree();
      *check_val = data.percent;
      *checked = true;
      if(parent != 0){
        cout<< "parent  " << parent->data.percent <<" parent->right "<< parent->right->data.percent<< endl;
        parent->right = a;
      }
    }
  }
  return a;
}
/*
Hace que este balanceado el nodo atraves de rotaciones
@param
@return Node<T> El nodo que ha sido balanceado
*/
template <class T>
Node<T>* Node<T>::balance_tree() {
  Node<T> *a = this, *le =left, *ri =right;
  if (balance > 0) {
    if (le->balance > 0){
      a = rot_right(a);
    }else{
      a = rot_left_right(a);
    }
  }else{
    if (ri->balance < 0){
      a = rot_left(a);
    }else{
      a = rot_right_left(a);
    }
  }
  return a;
}

/*
Rota un nodo a la izquierda
@param Node<T> Nodo que va a ser rotado
@return Node<T> Nodo que ha sido rotado
*/
template <class T>
Node<T>* Node<T>::rot_left(Node<T>* a){
  Node<T> *b, *temp = 0;
  b = 0;
  if (a->right != 0){
    b = a->right;
    if (b->left != 0)
      temp = b->left;
    b->left = a;
    if(temp != 0){
      a->right = temp;
    }else{
      a->right = 0;
    }
  }
  return b;
}
/*
Rota un nodo a la derecha
@param Node<T> Nodo que va a ser rotado
@return Node<T> Nodo que ha sido rotado
*/
template <class T>
Node<T>* Node<T>::rot_right(Node<T>* a){
  Node<T> *b, *temp = 0;
  b = 0;
  if (a->left != 0){
    b = a->left;
    if (b->right != 0)
      temp = b->right;
    b->right = a;
    if(temp != 0){
      a->left = temp;
    }else{
      a->left = 0;
    }
  }
  return b;
}
/*
Serie de rotacoines cuando se mueven 3 nodos
@param Nodo que se era rotando
@return Nodo que ha sido rotado
*/
template <class T>
Node<T>* Node<T>::rot_left_right(Node<T>* a){
  a->left = rot_left(a->left);
  a = rot_right(a);
  return a;
}
/*
Serie de rotacoines cuando se mueven 3 nodos
@param Nodo que se era rotando
@return Nodo que ha sido rotado
*/
template <class T>
Node<T>*  Node<T>::rot_right_left(Node<T>* a){
  a->right = rot_right(a->right);
  a = rot_left(a);
  return a;
}
/*
Busca el valor mas pequeno dentro del AVL
@param stringstream Se utiliza para guardar que valor se ha checado
y que se debe de imprimir
@return 
*/
template <class T>
void Node<T>::smallest(std::stringstream &aux){
  if (left != 0) {
    left->smallest(aux);
  }
  if (left == 0){
    cout << "The smallest number is " << data.percent << endl;
    cout << "This belongs to: " << data.name << endl;
  }
}
/*
Busca el valor mas grande dentro del AVL
@param stringstream Se utiliza para guardar que valor se ha checado
y que se debe de imprimir
@return 
*/
template <class T>
void Node<T>::biggest(std::stringstream &aux){
  if (right != 0) {
    right -> biggest(aux);
  }
  if (right == 0){
    cout << "The biggest number is " << data.percent << endl;
    cout << "This belongs to: " << data.name << endl;
  }
}
/*
Guarda los datos dentro de un archivo de texto
@param stringstream de auxiliar para todo lo que se debe de guardar en el documento
ofstream el documento donde se guardaran los datos
@return 
*/
template<class T>
void Node<T>::save_data(std::stringstream &aux, ofstream &saving){
  if (left != 0) {
    left->save_data(aux, saving);
  }
  if (aux.tellp() != 1) {
    saving << data.percent << ", ";
    saving << data.name << endl;
    aux << " " << endl;
  }
  if (right != 0) {
    right->save_data(aux, saving);
  }
}

template <class T>
class AVL {
private:
  Node<T> *root;

public:
  AVL();
  ~AVL();
  bool empty() const;
  void add(float, string);
  bool find(float) const;
  void remove(float);
  void removeAll();
  std::string inorder() const;
  void smallest();
  void biggest();
  void save_data();
};

template <class T>
AVL<T>::AVL() : root(0) {}

template <class T>
AVL<T>::~AVL() {
  removeAll();
}
/*
Confirma si el arbol esta vacio o no
@param 
@return Regresa que el arbol esta vacio
*/
template <class T>
bool AVL<T>::empty() const {
  return (root == 0);
}
/*
Agrega los valores dados por el usuario al arbol
@param float porcentaje dado por el usuario
string nombre dado por el usuario
@return 
*/
template<class T>
void AVL<T>::add(float per, string na) {
  if (root != 0) {
    if (!root->find(per)) {
      Node <T> *temp;
      T check_val = false;
      bool aux = false;
      root->add(per, na);
      root->max_depth();
      temp = root->check_tree(&check_val, 0, &aux);
      if (check_val == root->data.percent){
        root = temp;
      }
      root->max_depth();
    }
  } else {
    root = new Node<T>(per, na);
  }
}
/*
Busca y elimina un dato dado por el usuario
@param float El valor que va a ser eliminado
@return 
*/
template <class T>
void AVL<T>::remove(float per) {
  if (root != 0) {
    if (per == root->data.percent) {
      Node<T> *succ = root->predecesor();
      if (succ != 0) {
        succ->left = root->left;
        succ->right = root->right;
      }
      delete root;
      root = succ;
    } else {
      root->remove(per);
    }
    root->max_depth();
    Node <T> *temp;
    T check_val = false;
    bool aux = false;
    temp = root->check_tree(&check_val, 0, &aux);
    if (check_val == root->data.percent){
      root = temp;
    }
    root->max_depth();
  }
}
/*
Elimina todos los valores dentro del arbol
@param 
@return 
*/
template <class T>
void AVL<T>::removeAll() {
  if (root != 0) {
    root->removeChilds();
  }
  delete root;
  root = 0;
}
/*
Confirma si un valor se encuentra dentro del arbol
@param float valor siendo buscado dentro del arbol
@return bool confirmacion si el valor fue localizado
*/
template <class T>
bool AVL<T>::find(float per) const {
  if (root != 0) {
    return root->find(per);
  } else {
    return false;
  }
}
/*
Funcion que imprime todos los valores dentro del arbol en orden
numerico
@param 
@return string Contiene todo el texto de los valores en el arbol
*/
template <class T>
std::string AVL<T>::inorder() const {
  std::stringstream aux;

  aux << "";
  if (!empty()) {
    root->inorder(aux);
  }
  aux << "" << endl;
  return aux.str();
}
/*
Buaca el valor mas pequeno
@param 
@return 
*/
template<class T>
void AVL<T>::smallest(){
  std::stringstream aux;
  if(!empty()){
    root -> smallest(aux);
  }
}
/*
Busca el valor mas grande
@param 
@return 
*/
template<class T>
void AVL<T>::biggest(){
  std::stringstream aux;
  if(!empty()){
    root -> biggest(aux);
  }
}
/*
Guarda los datos dentro de un archivo de texto
@param 
@return 
*/
template<class T>
void AVL<T>::save_data(){
  std::stringstream aux;
  ofstream savedata;
  savedata.open("savedata.txt");
  if(!empty()){
    root -> save_data(aux, savedata);
  }
  savedata.close();
}

#endif
