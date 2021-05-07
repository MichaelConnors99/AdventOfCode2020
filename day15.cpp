//Note: Requires input to be numbers seperated by spaces not ","

#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> mem;
  vector<int> prev;
  vector<int> last;
  last.resize(99999999);
  prev.resize(99999999);
  for(int i = 0;i < 99999999;i++){
    last[i] = -1;
    prev[i] = -1;
  }
  int num;
  int count = 0;
  while(cin >> num){
    mem.push_back(num);
    last[num] = count;
    count++;
  }
  for(int i = mem.size();i < 30000000;i++){
    int current = mem[i-1];
    if(prev[current] == -1){
      mem.push_back(0);
      prev[0] = last[0];
      last[0] = i;
    }
    else{
      int val = i-1 - prev[current];
      mem.push_back(val);
      if(last[val] == -1){
        last[val] = i;
      }
      else{
        prev[val] = last[val];
        last[val] = i;
      }
    }
  }
  cout << mem[29999999] << endl;
}
