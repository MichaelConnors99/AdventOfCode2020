#include <bits/stdc++.h>

using namespace std;

int main(){
  string command;
  char direction;
  int distance;
  int x=0,y=0,wx=10,wy=1;
  char facing = 'E';
  while(cin >> command){
    direction = command[0];
    distance = stoi(command.substr(1));
    if(direction =='N') wy += distance;
    else if(direction == 'S') wy -= distance;
    else if(direction == 'E') wx += distance;
    else if(direction =='W') wx -= distance;

    if(direction == 'L' && distance == 90){
      int temp = wx;
      wx = wy*-1;
      wy = temp;
    }
    else if(direction == 'L' && distance == 180){
      wx = -1*wx;
      wy = -1*wy;
    }
    else if(direction == 'L' && distance == 270){
      int temp = wx;
      wx = wy;
      wy = temp*-1;
    }
    else if(direction == 'R' && distance == 90){
      int temp = wx;
      wx = wy;
      wy = -1*temp;
    }
    else if(direction == 'R' && distance == 180){
      wx = -1*wx;
      wy = -1*wy;
    }
    else if(direction == 'R' && distance == 270){
      int temp = wx;
      wx = wy*-1;
      wy = temp;
    }
    else if(direction == 'F'){
      x += distance*wx;
      y += distance*wy;
    }
  }
  cout << abs(x) + abs(y) << endl;
}
