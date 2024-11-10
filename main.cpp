#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
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
}

int main(){
  AVL<int> data;

  //TESTING
  AVL<int> test;
  test.add(10,"Wraith");
  std::cout << test.inorder() << std::endl << std::endl;
  
  test.add(5, "Seer");
  test.add(40,"Catalyst");
  test.add(2,"Fuse");
  test.add(7, "Crypto");
  std::cout << test.inorder() << std::endl << std::endl;

  test.remove(10);
  std::cout << test.inorder() << std::endl << std::endl;

  bool found = test.find(7);
  confirm(found);

  int run = 0;
  cout << "Welcome to the character use/win rate maker!" << endl;
  cout << "What would you like to do today?" << endl;
  while(run != 4){
    cout << "Type 1 for a quick explination of what you can do" << endl;
    cout << "Type 2 to start organizing data" << endl;
    cout << "Type 3 to print information" << endl;
    cout << "Type 4 to end the program" << endl;
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
          int per;
          cout << "Please give us the character/item name: " << endl;
          cin >> na;
          cout << "Please give us the win/use rate: " << endl;
          cin >> per;
          data.add(per,na);
        }
        else if (building == 2){
          int re;
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
          cout << "Under Construction" << endl;
        }
        else if (building == 5){
          cout << "Under Construction" << endl;
        }
        else if (building == 6){
          cout << data.inorder() << endl;
        }
        else if(0 > building or 7 < building){
          cout << "Wrong Number. Try Again." << endl;
        }
      }
    }
    if(run == 3){
      cout << "Here is all the data!" << endl;
      cout << data.inorder() << endl;
    
      cout << "We recomend taking a look at the following aspects" << endl;
      cout << "This character/weapon might need a buff: " << endl;
      data.smallest();
      cout << "This character/weapon might need a nerf: " << endl;
      data.biggest();
    }
  }
  cout << "Thank you for using my program!" << endl;

  //TESTING
  test.smallest();
  test.biggest();
}
