#include <fstream>
#include <vector>
#include <stack>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n,m,i,x,y,nr,viz[100005],low[100005],niv;

bool s[100005];

vector <int> g[100005],c[100005];

stack <int> st;



void dfs(int nod){

    viz[nod]=low[nod]=++niv;

    s[nod]=1;

    st.push(nod);

    for(int i=0;i<g[nod].size();i++){

        int nou=g[nod][i];

        if(!viz[nou]){

            dfs(nou);

            low[nod]=min(low[nod],low[nou]);

        }

        else if(s[nou])

            low[nod]=min(low[nod],viz[nou]);

    }

    if(viz[nod]==low[nod]){

        nr++;

        int x=st.top();

        st.pop();

        while(x!=nod){

            s[x]=0;

            c[nr].push_back(x);

            x=st.top();

            st.pop();

        }

        s[nod]=0;

        c[nr].push_back(nod);

    }

}



int main()

{

    fin>>n>>m;

    for(i=1;i<=m;i++){

        fin>>x>>y;

        g[x].push_back(y);

    }

    for(i=1;i<=n;i++)

      if(!viz[i])

         dfs(i);

    fout<<nr<<'\n';

    for(i=1;i<=nr;i++){

        for(int j=0;j<c[i].size();j++)

            fout<<c[i][j]<<' ';

        fout<<'\n';

    }

    return 0;

}
