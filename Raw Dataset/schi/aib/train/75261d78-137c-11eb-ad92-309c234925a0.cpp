#include<bits/stdc++.h>
using namespace std;


int n,vec[30000],tree[30000];
int results[30000];

int lsb(int a)
{
    return a&(-a);
}

void update(int index,int value)
{
    while(index<=n)
    {
        tree[index]+=value;
        index+=lsb(index);
    }
}

int query(int index)
{
    int result=0;
    while(index)
    {
        result+=tree[index];
        index-=lsb(index);
    }
    return result;
}

void read()
{
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&vec[i]);
    }

    for(int i=1; i<=n; i++)
    {
        update(i,1);
    }
}


int get_index(int needed)
{
    int left=1,right=n;

    while(left<right)
    {
        int middle=(left+right)/2;
        int aux=query(middle);


        if(needed<=aux)
        {
            right=middle;
        }
        else
        {
            left=middle+1;
        }
    }

    return left;

}


void solve()
{
    for(int i=n-1; i>=0; i--)
    {
        int need_empty=vec[i];
        int index=get_index(need_empty);

        update(index,-1);

        results[index-1]=i+1;
    }


    for(int i=0; i<n; i++)
        printf("%d\n",results[i]);
}


int main()
{
    freopen("schi.in","r",stdin);
    freopen("schi.out","w",stdout);

    read();
    solve();
    return 0;
}
