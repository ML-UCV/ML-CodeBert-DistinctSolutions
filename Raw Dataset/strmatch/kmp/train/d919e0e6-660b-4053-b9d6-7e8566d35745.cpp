#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

const int lmax = 2000001;
const int nmax = 1000;
char A[lmax], B[lmax];
int lcp[lmax];

vector <int> sol;

void preProcessKMP(){
 int i,j,n;
 n = strlen(A);
 j = 0, lcp[0] = 0;
 for(i=1; i<n;){
  if(A[i] == A[j]){
   lcp[i] = j+1;
   i++, j++;
  }
  else{
   if(j != 0)
    j = lcp[j-1];
   else{
    lcp[i] = 0;
    i++;
   }
  }
 }
}

int KMP(){
 int ans = 0, j = 0;
 int m = (int)strlen(B), n = (int)strlen(A);
 for(int i=0; i<m;){
  if(B[i] == A[j])
   i++, j++;
  else{
   if(j != 0)
    j = lcp[j-1];
   else
    i++;
  }
  if(j == n){
   ans++;
   j = lcp[j-1];
   if(ans <= nmax)
    sol.push_back(i-n);
  }
 }
 return ans;
}

int main()
{
 FILE *fin, *fout;
 fin = fopen("strmatch.in","r");
 fout = fopen("strmatch.out","w");
 fscanf(fin,"%s\n%s\n",A,B);
 preProcessKMP();
 fprintf(fout,"%d\n",KMP());
 for(int i=0; i<(int)sol.size(); i++)
  fprintf(fout,"%d ",sol[i]);
 fclose(fin);
 fclose(fout);
 return 0;
}
