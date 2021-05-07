#include <bits/stdc++.h>

using namespace std;

int main(){
  string command;
  char direction;
  int distance;
  int x=0,y=0;
  char facing = 'E';
  while(cin >> command){
    direction = command[0];
    distance = stoi(command.substr(1));
    if(direction =='N') y += distance;
    else if(direction == 'S') y -= distance;
    else if(direction == 'E') x += distance;
    else if(direction =='W') x -= distance;

    if(direction == 'L' && distance == 90){
      if(facing == 'N') facing = 'W';
      else if(facing == 'S') facing = 'E';
      else if(facing == 'E') facing = 'N';
      else if(facing == 'W') facing = 'S';
    }
    else if(direction == 'L' && distance == 180){
      if(facing == 'N') facing = 'S';
      else if(facing == 'S') facing = 'N';
      else if(facing == 'E') facing = 'W';
      else if(facing == 'W') facing = 'E';
    }
    else if(direction == 'L' && distance == 270){
      if(facing == 'N') facing = 'E';
      else if(facing == 'S') facing = 'W';
      else if(facing == 'E') facing = 'S';
      else if(facing == 'W') facing = 'N';
    }
    else if(direction == 'R' && distance == 90){
      if(facing == 'N') facing = 'E';
      else if(facing == 'S') facing = 'W';
      else if(facing == 'E') facing = 'S';
      else if(facing == 'W') facing = 'N';
    }
    else if(direction == 'R' && distance == 180){
      if(facing == 'N') facing = 'S';
      else if(facing == 'S') facing = 'N';
      else if(facing == 'E') facing = 'W';
      else if(facing == 'W') facing = 'E';
    }
    else if(direction == 'R' && distance == 270){
      if(facing == 'N') facing = 'W';
      else if(facing == 'S') facing = 'E';
      else if(facing == 'E') facing = 'N';
      else if(facing == 'W') facing = 'S';
    }
    else if(direction == 'F'){
      if(facing == 'N') y += distance;
      else if(facing == 'S') y -= distance;
      else if(facing == 'E') x += distance;
      else if(facing == 'W') x -= distance;
    }
  }
  cout << abs(x) + abs(y) << endl;
}
