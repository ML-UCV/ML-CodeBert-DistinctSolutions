#include <iostream>
#include <fstream>
using namespace std;
bool ok[109];
struct inv{
    int x,y,z;
    bool check()
    {
        if(z==0)
            return ok[x]||ok[y];
        if(z==1)
            return ok[x]||!ok[y];
        if(z==2)
            return !ok[x]||ok[y];
        if(z==3)
            return !(ok[x]&&ok[y]);
        return 0;
    }

    void random()
    {
        int v=rand()%2;
        if(v==0)
            ok[x]=!ok[x];
        else
            ok[y]=!ok[y];
    }
};
inv inviat[1003];
int n,m;

int main()
{


    ifstream f("party.in");
    ofstream g("party.out");
    f>>n>>m;
    for(int i=1;i<=n;++i){
        ok[i]=1;
    }

    for(int i=0;i<m;++i)
        f>>inviat[i].x>>inviat[i].y>>inviat[i].z;

    for(int i=0;i<m;++i)
        if(!inviat[i].check()){
            inviat[i].random();
            i=-1;
        }

    int nr=0;
    for(int i=1;i<=n;++i)
        if(ok[i])
            nr++;
    g<<nr<<'\n';
    for(int i=1;i<=n;++i)
        if(ok[i])
            g<<i<<'\n';
    return 0;
}
