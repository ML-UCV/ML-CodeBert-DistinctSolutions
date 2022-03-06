#include <stdio.h>
#include <vector>
#include <stack>


FILE *fin,*fout;

int ctc;

char viz[100001],vizt[100001];

std::vector<int>l[100001];

std::vector<int>lt[100001];

std::stack<int>s;

std::vector<int>r[100001];



void dfs(int nod){

  viz[nod]=1;

  for(auto i: l[nod])

    if(!viz[i])

      dfs(i);

  s.push(nod);

}



void dfst(int nod){

  vizt[nod]=1;

  r[ctc].push_back(nod);

  for(auto i: lt[nod])

    if(!vizt[i])

      dfst(i);

}



int main(){

  fin=fopen("ctc.in","r");

  fout=fopen("ctc.out","w");

  int n,m,i,x,y;



  fscanf(fin,"%d%d",&n,&m);

  for(i=0; i<m; i++){

    fscanf(fin,"%d%d",&x,&y);

    l[x].push_back(y);

    lt[y].push_back(x);

  }

  for(i=1; i<=n; i++)

    if(!viz[i])

      dfs(i);

  while(!s.empty()){

    int f=s.top();

    s.pop();

    if(!vizt[f]){

      dfst(f);

      ctc++;

    }

  }

  fprintf(fout,"%d\n",ctc);

  for(i=0; i<ctc; i++){

    for(auto a: r[i])

      fprintf(fout,"%d ",a);

    fprintf(fout,"\n");

  }

  fclose(fin);

  fclose(fout);

  return 0;

}
