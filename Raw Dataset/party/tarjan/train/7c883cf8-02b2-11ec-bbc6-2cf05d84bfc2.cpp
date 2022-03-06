#include <cstdio>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
using namespace std;







typedef set<int>::iterator siter;

typedef vector<int>::iterator viter;



vector<int> g[210];

set<int> cg[210];

vector<vector<int> > cc;

int idx[210],llink[210],comp[210],ts[210],tidx=1,n,m,nc=0,tnc;

bitset<210> viz,inStack,val;

stack<int> stk;



inline int non(int x){

 return (x>n)?x-n:x+n;

}



void tarjan(int nod){

 idx[nod]=llink[nod]=tidx++;

 stk.push(nod),inStack[nod]=true;



 for(viter it=g[nod].begin();it!=g[nod].end();++it){

  if(!idx[*it]){

   tarjan(*it);

   llink[nod]=min(llink[*it],llink[nod]);

  }else if(inStack[*it]){

   llink[nod]=min(llink[*it],llink[nod]);

  }

 }



 if(llink[nod]==idx[nod]){

  vector<int> con;

  int nd;

  do{

   con.push_back(nd = stk.top());

   stk.pop(),inStack[nd]=false;

   comp[nd]=nc;

  }while(nd!=nod);

  nc++;

  cc.push_back(con);

 }

}



void build(){

 for(int i=0;i<nc;i++){

  for(int j=0;j<cc[i].size();j++){

   for(viter it=g[cc[i][j]].begin();it!=g[cc[i][j]].end();++it){

    cg[i].insert(comp[*it]);

   }

  }

 }

}



void tsort(int nod){

 viz[nod]=true;

 for(siter it=cg[nod].begin();it!=cg[nod].end();++it){

  if(!viz[*it]){

   tsort(*it);

  }

 }

 ts[--tnc]=nod;

}



void solve(int nod){

 if(viz[nod]){

  for(viter it=cc[nod].begin();it!=cc[nod].end();it++){

   val[*it]=false;

   val[non(*it)]=true;

   viz[comp[non(*it)]]=false;

  }

 }

}



bool verif(){

 for(int i=1;i<=n;i++){

  if(comp[i]==comp[non(i)]){

   return false;

  }

 }

 return true;

}



int main(){

 FILE* fin=fopen("party.in","r");

 FILE* fout=fopen("party.out","w");



 fscanf(fin,"%d %d\n",&n,&m);



 for(int i=0,x,y,z;i<m;i++){

  fscanf(fin,"%d %d %d\n",&x,&y,&z);

  switch(z){

   case 0:

    g[x+n].push_back(y);

    g[y+n].push_back(x);

    break;

   case 1:

    g[x+n].push_back(y+n);

    g[y].push_back(x);

    break;

   case 2:

    g[y+n].push_back(x+n);

    g[x].push_back(y);

    break;

   case 3:

    g[x].push_back(y+n);

    g[y].push_back(x+n);

    break;

  }

 }



 for(int i=1;i<=n+n;i++){

  if(!idx[i]){

   tarjan(i);

  }

 }



 if(verif()){

  build();



  tnc=nc;

  for(int i=0;i<nc;i++){

   if(!viz[i]){

    tsort(i);

   }

  }



  for(int i=0;i<nc;i++){

   solve(ts[i]);

  }



  vector<int> sol;

  for(int i=1;i<=n;i++){

   if(val[i]){

    sol.push_back(i);

   }

  }

  fprintf(fout,"%d\n",sol.size());

  for(viter it=sol.begin();it!=sol.end();++it){

   fprintf(fout,"%d\n",*it);

  }

 }else{

  fprintf(fout,"0\n");

 }

 fclose(fin);

 fclose(fout);

}
