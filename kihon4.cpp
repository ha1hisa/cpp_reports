#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name; 
};

class addressbook{
public:
  person* friends;
  addressbook(){friends = new person;}
  ~addressbook(){delete[] friends;}
};

int main()
{
  int i = 0;
  string mark;
  addressbook* abooks = new addressbook [100];
  while(1){
    cout << "続ける場合はｙを入力してください.(終了するにはquitと入力してください.)\n";
    cin >> mark;
    if(mark == "quit"){break;}
    cout << "住所録に登録する名前を入力してください: ";
    cin >> abooks[i].friends->name;
    cout << "その名前を持つ人のアドレスを入力してください: ";
    cin >> abooks[i].friends->address;
    //   cout << "name.length() = " << name.length() << "\n";
    i++;
  }
  cout << "\n名前：住所\n";
  for(int j = 0; j < i; j++){
      cout << abooks[j].friends->name << ":" << abooks[j].friends->address << "\n";
  }
  
}
