#include <fstream>

using namespace std;
int lg[2000000],nex[23][300005],put[30];
int que(int nod,int p){
    if(p==0){
        return nod;
    }
    int e=lg[p];
    return que(nex[e][nod],p-put[e]);
}
int main()
{
    ifstream cin("stramosi.in");
    ofstream cout("stramosi.out");
    int n,q,nod,p,a;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a;
        nex[0][i]=a;
    }
    nex[0][0]=0;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            nex[i][j]=nex[i-1][nex[i-1][j]];
        }
    }
    put[0]=1;
    for(int i=1;i<=20;i++){
        put[i]=put[i-1]*2;
        lg[put[i]]++;
    }
    for(int i=1;i<=1000000;i++){
        lg[i]+=lg[i-1];
    }
    for(int i=1;i<=q;i++){
        cin>>nod>>p;
        cout<<que(nod,p)<<"\n";
    }
    return 0;
}
