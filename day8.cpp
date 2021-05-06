#include <bits/stdc++.h>

using namespace std;

void check(vector<pair<string,string>> v){
  string action,amount;
  int number;
  char sign;
  bool arr[800] = {false};
  int index = 0;
  int acc = 0;
  while(!arr[index] && index != v.size()){
    arr[index] = true;
    action = v[index].first;
    amount = v[index].second;
    sign = amount[0];
    number = stoi(amount.substr(1));
    if(action == "nop"){
      index++;
    }
    if(action == "acc"){
      if(sign == '+'){
        acc += number;
      }
      else if(sign == '-'){
        acc -= number;
      }
      index++;
    }
    if(action == "jmp"){
      if(sign == '+'){
        index += number;
      }
      else if(sign == '-'){
        index -= number;
      }
    }
  }
  if(index == v.size()){
      cout << acc << endl; 
      return;
    }
    else{
      return;
    }
}

int main(){
  string action,amount;
  int number;
  char sign;
  bool arr[800] = {false};
  vector<pair<string,string>> v;
  while(cin >> action >> amount){
    v.push_back(make_pair(action,amount));
  }
  for(int i = 0;i < v.size();i++){
    if(v[i].first == "nop"){
      vector<pair<string,string>> myCheck = v;
      myCheck[i].first = "jmp";
      check(myCheck);
    }
    else if(v[i].first == "jmp"){
      vector<pair<string,string>> myCheck = v;
      myCheck[i].first = "nop";
      check(myCheck);
    }
  }
}
