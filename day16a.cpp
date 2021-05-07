// Note: requires the "your ticket:" and "nearby tickets" to be
#include <bits/stdc++.h>

using namespace std;

int main(){
  string line;
  bool arr[1000];
  int min,max;
  int index;
  char comma;
  int sum = 0;
  while(getline(cin,line) && line.find("-") != string::npos){
    index = line.find("-");
    min = stoi(line.substr(line.find(": ")+1,index));
    max = stoi(line.substr(index+1,line.find(" o")));
    for(int i = min;i <= max;i++){
      arr[i] = true;
    }
    line = line.substr(line.find(" or "));
    min = stoi(line.substr(4,line.find("-")));
    max = stoi(line.substr(line.find("-")+1));
    for(int i = min;i <= max;i++){
      arr[i] = true;
    }
  }
  for(int i = 0;i < 239;i++){
    for(int j = 0;j < 20;j++){
      if(j == 19){
        cin >> index;
      }
      else{
        cin >> index >> comma;
      }
      if(!arr[index]){
        sum += index;
      }
    }
  }
  cout << sum << endl;
}
