#include <fstream>
#include <deque>
using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

deque <int> aux[300];

int i, n, v[50003], ok, z[50003];

char c1[50003], c2[50003];

long long sol;



void update(int p, int val)

{

    for(;p<=n;p+=p&(-p))

        z[p]+=val;

}



int quarry(int p)

{

    int r=0;

    for(;p>=1;p-=p&(-p))

        r+=z[p];

    return r;

}



int verif(int a)

{

    if(a<0)

        a=-a;

    return a;

}



int main()

{

    fin>>c1;

    fin>>c2;

    for(i=0;c2[i]!=0;i++)

        aux[c2[i]].push_back(i+1);

    for(i=0;c1[i]!=0;i++)

    {

        n++;

        if(aux[c1[i]].size()>0)

        {

            v[i+1]=aux[c1[i]][0];

            aux[c1[i]].pop_front();

        }

        else

        {

            ok=1;

        }

    }

    if(ok==1)

    {

        fout<<-1;

        return 0;

    }

    for(i=1;i<=n;i++)

    {

        sol+=v[i]-1-quarry(v[i]);

        update(v[i], 1);

    }

    fout<<sol;

    fin.close();

    fout.close();

    return 0;

}
