#include<fstream>
#include<vector>
#include<cstring>
#include<queue>


using namespace std;



const char iname[]="party.in";

const char oname[]="party.out";

const int maxn=200005;



ifstream f(iname);

ofstream g(oname);



vector<int> E[maxn],S,aux;

vector<vector<int> > CTC;



queue<int> Q;



int n,i,j,m,lowlink[maxn],burst[maxn],burstt,value[maxn];

int x,y,inS[maxn],node,scc[maxn],inG[maxn],type,k;



int id(const int& x),deny(const int& y);

void tarjan(int x),build_grades();



int main()

{

    f>>n>>m;

    for(i=1;i<=m;++i)

    {

        f>>x>>y>>type;

        switch(type)

        {

            case 0:E[deny(y)].push_back(id(x)),E[deny(x)].push_back(id(y));break;

            case 1:E[deny(x)].push_back(deny(y)),E[id(y)].push_back(id(x));break;

            case 2:E[deny(y)].push_back(deny(x)),E[id(x)].push_back(id(y));break;

            case 3:E[id(x)].push_back(deny(y)),E[id(y)].push_back(deny(x));break;

        }



    }

    for(i=n<<1;i;--i)

        if(burst[i]==0)

            tarjan(i);



    for(i=1;i<=n;++i)

        if(scc[i]==scc[i+n])

        {

            g<<-1<<"\n";

            f.close();

            g.close();



            return 0;

        }



    build_grades();

    for(i=0;i<CTC.size();++i)

        if(inG[i]==0)

            Q.push(i);

    memset(value,-1,sizeof(value));



    while(!Q.empty())

    {

        x=Q.front();

        Q.pop();

        for(vector<int>::iterator it=CTC[x].begin();it!=CTC[x].end();++it)

            for(vector<int>::iterator jt=E[*it].begin();jt!=E[*it].end();++jt)

                if(scc[*it]!=scc[*jt])

                {

                    --inG[scc[*jt]];

                    if(inG[scc[*jt]]==0)

                        Q.push(scc[*jt]);

                }



        for(vector<int>::iterator it=CTC[x].begin();it!=CTC[x].end();++it)

            if(value[*it]==-1)

                if(*it>n)

                    value[*it]=0,value[*it-n]=1;

                else

                    value[*it]=0,value[*it+n]=1;

    }

    for(i=1;i<=n;++i)

        k+=value[i];

    g<<k<<"\n";

    for(i=1;i<=n;++i)

        if(value[i])

            g<<i<<"\n";

    f.close();

    g.close();

    return 0;



}



void build_grades()

{

    for(int i=n<<1;i;--i)

        for(vector<int>::iterator it=E[i].begin();it!=E[i].end();++it)

            if(scc[*it]!=scc[i])

                ++inG[scc[*it]];

}



void tarjan(int x)

{

    lowlink[x]=burst[x]=++burstt;

    S.push_back(x);inS[x]=1;

    for(vector<int>::iterator it=E[x].begin();it!=E[x].end();++it)

        if(burst[*it]==0)

            tarjan(*it),

            lowlink[x]=min(lowlink[x],lowlink[*it]);

        else

            if(inS[*it])

                lowlink[x]=min(lowlink[x],lowlink[*it]);

    if(lowlink[x]==burst[x])

    {

        aux.clear();

        do

        {

            aux.push_back(node=S.back());

            S.pop_back();inS[node]=0;scc[node]=CTC.size();

        } while(node!=x);

        CTC.push_back(aux);

    }

}



int deny(const int& x)

{

    if(x<0)

        return -x;

    if(x<=n)

        return x+n;

    return x-n;

}

int id(const int& x)

{

    if(x<0)

        return n-x;

    return x;

}
