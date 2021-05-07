#include <bits/stdc++.h>

using namespace std;

vector<string> view;
vector<string> model;

void nextPhase(){
  for(int i = 0;i < view.size();i++){
    for(int j = 0;j < view[0].length()-1;j++){
      int seatCount = 0;
      if(view[i][j] == 'L'){
        for(int k = 1;i-k >= 0 && j-k >=0 && seatCount == 0;k++){
          if(view[i-k][j-k] == '#') seatCount++;
          if(view[i-k][j-k] == 'L') break;
        }
        for(int k = 1;i-k >= 0 && seatCount == 0;k++){
          if(view[i-k][j] == '#') seatCount++;
          if(view[i-k][j] == 'L') break;
        }
        for(int k = 1;i-k >= 0 && j+k < view[i].length() && seatCount == 0;k++){
          if(view[i-k][j+k] == '#') seatCount++;
          if(view[i-k][j+k] == 'L') break;
        }
        for(int k = 1;j-k >=0 && seatCount == 0;k++){
          if(view[i][j-k] == '#'){
            seatCount++;
          }
          if(view[i][j-k] == 'L'){
            break;
          }
        }
        for(int k = 1;j+k < view[i].length() && seatCount == 0;k++){
          if(view[i][j+k] == '#') seatCount++;
          if(view[i][j+k] == 'L') break;
        }
        for(int k = 1;i+k < view.size() && j-k >=0 && seatCount == 0;k++){
          if(view[i+k][j-k] == '#') seatCount++;
          if(view[i+k][j-k] == 'L') break;
        }
        for(int k = 1;i+k < view.size() && seatCount == 0;k++){
          if(view[i+k][j] == '#') seatCount++;
          if(view[i+k][j] == 'L') break;
        }
        for(int k = 1;i+k < view.size() && j+k < view[i].length() && seatCount == 0;k++){
          if(view[i+k][j+k] == '#') seatCount++;
          if(view[i+k][j+k] == 'L') break;
        }
        if(seatCount == 0) model[i][j] = '#';
      }
      if(view[i][j] == '#'){
        for(int k = 1;i-k >= 0 && j-k >=0;k++){
          if(view[i-k][j-k] == '#'){
            seatCount++;
            break;
          }
          if(view[i-k][j-k] == 'L'){
            break;
          }
        }
        for(int k = 1;i-k >= 0;k++){
          if(view[i-k][j] == '#'){
            seatCount++;
            break;
          }
          if(view[i-k][j] == 'L'){
            break;
          }
        }
        for(int k = 1;i-k >= 0 && j+k < view[i].length();k++){
          if(view[i-k][j+k] == '#'){
            seatCount++;
            break;
          }
          if(view[i-k][j+k] == 'L'){
            break;
          }
        }
        for(int k = 1;j-k >=0;k++){
          if(view[i][j-k] == '#'){
            seatCount++;
            break;
          }
          if(view[i][j-k] == 'L'){
            break;
          }
        }
        for(int k = 1;j+k < view[i].length();k++){
          if(view[i][j+k] == '#'){
            seatCount++;
            break;
          }
          if(view[i][j+k] == 'L'){
            break;
          }
        }
        for(int k = 1;i+k < view.size() && j-k >=0;k++){
          if(view[i+k][j-k] == '#'){
            seatCount++;
            break;
          }
          if(view[i+k][j-k] == 'L'){
            break;
          }
        }
        for(int k = 1;i+k < view.size();k++){
          if(view[i+k][j] == '#'){
            seatCount++;
            break;
          }
          if(view[i+k][j] == 'L'){
            break;
          }
        }
        for(int k = 1;i+k < view.size() && j+k < view[i].length();k++){
          if(view[i+k][j+k] == '#'){
            seatCount++;
            break;
          }
          if(view[i+k][j+k] == 'L'){
            break;
          }
        }
        if(seatCount >= 5) model[i][j] = 'L';
      }
    }
  }
  view = model;
}

int main(){
  int answer = 0;
  string line;
  string floor = "";
  for(int i = 0;i < 97;i++){
    floor+= ".";
  }
  view.push_back(floor);
  model.push_back(floor);
  while(cin >> line){
    line = "." + line + ".";
    view.push_back(line);
    model.push_back(line);
  }
  view.push_back(floor);
  model.push_back(floor);
  for(int k = 0;k < 100;k++){
    nextPhase();
  }
  for(int i = 0;i < view.size();i++){
    for(int j=0;j < view[0].length();j++){
      if(model[i][j] == '#'){
        answer++;
      }
    }
  }
  cout << answer << endl;
}
