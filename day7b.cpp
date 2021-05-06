#include <bits/stdc++.h>

using namespace std;
string rules[594];
int containCount(string bag){
  int count = 0;
  int amount;
  string contains;
  for(int i = 0;i < 594;i++){
    string line = rules[i];
    int seperate = line.find("contain");
    if(bag == rules[i].substr(0,seperate-6)){
      if(line.find("no other") != string::npos){
        return 0;
      }
      contains = line.substr(seperate+8);
      vector<string> list;
      vector<int> amount;
      while(contains.find(",") != string::npos){
        string str = contains.substr(2,contains.find(",")-6);
        if(str[str.length()-1] == ' '){
          str = str.substr(0,str.length()-1);
        }
        list.push_back(str);
        amount.push_back((int)contains[0]-'0');
        contains = contains.substr(contains.find(",")+2);
      }
      if(contains.find("bags") != string::npos){
        contains = contains.substr(0,contains.length()-1);
      }
      amount.push_back((int)contains[0]-'0');
      contains = contains.substr(2,contains.length()-7);
      list.push_back(contains);
      for(int j = 0;j < list.size();j++){
        count += amount[j] + amount[j] *  containCount(list[j]);
      }
    }
  }
  return count;
}

int main(){
  string line;
  int count = 0;
  while(getline(cin,line) && line.length() > 0){
    rules[count] = line;
    string bag = line.substr(0,line.find("bags")-1);
    count++;
  }
  cout << containCount("shiny gold") << endl;
}
