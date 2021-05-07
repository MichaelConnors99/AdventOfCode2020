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
    if(sub == "x") continue;
    else{
      buses.push_back(stoi(sub));
    }
  }
  int best = 100000;
  int bestBus = 0;
  for(int i = 0;i < buses.size();i++){
    int bus = buses[i];
    int sum = 0;
    while(sum < target){
      sum += bus;
    }
    int wait = sum - target;
    if(wait < best){
      best = wait;
      bestBus = buses[i];
    }
  }
  cout << (best)*bestBus<< endl;
}
