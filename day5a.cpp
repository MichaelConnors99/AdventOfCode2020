#include <bits/stdc++.h>

using namespace std;

int main(){
  string pass;
  int highest = 0;
  int id = 0;
  int mid = 0;
  int row = 0;
  int col = 0;
  bool seats[128][8] = {false};
  while(cin >> pass){
    int vmax = 128;
    int vmin = 1;
    int hmax = 8;
    int hmin = 1;
    for(int i = 0;i < 6;i++){
      mid = 1 + floor((vmax-vmin)/2);
      if(pass[i] == 'F'){
        vmax -= mid;
      }
      else if(pass[i] == 'B'){
        vmin += mid;
      }
    }
    if(pass[6] == 'F'){
      row = vmin-1;
    }
    else{
      row = vmax-1;
    }
    for(int i = 7;i < pass.length()-1;i++){
      mid = 1 + floor((hmax-hmin)/2);
      if(pass[i] == 'L'){
        hmax -= mid;
      }
      else{
        hmin += mid;
      }
    }
    if(pass[9] == 'L'){
      col = hmin-1;
    }
    else{
      col = hmax-1;
    }
    seats[row][col] = true;
    id = row*8 + col;
    if(id > highest){
      highest = id;
    }
  }
  cout << highest << endl;
}
