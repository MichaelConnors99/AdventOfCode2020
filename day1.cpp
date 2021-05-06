#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  vector<int> v;
  while(cin >> n){
    v.push_back(n);
  }
  for(int i = 0;i < v.size();i++){
    for(int j = 0;j < v.size();j++){
      for(int k = 0;k < v.size();k++){
        if(i!=j && j!=k){
          if(v[i] + v[j] + v[k] == 2020){
            cout << v[i] * v[j] * v[k] << endl;
          }
        }
      }
    }
  }
}
