#include <bits/stdc++.h>
using namespace std;

char s[100003], *p=s;
long long i;

long long eval1();
long long eval2();
long long eval(){
 long long rez=eval1();
 while(*p=='+'||*p=='-'){
  if(*p=='+'){
   ++p;
   rez+=eval1();
  }
  else{
   ++p;
   rez-=eval1();
  }
 }
 return rez;
}
long long eval1(){
 long long rez=eval2();
 while(*p=='*'||*p=='/'){
  if(*p=='*'){
   ++p;
   rez*=eval2();
  }
  else {
   ++p;
   rez/=eval2();
  }
 }
 return rez;
}
long long eval2(){
 long long rez=0;
 if(*p=='('){
  ++p;
  rez=eval();
  ++p;
 }
 else while(isdigit(*p)){
  rez=rez*10+*p-'0';
  ++p;
 }
 return rez;
}
int32_t main(){
 ifstream cin("evaluare.in");
 ofstream cout("evaluare.out");
 cin >> s;
 cout << eval();
}
