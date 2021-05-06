#include <bits/stdc++.h>

using namespace std;
vector<int> v;
vector<long long> v2;
long long path(int index){
  if(v2[index] > 0){
    return v2[index];
  }
  if(index >= v.size()-3){
    return 1;
  }
  if(v[index+3] - v[index] == 3){
    v2[index] = path(index+1) + (path(index+2) + path(index+3));
    return v2[index];
  }
  else if(v[index+2] - v[index] <= 3){
    v2[index] = path(index+1)*2;
    return v2[index];
  }
  else{
    v2[index] = path(index+1);
    return v2[index];
  }
}

int main(){
  v2.resize(200);
  int adapter;
  v.push_back(0);
  long long total = 1;
  int bigDiff = 0, smallDiff = 0;
  while(cin >> adapter){
    v.push_back(adapter);
  }
  sort(v.begin(),v.end());
  v.push_back(v[v.size()-1] + 3);
  v2[v.size()-1] = 1;
  v2[v.size()-2] = 1;
  v2[v.size()-3] = 1;
  cout << path(0) << endl;
}
