#include <bits/stdc++.h>

using namespace std;

string toBitMask(long long num){
  int count = 35;
  string bitMask = "000000000000000000000000000000000000";
  while(num>0){
    if(num%2 == 1){
      bitMask[count] = '1';
      count--;
    }
    else{
      count--;
    }
    num /= 2;
  }
  return bitMask;
}

long long parseBitMask(string bm){
  long long num = 0;
  for(int i = 35;i >= 0;i--){
    if(bm[i] == '1'){
      num += pow(2,35-i);
    }
  }
  return num;
}

string compare(string bm,string value){
  string comparison = "000000000000000000000000000000000000";
  for(int i = 0;i < 36;i++){
    if(bm[i] == 'X') comparison[i] = 'X';
    else if(bm[i] == '1'){
      comparison[i] = '1';
    }
    else if(bm[i] == '0') comparison[i] = value[i];
  }
  return comparison;
}

int main(){
  string line;
  string mask;
  long long value;
  int index;
  map<long,long long> m;
  string comparison;
  long long sum = 0;
  while(getline(cin,line)){
    if(line.find("mask") != string::npos){
      mask = line.substr(line.find("=")+2);
    }
    else if(line.find("mem") != string::npos){
      index = stoi(line.substr(line.find("[")+1,line.find("]")-4));
      value = stoi(line.substr(line.find("=")+2));
      comparison = compare(mask,toBitMask(index));
      string exes="";
      int max = 0;
      for(int i = 0;i < comparison.length();i++){
        if(comparison[i] == 'X'){
          max += pow(2,exes.length());
          exes += "0";
        }
      }
      for(int i = 0;i <= max;i++){
        string enu = toBitMask(i).substr(36-exes.length());
        string newIndex = "";
        int place = 0;
        for(int j = 0;j < comparison.length();j++){
          if(comparison[j] == 'X'){
            newIndex += enu[place];
            place++;
          }
          else{
            newIndex += comparison[j];
          }
        }
        if(m[parseBitMask(newIndex)] > 0){
          sum -= m[parseBitMask(newIndex)];
          sum += value;
          m[parseBitMask(newIndex)] = value;
        }
        else{
          sum += value;
          m[parseBitMask(newIndex)] = value;
        }
      }
    }
  }
  cout << sum << endl;
}
