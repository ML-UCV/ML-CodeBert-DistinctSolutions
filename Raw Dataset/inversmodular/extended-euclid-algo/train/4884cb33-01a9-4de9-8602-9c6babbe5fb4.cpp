#include<bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");





long long a,n,x,y;



void read()

{

 fin>>a>>n;

}



void invmod(long long u,long long v,long long &x,long long &y)

{

 if(!v)

     {

        x=1;

        y=0;

        return;

     }



 long long X,Y;

 invmod(v,u%v,X,Y);

 x=Y;

 y=X-(u/v)*Y;



}



void solve()

{

 invmod(a,n,x,y);



 while(x<0)

        x+=n;



 fout<<x;

}
int main()

{

 read();

 solve();



 return 0;

}
