#include <bits/stdc++.h>

using namespace std;

char model[100][100][100];
char view[100][100][100];
void simulate(){
  for(int x = 1;x < 99;x++){
    for(int y = 1;y < 99;y++){
      for(int z = 1;z < 99;z++){
        int count = 0;
        for(int i = x-1;i <= x+1;i++){
          for(int j = y-1;j <= y+1;j++){
            for(int k = z-1;k <= z+1;k++){
              if(i == x && j == y && k == z) continue;
              if(view[i][j][k] == '#'){
                count++;
              }
            }
          }
        }
        if(view[x][y][z] == '#' && count != 2 && count != 3){
          model[x][y][z] = '.';
        }
        else if(view[x][y][z] == '.' && count==3){
          model[x][y][z] = '#';
        }
      }
    }
  }
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      for(int k = 0;k < 100;k++){
        view[i][j][k] =  model[i][j][k];
      }
    }
  }
}

int main(){
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      for(int k = 0;k < 100;k++){
        model[i][j][k] = '.';
        view[i][j][k] = '.';
      }
    }
  }
  string line;
  int j = 50;
  while(cin >> line){
    for(int i = 0;i < line.length();i++){
      model[i+50][j][50] = line[i];
      view[i+50][j][50] = line[i];
    }
    j++;
  }
  for(int i = 0;i < 6;i++){
    simulate();
  }
  int count = 0;
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      for(int k = 0;k < 100;k++){
        if(view[i][j][k] == '#'){
          count++;
        }
      }
    }
  }
  cout << count << endl;
}
