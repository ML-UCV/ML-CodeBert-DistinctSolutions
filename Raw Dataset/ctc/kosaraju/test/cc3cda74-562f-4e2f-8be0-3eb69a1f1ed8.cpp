#include <fstream>
#include <vector>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int N=100000+5;



int n,m,va[N],vb[N];

vector<int>A[N];

vector<int>B[N];

int st[N],vf=0;



inline void da(int a)

{

    va[a]=1;

    for(auto b:A[a])

    {

        if(va[b]==0)

        {

            da(b);

        }

    }

    st[++vf]=a;

}



int k;



vector<int>lol[N];



inline void db(int a)

{

    lol[k].push_back(a);

    vb[a]=1;

    for(auto b:B[a])

    {

        if(vb[b]==0)

        {

            db(b);

        }

    }

}



int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int a,b;

        fin>>a>>b;

        A[a].push_back(b);

        B[b].push_back(a);

    }

    for(int i=1;i<=n;i++)

    {

        if(va[i]==0)

        {

            da(i);

        }

    }

    for(int i=n;i>=1;i--)

    {

        int x=st[i];

        if(vb[x]==0)

        {

            k++;

            db(x);

        }

    }

    fout<<k<<"\n";

    for(int i=1;i<=k;i++)

    {

        for(auto x:lol[i])

        {

            fout<<x<<" ";

        }

        fout<<"\n";

    }

    return 0;

}
