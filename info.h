#ifndef INFO_H_
#define INFO_H_
#include <vector>
#include <list>

using namespace std;

template <class T,class N>
class Info{
  private:
    vector<T> damage{};
    vector<N> names{};

    void swap(vector<T> &v, int i, int j){
      T aux = v[i];
      v[i] = v[j];
      v[j] = aux;
  }
    void swap(vector<N> &v, int i, int j){
    N aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    }
    void copyArray(vector<T> &A, vector<N> &B, int low, int high){
      for (int i = low; i <= high; i++) {
        A[i] = B[i];
      }
  
  }
  public:
    Info(vector<T> da, vector<N>na){
     damage = da;
     names = na;
    }
    void ordenaBurbuja() {
      int d = damage.size();
      for (int i = d - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
          if (damage[j] > damage[j + 1]) {
            swap(damage, j, j + 1);
            swap(names, j, j+1);
          }
        }
      }
    }
    void printInfo(){
      int d = damage.size();
      for(int i = 0; i <= d-1; i++){
        cout << "Weapon " << i + 1 << endl;
        cout << "Damage " << i + 1 << ": "<< damage[i] << endl;
        cout << "Weapon Name " << i + 1 << ": "<< names[i] << endl << endl;
      }
    }

    void addInfo(){
      string na;
      cout << "What is the name of the weapon" << endl;
      cin >>  na;
      int da;
      cout << "What is the damage of the weapon" << endl;
      cin >> da;
      damage.insert(damage.begin(), da);
      names.insert(names.begin(), na);
    }

    void fullArsenal(){
      int d = damage.size();
      int total = 0;
      for(int i = 0; i <= d-1; i++){
        total += damage[i];
      }
      cout << "The full damage of all weapons is: " << total << endl;
    }
};


#endif