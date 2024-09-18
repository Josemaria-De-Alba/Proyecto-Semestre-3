#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "info.h"

using namespace std;
int main(){
  
  vector<int> damageT{2,3,1};
  vector<string> weaponT{"Ace of Spades", "Ghallarhorn","Choir of One"};

  
  Info <int,string>info(damageT,weaponT);
  info.printInfo();

  info.addInfo();
  
  info.ordenaBurbuja();

  info.printInfo();

  info.fullArsenal();
}