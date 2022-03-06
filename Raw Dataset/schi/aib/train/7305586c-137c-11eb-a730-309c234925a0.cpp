#include<bits/stdc++.h>
using namespace std;

const int N=30005;

int aib[N];

void update(int poz,int val){

  for(int i=poz;i<N;i+=i&(-i))

    aib[i]+=val;

}

int query(int poz){

  int ans=0;

  for(int i=poz;i>0;i-=i&(-i)){

    ans+=aib[i];

  }

  return ans;

}

int v[N];

int ans[N];

int main()

{

  FILE*fin,*fout;

  fin=fopen("schi.in","r");

  fout=fopen("schi.out","w");

  int n;

  fscanf(fin,"%d",&n);

  for(int i=1;i<=n;i++){

    fscanf(fin,"%d",&v[i]);

    update(i,1);

  }

  for(int i=n;i>=1;i--){

    int pas=0,p2=1<<15;

    int rnk=v[i];

    while(p2){

      if(pas+p2<=n && aib[pas+p2]<rnk){

        pas+=p2;

        rnk-=aib[pas];

      }

      p2/=2;

    }

    pas++;

    update(pas,-1);

    ans[pas]=i;

  }

  for(int i=1;i<=n;i++){

    fprintf(fout,"%d\n",ans[i]);

  }

  return 0;

}
