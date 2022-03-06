#include <iostream>
#include <fstream>
#include <vector>



using namespace std;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

int n,m,table[20][250000 +5],q,p;

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>table[0][i];
    }
    for(int j=1;j<=17;j++){
        for(int i=1;i<=n;i++){
            table[j][i]=table[j-1][table[j-1][i]];
        }
    }
    while(m--){
        f>>q>>p;
        for(int j=17;j>=0;j--){
            if((1<<j)<=p){
                q=table[j][q];
                p=p-(1<<j);
            }
        }
        g<<q<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
