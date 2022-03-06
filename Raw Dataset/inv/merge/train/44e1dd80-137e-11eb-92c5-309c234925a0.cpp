#include <fstream>

using namespace std;
ifstream fin("inv.in");
ofstream fout("inv.out");
int cnt;
int v[100001];
void dei(int st,int dr)
{
    if(st==dr)
    {
        return;
    }
    int mij=(st+dr)/2;
    dei(st,mij);
    dei(mij+1,dr);
    int B[dr-st+2];
    int i=st,j=mij+1,pas=0;
    while(i<=mij && j<=dr)
    {
        if(v[i]>v[j])
        {
            cnt+=(mij-i+1);
            cnt%=9917;
            B[pas++]=v[j];
            j++;
        }
        else
        {
            B[pas++]=v[i];
            i++;
        }
    }
    while(i<=mij) {B[pas++]=v[i];i++;};
    while(j<=dr) {B[pas++]=v[j];j++;};
    for(i=st,pas=0;i<=dr;i++,pas++) v[i]=B[pas];
}
int main()
{
    int n,i;
    fin>>n;
    for(i=1;i<=n;i++) fin>>v[i];
    dei(1,n);
    fout<<cnt;
}
