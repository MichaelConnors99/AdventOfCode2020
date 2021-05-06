#include <bits/stdc++.h>

using namespace std;

int main(){
  int adapter;
  vector<int> v;
  v.push_back(0);
  int bigDiff = 0, smallDiff = 0;
  while(cin >> adapter){
    v.push_back(adapter);
  }
  sort(v.begin(),v.end());
  v.push_back(v[v.size()-1] + 3);
  for(int i = 1;i < v.size();i++){
    if(v[i] - v[i-1] == 1){
      smallDiff++;
    }
    else if(v[i] - v[i-1] == 3){
      bigDiff++;
    }
  }
  cout << smallDiff * bigDiff << endl;
}
