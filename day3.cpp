#include <bits/stdc++.h>

using namespace std;

int main(){
  string slope[323];
  string line;
  int ans = 1;
  int lineCount = 0;
  int right = 0;
  int treeCount = 0;
  while(cin >> line){
    slope[lineCount] = line;
    lineCount++;
  }
  for(int i = 1;i < 323;i++){
    right += 1;
    if(right > 30){
      right = right - 31;
    }
    cout << right << endl;
    if(slope[i][right] == '#'){
      treeCount++;
    }
  }
  right = 0;
  cout << treeCount << endl;
}
