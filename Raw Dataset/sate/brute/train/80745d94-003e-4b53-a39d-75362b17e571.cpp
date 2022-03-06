#include<fstream>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,x,y,i;
int a[100100] , b[100100] , d[100100];
int drum[100100];
int main()
{
    fin>>x>>m>>x>>y;
    for(i=1;i<=m;i++)
        fin>>a[i]>>b[i]>>d[i];
    drum[x]=1;
    while(!drum[y])
        for(i=1;i<=m;i++)
            if(!drum[a[i]] && drum[b[i]])
                drum[a[i]]=drum[b[i]]-d[i];
            else if(drum[a[i]] && !drum[b[i]])
                drum[b[i]]=drum[a[i]]+d[i];
    fout<<drum[y]-1;
    fin.close();
    fout.close();
    return 0;
}
