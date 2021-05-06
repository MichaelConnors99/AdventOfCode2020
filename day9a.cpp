#include <bits/stdc++.h>

using namespace std;

int arr[1000];
vector<long> v;

bool check(int index){
  for(int i = index-25;i < index;i++){
    for(int j = index-25;j < index;j++){
      if(i != j && v[i] + v[j] == v[index]){
        return true;
      }
    }
  }
  return false;
}
int main(){
  long number;
  int count = 0;
  while(cin >> number){
    v.push_back(number);
    count++;
  }
  for(int i = 25;i < v.size();i++){
    if(!check(i)){
      cout << v[i] << endl;
    }
  }
}
