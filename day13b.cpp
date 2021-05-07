//Note requires an ",x" to be appended to the end of the input

#include <bits/stdc++.h>

using namespace std;

int main(){
  int target;
  string line;
  cin >> target;
  cin >> line;
  vector<int> buses;
  while(line.find(",") != string::npos){
    string sub = line.substr(0,line.find(","));
    line = line.substr(line.find(",")+1);
    //cout << sub << endl << line << endl;
    if(sub == "x"){
      buses.push_back(-1);
    }
    else{
      buses.push_back(stoi(sub));
    }
  }
  bool found = false;
  int mult = 1;
  int current = 1;
  long long plus = 1;
  long long big = 0,small = 0;

  for(int i = 0;i < buses.size();i++){
    if(buses[i] == -1) continue;
    int count = 0;
    for(long long j = big;count < 3;j+=plus){
      if((j+i)%buses[i] == 0){
        if(i == buses.size()-1){
          cout << j << endl;
          break;
        }
        else{
          count++;
          if(count == 1) small = j;
          if(count == 2){
            big = j;
            plus = big - small;
            break;
          }
        }
      }
    }
  }
}
