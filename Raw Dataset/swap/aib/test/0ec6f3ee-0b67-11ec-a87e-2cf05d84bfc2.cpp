#include<bits/stdc++.h>
using namespace std;



typedef struct lnod {

    int nod;

    lnod *next;

}*nod;



int i,n,aib[50005],ar[50005],rs;

nod lda[30];

string a,b;



void update(int poz) {

    while(poz<=n) ++aib[poz],poz+=-poz&poz;

}



int query(int poz) {

    int aux=0;

    while(poz>=1) aux+=aib[poz],poz-=-poz&poz;

    return aux;

}



void add(int x,nod &y) {

    nod p=new lnod;

    p->nod=x;

    p->next=y;

    y=p;

}



int main()

{

  ifstream cin("swap.in");

  ofstream cout("swap.out");



  ios_base::sync_with_stdio(0); cin.tie(0);



  getline(cin,a); n=a.length();

  getline(cin,b);



  for(i=0;i<n;++i) add(i+1,lda[b[i]-'a']);



  for(i=n-1;i>=0;--i)

  {

    nod p=lda[a[i]-'a'];

    if(!p) return cout<<"-1\n",0;

    ar[i+1]=p->nod;

    lda[a[i]-'a']=p->next;

  }



  for(i=1;i<=n;++i) rs+=i-1-query(ar[i]),update(ar[i]);



  cout<<rs<<'\n';



 return 0;

}
