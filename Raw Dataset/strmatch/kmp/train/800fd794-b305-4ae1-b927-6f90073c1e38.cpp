#include<bits/stdc++.h>
using namespace std;



const int maxN=(2e6)+5;



char a[maxN],b[maxN];

int n,m,pref[maxN],k;

vector<int> pos;



int main()

{

    freopen("strmatch.in","r",stdin);

    freopen("strmatch.out","w",stdout);



    scanf("%s",a+1);

    scanf("\n");

    scanf("%s",b+1);



    n=strlen(a+1);

    m=strlen(b+1);





    pref[1]=0;



    k=0;

    for(int i=2;i<=n;i++)

    {

        while(k && a[k+1]!=a[i]) k=pref[k];

        if(a[k+1]==a[i]) k++;



        pref[i]=k;

    }





    k=0;

    for(int i=1;i<=m;i++)

    {

        while(k && a[k+1]!=b[i]) k=pref[k];

        if(a[k+1]==b[i]) k++;

        if(k==n) pos.push_back(i-n);

    }





    int sz=(int)pos.size();

    printf("%d\n",sz);



    if(sz>1000) pos.resize(1000);



    for(auto it:pos)

        printf("%d ",it);



    printf("\n");

    return 0;

}
