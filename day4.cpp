#include <bits/stdc++.h>

using namespace std;

bool check(map<string,string> m){
  string byr = m["byr"];
  string iyr = m["iyr"];
  string eyr = m["eyr"];
  string hgt = m["hgt"];
  string hcl = m["hcl"];
  string ecl = m["ecl"];
  string pid = m["pid"];
  //checks for anything that makes the passport invalid
  if(byr.length() != 4 || stoi(byr) < 1920 || stoi(byr) > 2002){
    return false;
  }
  if(iyr.length() != 4 || stoi(iyr) < 2010 || stoi(iyr) > 2020){
    return false;
  }
  if(eyr.length() != 4 || stoi(eyr) < 2020 || stoi(eyr) > 2030){
    return false;
  }
  string heightType = hgt.substr(hgt.length()-2);
  if(heightType != "in" && heightType != "cm"){
    return false;
  }
  int height = stoi(hgt.substr(0,hgt.length()-1));
  if(heightType == "in" && (height < 59 || height > 76)){
    return false;
  }
  if(heightType == "cm" && (height < 150 || height > 193)){
    return false;
  }
  if(hcl[0] != '#' || hcl.length() != 7){
    return false;
  }
  for(int i = 1;i < 7;i++){
    char val = hcl[i];
    if(val < 48 || val > 102){
      return false;
    }
    if(val > 57 && val < 97){
      return false;
    }
  }
  if(ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth"){
    //cout << "bigo" << endl;
    return false;
  }
  if(pid.length() != 9){
    return false;
  }
  for(int i = 0;i < 9;i++){
    if(!isdigit(pid[i])){
      return false;
    }
  }
  return true;
}

int main(){
  string value,key,param;
  int validCount = 0;
  map<string,bool> m1;
  map<string,string> m2;

  while(true){
    //appended kill to input string to terminate parsing
    while(cin >> param && param != "kill"){
      int colon = param.find(":");
      key = param.substr(0,colon);
      value = param.substr(colon+1);
      //cout << value << endl;
      m1[key] = true;
      m2[key] = value;
    }
    if(m1["byr"] && m1["iyr"] && m1["eyr"] && m1["hgt"] && m1["hcl"] && m1["ecl"] && m1["pid"]){
      if(check(m2)){
      validCount++;
      }
    }
    m1.clear();
    m2.clear();
  }
  cout << validCount << endl;
}
