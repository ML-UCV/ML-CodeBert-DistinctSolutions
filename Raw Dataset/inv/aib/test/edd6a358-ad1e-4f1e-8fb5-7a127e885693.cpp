#include <fstream>
#include <algorithm>


using namespace std;

ifstream in ("inv.in");

ofstream out ("inv.out");

int n,i,m,a[100005],b[100005],v[100005],aib[100005];

int ub (int x)

{

    return(x&(-x));

}



void add( int x )

{

    for(int i=x; i<=n; i+=ub(i))

    {

        aib[i]++;



    }



}

int sum (int x)

{

    int s=0;

    for(int i=x; i>=1; i-=ub(i))

    {

        s=s+aib[i];



    }

    return s;

}
int main()

{

in>>n;



for(i=1;i<=n;i++)

{in>>a[i];

    b[i]=a[i];

}

sort(b+1,b+n+1);

m=0;

v[++m]=b[1];

for(i=2;i<=n;i++)

{if(b[i]!=b[i-1])v[++m]=b[i];



}
for(i=1;i<=n;i++){a[i]=lower_bound(v+1,v+m+1,a[i])-v; }
int nr=0;

for(i=n;i>=1;i--)

{nr=nr+sum(a[i]-1);



    nr=nr%9917;

    add(a[i]);



}



    out<<nr;





    return 0;

}
