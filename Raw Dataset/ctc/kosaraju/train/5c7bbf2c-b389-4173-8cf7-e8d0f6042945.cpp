#include <fstream>
#include <vector>
#include <stack>
#include <bitset>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

const int N = 100010;

int n,m,comp[N],nc;

vector<int> vd[N],vi[N];

bitset<N> viz;

stack<int> st;

void dfsD(int);

void dfsI(int);

vector<int> c;

vector<vector<int>> C;

int main()

{

    f>>n>>m;

    for(;m;m--)

    {

        int x,y;

        f>>x>>y;

        vd[x].push_back(y);

        vi[y].push_back(x);



    }

    for(int i=1;i<=n;i++)

        if(!viz[i])

            dfsD(i);



    do

    {

        while(st.size()&&comp[st.top()])

            st.pop();

        if(st.size())

        {

            nc++;

            int x=st.top();

            c.resize(0);

            dfsI(x);

            C.push_back(c);

        }

    }

    while(st.size());

    g<<C.size()<<'\n';

    for(auto com:C)

    {

        for(auto it:com)

            g<<it<<' ';

        g<<'\n';

    }

    return 0;

}

void dfsD(int nod)

{

    viz[nod]=1;

    for(auto vec:vd[nod])

        if(!viz[vec])

            dfsD(vec);

    st.push(nod);

}

void dfsI(int nod)

{

    c.push_back(nod);

    comp[nod]=nc;

    for(auto vec:vi[nod])

        if(!comp[vec])

            dfsI(vec);



}
