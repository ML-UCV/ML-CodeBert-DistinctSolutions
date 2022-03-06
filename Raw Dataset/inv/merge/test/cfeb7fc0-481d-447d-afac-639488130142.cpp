#include <bits/stdc++.h>	

using namespace std;
ifstream f("inv.in");
ofstream g("inv.out");
int n,a[100005],sol,temp[100005];
const int MOD=9917;
void interclasare(int st,int dr)
{
    int k=0;
    int i=st;
    int mid=(st+dr)/2;
    int j=mid+1;
    while(i<=mid && j<=dr)
    {
        if(a[i]<=a[j])
            temp[++k]=a[i++];
        else
        {
            sol+=(mid-i+1);
            sol%=MOD;
            temp[++k]=a[j++];
        }
    }
    while(i<=mid)
        temp[++k]=a[i++];
    while(j<=dr)
        temp[++k]=a[j++];
    for(i=st;i<=dr;i++)
        a[i]=temp[i-st+1];
}
void divide(int st,int dr)
{
    if(st<dr)
    {
        int mid=(st+dr)/2;
        divide(st,mid);
        divide(mid+1,dr);
        interclasare(st,dr);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>a[i];
    divide(1,n);
    g<<sol;
    return 0;
}
