#include <bits/stdc++.h>


using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



const int MMAX = 1005;

int X[MMAX],Y[MMAX],Z[MMAX];

bool ok[105];



int main()

{

    int n,m;

    fin >> n >> m;

    for(int i=1;i<=n;i++) ok[i]=1;

    for(int i=1;i<=m;i++) fin >> X[i] >> Y[i] >> Z[i];

    bool ok_boomer=0;

    while(ok_boomer==0){

        ok_boomer=1;

        for(int i=1;i<=m;i++)

        {

            int x,y,z;

            x=X[i],y=Y[i],z=Z[i];

            if(z==0) if(ok[x]==0 and ok[y]==0){

                ok[x]=1;

                ok[y]=1;

                ok_boomer=0;

                break;

            }

            if(z==1) if(ok[x]==0 and ok[y]==1){

                ok[y]=0;

                ok_boomer=0;

                break;

            }

            if(z==2) if(ok[x]==1 and ok[y]==0){

                ok[x]=0;

                ok_boomer=0;

                break;

            }

            if(z==3) if(ok[x]==1 and ok[y]==1){

                ok[y]=0;

                ok_boomer=0;

                break;

            }

        }

    }

    int rasp=0;

    for(int i=1;i<=n;i++) if(ok[i]==1) rasp++;

    fout << rasp << '\n';

    for(int i=1;i<=n;i++) if(ok[i]==1) fout << i << '\n';

    return 0;

}
