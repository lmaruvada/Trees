#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool palindrome(char * st, int len){
  for(int i =1 ; i<len; i++){
    if((st[i-1] == st[i+1]) || (st[i] != st[i-1])){
      return true; 
    }
  }
  return false;
};

int main(){
  char str[200];
  cout << "Enter a string: " << endl;  
  gets (str);
  if(palindrome(str, strlen(str)))
    cout << "is true" << endl;
  else
    cout << "is false" << endl;
  return 0;
}
