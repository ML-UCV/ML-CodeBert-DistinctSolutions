#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;



FILE*f=fopen("swap.in","r");

FILE*g=fopen("swap.out","w");



int n;

int child[30],aib[50005],fr1[30],fr2[30];

char A[50005],B[50005];

vector<int>P[30];



inline int lsb ( int x ){

 return x & -x;

}



inline void update_aib ( int poz ){



 while ( poz <= n ){

  ++aib[poz];

  poz += lsb(poz);

 }

}



inline int query_aib ( int poz ){

 int s = 0;



 while ( poz > 0 ){

  s += aib[poz];

  poz -= lsb(poz);

 }



 return s;

}



int main () {



 fscanf(f,"%s%s",A+1,B+1);

 n = strlen(A+1);



 for ( int i = 1 ; i <= n ; ++i ){

  P[ A[i]-'a'+1 ].push_back(i);

  ++fr1[A[i]-'a'+1];

  ++fr2[B[i]-'a'+1];

 }



 for ( int i = 1 ; i <= 26 ; ++i ){

  if ( fr1[i] != fr2[i] ){

   fprintf(g,"-1\n");

   fclose(f);

   fclose(g);

   return 0;

  }

 }



 long long sol = 0;

 for ( int i = 1 ; i <= n ; ++i ){

  int pos = P[ B[i]-'a'+1 ][child[B[i]-'a'+1]++];

  int real_pos = pos + i - 1 - query_aib(pos-1);



  sol += real_pos - i;

  update_aib(pos);

 }



 fprintf(g,"%lld\n",sol);



 fclose(f);

 fclose(g);



 return 0;

}
