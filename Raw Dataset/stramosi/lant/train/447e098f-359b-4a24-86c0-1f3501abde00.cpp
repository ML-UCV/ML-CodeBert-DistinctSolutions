#include <fstream>
#include <vector>
using namespace std;
ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



struct nod{

             int index;

             vector<int> sons;

          }v[250003];



struct wee{

            int poz, p;

          };



vector<wee> q[250003];



int sol[300003], n, m;



bool b[250003];



void DFSsolve(int x)

{

    int Stack[250003], vf=0;

    Stack[++vf]=x;

    for(int i=0;i<q[Stack[vf]].size();++i)

    {

        if(q[Stack[vf]][i].p>=vf) sol[q[Stack[vf]][i].poz]=0;

        else sol[q[Stack[vf]][i].poz]=Stack[vf-q[Stack[vf]][i].p];

    }

    while(vf)

    {

        if(v[Stack[vf]].index<v[Stack[vf]].sons.size())

        {

            Stack[vf+1]=v[Stack[vf]].sons[v[Stack[vf]].index];

            v[Stack[vf]].index++;

            vf++;

            for(int i=0;i<q[Stack[vf]].size();++i)

            {

                if(q[Stack[vf]][i].p>=vf) sol[q[Stack[vf]][i].poz]=0;

                else sol[q[Stack[vf]][i].poz]=Stack[vf-q[Stack[vf]][i].p];

            }

        }

        else vf--;

    }

}



int main()

{

    fin>>n>>m;

    for(int i=1;i<=n;++i)

    {

        int x;

        fin>>x;

        v[x].sons.push_back(i);

        v[i].index=0;

        if(x==0) b[i]=1;

    }

    for(int i=1;i<=m;++i)

    {

        int x, y;

        fin>>x>>y;

        wee z;

        z.poz=i, z.p=y;

        q[x].push_back(z);

    }

    for(int i=1;i<=n;++i)

        if(b[i]) DFSsolve(i);

    for(int i=1;i<=m;++i) fout<<sol[i]<<"\n";

    fout<<"\n";

    return 0;

}
