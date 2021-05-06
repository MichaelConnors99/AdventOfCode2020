#include <bits/stdc++.h>

using namespace std;

int arr[1000];
vector<long> v;

bool check(int i1, int i2){
  long sum = 0;
  for(int i = i1;i <= i2;i++){
    sum += v[i];
  }
  if(sum == 3199139634){
    return true;
  }
  return false;
}
int main(){
  long goal = 3199139634;
  long maxIndex = 683;
  long number;
  int count = 0;
  while(cin >> number){
    v.push_back(number);
    count++;
  }
  for(int range = 2;range < 100;range++){
    for(int i = 0;i < maxIndex-range;i++){
      long sum = 0;
      for(int j = i;j < i+range;j++){
        sum += v[j];
      }
      if(sum == goal && check(i,i+range-1)){
        long smallest = 1000000000000000;
        long biggest = 0;
        for(int k = i;k < i+range;k++){
          if(v[k] < smallest){
            smallest = v[k];
          }
          if(v[k] > biggest){
            biggest = v[k];
          }
        }
        cout << biggest + smallest << endl;
      }
    }
  }
}
