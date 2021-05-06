#include <bits/stdc++.h>

using namespace std;

int main(){
  int validCount = 0;
  int min,max;
  char letter;
  string password;
  string range;
  string colon;
  size_t l = 4;
  int s = l;
  int count;
  while(cin >> range){
    count = 0;
    cin >> colon >> password;
    int hyphon = range.find("-");
    min = stoi(range.substr(0,hyphon));
    max = stoi(range.substr(hyphon+1));
    letter = colon[0];
    cout << password << endl;
    if(password[min-1] == letter & password[max-1] != letter){
      validCount++;
    }
    if(password[min-1] != letter && password[max-1] == letter){
      validCount++;
    }
  }
  cout << validCount << endl;
}
