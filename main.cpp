#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>
#include "info.h"

void confirm(bool f){
  if (f == 1){
    cout << "The value is there" << endl;
  }
  else{
    cout<< "The value is not there"<< endl;
  }
}

void description(){
  cout << "If you have ever played an competitive online game you know how ";
  cout << "important balance is." << endl;
  cout << "This program has been designed in order to help find unbalanced ";
  cout << "areas." << endl << "This program works by recieving a " << endl;
  cout << "number(as a percent) and a name and automatically ordering " << endl;
  cout << "them from smallest to largest." << endl;
  cout << "The number can be a win rate or use rate for characters or weapons ";
  cout << "and the name used to find what it is connected to." << endl;
  cout << "This could be used for games such as Overwatch 2, Apex Legends, ";
  cout << "Destiny 2, Call of Duty, etc" << endl << endl;
  cout << "You will be given 2 ways to store and organize data: ";
  cout << "a vector and a AVL tree." << endl;
  cout << "I recomend using a vector to organize data alphabetically ";
  cout << "and using the tree to sort by percent and be able to get a short";
  cout << " recomendation of what needs a buff or  a nerf" << endl;
  cout << "VERY IMPORTANT! YOU CAN ONLY SAVE DATA TO GO WITH AVL TREES" << endl;
}

AVL<float> example(){
  AVL<float> leg;
  fstream legends("legends.txt");
  string line;
  float percent;
  string name;
  if(legends.is_open()){
    while(getline(legends,line)){
      percent = stof(line.substr(0, 4));
      name = line.substr(5, 4);
      leg.add(percent, name);
    }
    cout << leg.inorder();
    legends.close();
  }
  return leg;
}

int main(){
  AVL<float> data;
  AVL<float> legends;
  int done = 0;


  Sort<character_info> sort(40, "Carry");
  sort.remove(40);
  
  
  int run = 0;
  cout << "Welcome to the character use/win rate maker!" << endl;
  cout << "What would you like to do today?" << endl;
  while(run != 5){
    cout << "Type 1 for a quick explination of what you can do" << endl;
    cout << "Type 2 to organize data in an AVL Tree" << endl;
    cout << "Type 3 to organize data in a vector" << endl;
    cout << "Type 4 to print information" << endl;
    cout << "Type 5 to end the program" << endl;
    cin >> run;
    if(run == 1){
      description();
    }
    if (run == 2){
      cout << "Here are the comands to start organizing data:" << endl;
      int building = 0;
      while(building != 7){
        cout << "Type 1 to add a values" << endl;
        cout << "Type 2 to remove a value" << endl;
        cout << "Type 3 to remove all values" << endl;
        cout << "Type 4 to load Apex Legends example" << endl;
        cout << "Type 5 to save values in a text file to go" << endl;
        cout << "Type 6 to print information" << endl;
        cout << "Type 7 to return to the main menu" << endl;
        cin >> building;
        if (building == 1){
          string na;
          float per;
          cout << "Please give us the character/item name: " << endl;
          cin >> na;
          cout << "Please give us the win/use rate: " << endl;
          cin >> per;
          data.add(per,na);
        }
        else if (building == 2){
          float re;
          bool available;
          cout << "Please give us the win/use rate: " << endl;
          cin >> re;
          available = data.find(re);
          if (available == 1){
            data.remove(re);
          }
          else{
            cout << "That data was not found, please try again" << endl;
          }
        }
        else if (building == 3){
          data.removeAll();
          cout << "Done all data removed! I hope that wasn't a typo Ɛ>" << endl;
        }
        else if (building == 4){
          if (done == 0){
            legends = example();
            cout << "Under Construction" << endl;
            cout << "Reading File" << endl;
            done = 1;
            cout << legends.inorder();
          }
          else{
            cout << "Use inorder to read file" << endl;
            cout << legends.inorder();
          }
          
        }
        else if (building == 5){
          data.save_data();
          cout << "Done! Please Check the savedata.txt file" << endl;
        }
        else if (building == 6){
          cout << data.inorder() << endl;
        }
        else if(0 >= building or 7 <= building){
          cout << "Wrong Number. Try Again." << endl;
        }
      }
    }
    if(run == 4){
      cout << "Here is all the data!" << endl;
      cout << data.inorder() << endl;
    
      cout << "We recomend taking a look at the following aspects" << endl;
      cout << "This character/weapon might need a buff: " << endl;
      data.smallest();
      cout << "This character/weapon might need a nerf: " << endl;
      data.biggest();
    }
    if(run == 3){
      cout << "Here are the instructions to start organizing data" << endl;
      int vectorbuild = 0;
      while(vectorbuild != 5){
        cout << "Type 1 to add a values" << endl;
        cout << "Type 2 to remove a value" << endl;
        cout << "Type 3 to print information" << endl;
        cout << "Type 4 to find where a percent is located" << endl;
        cout << "Type 5 to return to the main menu" << endl;
        cin >> vectorbuild;
        if(vectorbuild == 1){
          string na;
          float per;
          cout << "Please give us the character/item name: " << endl;
          cin >> na;
          cout << "Please give us the win/use rate: " << endl;
          cin >> per;
          sort.add(per,na);
          
        }
        else if(vectorbuild == 2){
          float re;
          cout << "Please give us the win/use rate: " << endl;
          cin >> re;
          sort.remove(re);
          
        }
        else if(vectorbuild == 3){
          sort.MergeSort();
          sort.printArray();
        }
        else if(vectorbuild == 4){
          float fi;
          cout << "What percent do you want to find?" << endl;
          cin >> fi;
          sort.MergeSort();
          sort.find(fi);
        }
        else if(vectorbuild <= 0 or vectorbuild >= 6){
          cout << "Wrong number, try again." << endl;
        }
      }
    }
    if(run <= 0 or run >= 6){
      cout << "Wrong Number. Try Again." << endl;
    }
  }
  cout << "Thank you for using my program!" << endl;
}
