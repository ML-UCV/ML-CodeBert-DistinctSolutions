#include <fstream>
#include <string.h>
using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char c,semn[100000],st[100000];

int i,n,k,nr,gasitnr,fp[100000];

long long steval[1000];



int main(){

 while(f >> c){

  if(c >= '0' && c <= '9'){

   gasitnr = 1;

   nr *= 10;

   nr += c-'0';

  }else{

   if(gasitnr){

    n++;

    fp[n] = nr;

    nr = 0;

    gasitnr = 0;

   }

   if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/'){

    k++;

    st[k] = c;

    if(st[k] == '+' || st[k] == '-'){

     while(st[k-1] == '+' || st[k-1] == '-' || st[k-1] == '*' || st[k-1] == '/'){

      n++;

      semn[n] = st[k-1];

      st[k-1] = st[k];

      k--;

     }

    }else{

     if(st[k] == '*' || st[k] == '/'){

      while(st[k-1] == '*' || st[k-1] == '/'){

       n++;

       semn[n] = st[k-1];

       st[k-1] = st[k];

       k--;

; }

     }

    }

   }else{

    if(c == ')'){

     while(st[k] != '('){

      n++;

      semn[n] = st[k];

      k--;

     }

     k--;

    }

   }

  }

 }

 if(gasitnr){

  n++;

  fp[n] = nr;

  nr = 0;

  gasitnr = 0;

 }

 while(k){

  n++;

  semn[n] = st[k];

  k--;

 }

 k = 0;

 for(int i = 1; i <= n; i++){

  if(semn[i] != '+' && semn[i] != '-' && semn[i] != '*' && semn[i] != '/'){

   k++;

   steval[k] = fp[i];

  }else{

   switch(semn[i]){

    case '+': steval[k-1] = steval[k-1]+steval[k]; break;

    case '-': steval[k-1] = steval[k-1]-steval[k]; break;

    case '*': steval[k-1] = steval[k-1]*steval[k]; break;

    case '/': steval[k-1] = steval[k-1]/steval[k]; break;

    default:

     break;

   }

   k--;

  }

 }

 g << steval[1];

 return 0;

}
