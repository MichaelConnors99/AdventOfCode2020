#include <bits/stdc++.h>

using namespace std;

int main(){
  string rules[600];
  map<string,bool> m;
  m["shiny gold"] = true;
  string line;
  int count = 0;
  int answer = 0;
  while(getline(cin,line) && line.length() > 0){
    rules[count] = line;
    string bag = line.substr(0,line.find("bags")-1);
    count++;
  }
  for(int j = 0;j < 100;j++){
    for(int i = 0;i < count;i++){
      string bag;
      string contains;
      string line = rules[i];
      if(line.find("no other") != string::npos){
          continue;
      }
      int seperate = line.find("contain");
      bag = line.substr(0,seperate-6);
      vector<string> list;
      contains = line.substr(seperate+8);
      while(contains.find(",") != string::npos){
        string str = contains.substr(2,contains.find(",")-6);
        if(str[str.length()-1] == ' '){
          str = str.substr(0,str.length()-1);
        }
        list.push_back(str);
        contains = contains.substr(contains.find(",")+2);
      }
      if(contains.find("bags") != string::npos){
        contains = contains.substr(0,contains.length()-1);
      }
      contains = contains.substr(2,contains.length()-7);
      list.push_back(contains);
      for(int k = 0;k < list.size();k++){
        if(m[list[k]] && !m[bag] && bag != "shiny gold"){
          answer++;
          m[bag] = true;
        }
      }
    }
  }
  cout << answer << endl;
}
