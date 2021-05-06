#include <bits/stdc++.h>

using namespace std;

int main(){
  string person;
  int count = 0;
  while(true){
    int index;
    int arr[26] = {0};
    int personCount = 0;
    while(getline(cin,person) && person.length() > 0){
      personCount++;
      for(int i = 0;i < person.length();i++){
        index = person[i] - 'a';
        arr[index]++;
      }
    }
    for(int i = 0;i < 26;i++){
      if(arr[i] == personCount){
        count++;
      }
    }
  }
  cout << count << endl;
}
