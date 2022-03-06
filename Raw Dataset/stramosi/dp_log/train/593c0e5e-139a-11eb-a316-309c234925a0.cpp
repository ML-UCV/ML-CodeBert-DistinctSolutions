#include <fstream>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

int n,m,s[21][250005];

int rasp(int a,int b){

    int node=a;

    for(int i=0;(1<<i)<=b;i++)

        if((1<<i)&b)

          node=s[i][node];

    return node;

}

int main()

{

    in>>n>>m;

    for(int i=1;i<=n;i++)

        in>>s[0][i];

    for(int k=1;k<=20;k++)

    for(int i=1;i<=n;i++)

      s[k][i]=s[k-1][s[k-1][i]];

    for(int i=1,a,b;i<=m;i++){

        in>>a>>b;

        out<<rasp(a,b)<<'\n';

    }

    return 0;

}
