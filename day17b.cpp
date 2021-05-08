#include <bits/stdc++.h>

using namespace std;

char model[100][100][100][100];
char view[100][100][100][100];
void simulate(){
  for(int x = 20;x < 80;x++){
    for(int y = 20;y < 80;y++){
      for(int z = 20;z < 80;z++){
        for(int w = 20;w < 80;w++){
          int count = 0;
          for(int i = x-1;i <= x+1;i++){
            for(int j = y-1;j <= y+1;j++){
              for(int k = z-1;k <= z+1;k++){
                for(int s = w-1;s <=w+1;s++){
                  if(i == x && j == y && k == z && s==w) continue;
                  if(view[i][j][k][s] == '#'){
                    count++;
                  }
                } 
              }
            }
          }
          if(view[x][y][z][w] == '#' && count != 2 && count != 3){
            model[x][y][z][w] = '.';
          }
          else if(view[x][y][z][w] == '.' && count==3){
            model[x][y][z][w] = '#';
          }
        }
        
      }
    }
  }
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      for(int k = 0;k < 100;k++){
        for(int s = 0;s < 100;s++){
          view[i][j][k][s] =  model[i][j][k][s];
        }
      }
    }
  }
}

int main(){
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      for(int k = 0;k < 100;k++){
        for(int l = 0;l < 100;l++){
          model[i][j][k][l] = '.';
        view[i][j][k][l] = '.';
        }
      }
    }
  }
  string line;
  int j = 50;
  while(cin >> line){
    for(int i = 0;i < line.length();i++){
      model[i+50][j][50][50] = line[i];
      view[i+50][j][50][50] = line[i];
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
        for(int l = 0;l < 100;l++){
          if(view[i][j][k][l] == '#'){
            count++;
          }
        }
      }
    }
  }
  cout << count << endl;
}
