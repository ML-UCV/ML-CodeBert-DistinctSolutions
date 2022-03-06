#include<bits/stdc++.h>

using namespace std;
char s1[2000005],s2[2000005];
int n,m,k,pi[2000005];
vector<int>rez;

ifstream ccin("strmatch.in");
ofstream ccout("strmatch.out");


void prefix(){
  k=0;
  for(int i=2; i<=n; i++){
    while(k>0&&s1[k+1]!=s1[i])
      k=pi[k];
    if(s1[k+1]==s1[i])
      k+=1;
    pi[i]=k;
    }
}

int main(){
    ccin>>s1+1>>s2+1;
    n=strlen(s1+1); m=strlen(s2+1);
    prefix();
    k=0;
    for(int i=1; i<=m; i++){
      while(k>0&&s1[k+1]!=s2[i])
        k=pi[k];
      if(s1[k+1]==s2[i])
        k++;
      if(k==n)
        rez.push_back(i-n);
    }
    k=rez.size();
    ccout<<k<<'\n';
    for(int i=0; i<min(k,1000); i++)
      ccout<<rez[i]<<' ';
    return 0;
}
