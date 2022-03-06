#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <bitset>
using namespace std;
int n,m;

pair< pair< int,int >,int > cer[1010];

bitset< 110 > rez;



inline void citire() {

 scanf("%d%d",&n,&m);

 for(int i=1; i<=m; ++i)

  scanf("%d%d%d",&cer[i].first.first,&cer[i].first.second,&cer[i].second);

}



inline bool vezi(int x) {

 int a = cer[x].first.first;

 int b = cer[x].first.second;

 if(cer[x].second==0)

  return (rez[a]==1 || rez[b]==1);

 if(cer[x].second==1)

  return (rez[a]==1 || (rez[a]==0 && rez[b]==0));

 if(cer[x].second==2)

  return (rez[b]==1 || (rez[a]==0 && rez[b]==0));

 return (rez[a]==0 || rez[b]==0);

}



inline void rezolva() {

 srand(time(NULL));



 int cati0 = n,unde;

 bool go = true,ok;

 int a,b;



 while(go) {

  ok = true;

  for(int i=1; i<=m && ok; ++i) {

   if(vezi(i)==false) {

    unde = i;

    ok = false;

   }

  }



  if(ok==false) {

   a = cer[unde].first.first;

   b = cer[unde].first.second;

   if(rand()&1) {

    rez[a] = ( (rez[a]==1) ? (0) : (1) );

    if(rez[a]==0)

     ++cati0;

    else

     --cati0;

   } else {

    rez[b] = ( (rez[b]==1) ? (0) : (1) );

    if(rez[b]==0)

     ++cati0;

    else

     --cati0;

   }

   continue;

  }



  if(cati0==n) {

   a = rand()%n + 1;

   rez[a] = 1;

   --cati0;

   continue;

  }



  go = false;

 }

}



inline void scrie() {

 int nrez = 0;

 for(int i=1; i<=n; ++i) {

  if(rez[i]==1)

   ++nrez;

 }



 printf("%d\n",nrez);

 for(int i=1; i<=n; ++i) {

  if(rez[i]==1)

   printf("%d\n",i);

 }

}





int main() {

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);



 citire();

 rezolva();

 scrie();



 return 0;

}
