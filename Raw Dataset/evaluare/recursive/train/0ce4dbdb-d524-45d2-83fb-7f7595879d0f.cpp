#include <fstream>
using namespace std;

char s[100001], *p=s;

ifstream cin("evaluare.in");
ofstream cout("evaluare.out");

long long eval();
long long termen();
long long factor();

long long eval(){
 long long r=termen();
 while (*p=='+' || *p=='-'){
  if (*p=='+'){
   ++p;
   r=r+termen();
  }
  else{
   ++p;
   r=r-termen();
  }
 }
 return r;
}

long long termen(){
 long long r=factor();
 while (*p=='*' || *p=='/'){
  if (*p=='*'){
   ++p;
   r=r*factor();
  }
  else{
   ++p;
   r=r/factor();
  }
 }
 return r;
}

long long factor(){
 long long r=0;
 if (*p=='('){
  ++p;
  r=eval();
  ++p;
 }
 else{
  while (*p>='0' && *p<='9'){
   r=r*10+*p-'0';
   ++p;
  }
 }
 return r;
}


int main(){
 cin>>s;
 cout<<eval();
 cin.close();
 cout.close();
 return 0;
}
