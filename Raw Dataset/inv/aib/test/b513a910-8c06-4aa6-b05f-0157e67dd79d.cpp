#include <fstream>
#include <algorithm>






using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



int n,i,a,b,k,v[100005],aib[100005],nr,sol,poz;

struct numar{

    int x,p;

}aa[100005];



int cmp(numar a, numar b){

    if(a.x==b.x)

        return a.p<b.p;

    return a.x<b.x;

}



int query(int x){

    int s=0;

    while(x>0){

        s=(s+aib[x])%9917;

        x-=(x&(-x));

    }

    return s;

}



void update(int x){

    while(x<=k){

        aib[x]++;

        if(aib[x]>=9917)

            aib[x]-=9917;

        x+=(x&(-x));

    }

}



int main()

{

    fin>>n;

    for(i=1;i<=n;i++){

        fin>>aa[i].x;

        aa[i].p=i;

    }

    sort(aa+1,aa+n+1,cmp);

    k=1;

    for(i=1;i<=n;i++){

        if(aa[i].x!=aa[i-1].x)

            k++;

        v[aa[i].p]=k;

    }

    for(i=1;i<=n;i++){

        nr=query(k)-query(v[i]);

        if(nr<0)

            nr+=9917;

        sol+=nr;

        if(sol>=9917)

           sol-=9917;

        update(v[i]);

    }

    fout<<sol;

    return 0;

}
