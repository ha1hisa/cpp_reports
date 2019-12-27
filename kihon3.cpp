/* sample 3 */
#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name; 
};

class addressbook{
  person friends[100];
  int numberOfFriends;
public:
  addressbook();
  void listFriends();
  void addFriend(string n, string a);
  person find(string query);
};

// constructor
addressbook::addressbook(){
  numberOfFriends = 0;  
}

void addressbook::addFriend(string n, string a){  
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << " : " << friends[i].address << "\n";
  }      
}

person addressbook::find(string query){
  person no_one;
  no_one.name = "";
  for(int i = 0; i < numberOfFriends; i++){
    if(friends[i].name == query){
      return friends[i];
    }      
  }
  return no_one;
}

int main()
{
  addressbook abook;
  string name;
  string address;

  while(1){
    cout << "住所録に登録する名前を入力してください（終了するにはquitと入力してください）: ";
    cin >> name;
    if(name == "quit"){break;}
    cout << "その名前を持つ人のアドレスを入力してください: ";
    cin >> address;
    //   cout << "name.length() = " << name.length() << "\n";
    abook.addFriend(name, address);
  }
  string query;
  cout << "\n検索する名前を入力してください: ";
  cin >> query;
  person found;
  found = abook.find(query);
  if(found.name == ""){
    cout << "見つかりませんでした.";
  }else{
    cout << found.name << ":" << found.address;
  }
  
}
