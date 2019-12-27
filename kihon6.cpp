#include <iostream>
using namespace std;

class person{
public:
  string address;
  void setName(string n){name = n;};
  string getName(){return name;};
protected:
  string name; 
};

class addressbook{
  person friends[100];
  int numberOfFriends;
public:
  addressbook();
  void listFriends();
  void addFriend(string n);
};

// constructor
addressbook::addressbook(){
  numberOfFriends = 0;  
}

void addressbook::addFriend(string n){
  friends[numberOfFriends].setName(n);
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].getName() << "\n";
  }      
}

int main()
{
  addressbook abook;
  string name;

  while(1){
    cout << "住所録に登録する名前を入力してください（終了するにはquitと入力してください）: ";
    cin >> name;
    if(name == "quit"){break;}
    abook.addFriend(name);
  }

  cout << "\n名前リスト:\n";
  abook.listFriends();  
}
