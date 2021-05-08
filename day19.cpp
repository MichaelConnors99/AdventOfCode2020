#include <bits/stdc++.h>

using namespace std;

long long eval(string expression){
  while(expression.find("+") != string::npos){
    int index = expression.find("+");
    int left,right;
    int leftIndex,rightIndex;
    for(int i = index+2;expression[i] - '0' >= 0 && expression[i] - '0' < 10;i++){
      right = stoi(expression.substr(index+2,i));
      rightIndex = i;
    }
    for(int i = index-2;expression[i] - '0' >= 0 && expression[i] - '0' < 10;i--){
      left = stoi(expression.substr(i,index-2));
      leftIndex = i;
    }
    int result = left + right;
    expression = expression.substr(0,leftIndex) + to_string(result) + expression.substr(rightIndex+1);
  }
  long long sum = expression[0] - '0';
  for(int i = 1;expression[i] - '0' >= 0 && expression[i] - '0' < 10;i++){
    sum = stoi(expression.substr(0,i));
  }
  for(int i = 1;i < expression.length();i++){
    int num = 5;
    if(expression[i] - '0' >= 0 && expression[i] - '0' < 10){
      for(int j = i;expression[j] - '0' >= 0 && expression[j] - '0' < 10;j++){
        num = stoi(expression.substr(i,j-1));
      }
      if(expression[i-2] == '+') sum += num;
      else if(expression[i-2] == '*') sum *= num;
      while(expression[i+1] - '0' >= 0 && expression[i+1] - '0' < 10 && i != expression.length()){
        i++;
      }
    }
  }
  return sum;
}

int main(){
  long long sum = 0;
  string line;
  while(getline(cin,line)){
    while(line.find(")") != string::npos){
      int index = line.find(")");
      for(int i = index;i >=0;i--){
        if(line[i] == '('){
          string sub = line.substr(i+1,index-(i+1));
          int result = eval("1 * " + sub);
          string str = to_string(result);
          if(index+1 >= line.length()){
            if(i == 0){
              line = str;
            }
            else{
              line = line.substr(0,i) + str;
            }
          }
          else{
            if(i == 0){
              line = str + line.substr(index+1);
            }
            else{
              line = line.substr(0,i) + str + line.substr(index+1);
            }
          }
          break;
        }
      }
    }
    sum += eval("1 * " + line);
  }
  cout << sum << endl;
}
