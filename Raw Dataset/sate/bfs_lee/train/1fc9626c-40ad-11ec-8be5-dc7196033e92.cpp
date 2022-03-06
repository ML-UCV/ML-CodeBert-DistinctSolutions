#include<fstream>
#include<vector>
#include<queue>
using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");
queue<int> S;
vector<pair<int,int> > A[30001];
int n,m,X,Y,x,y,i,d,vf,Viz[30001];
vector<pair<int,int> >::iterator it;
int main()
{
    fi>>n>>m>>X>>Y;
    for(i=1; i<=m; i++)
    {
        fi>>x>>y>>d;
        A[x].push_back(make_pair(y,d));
        A[y].push_back(make_pair(x,d));
    }
    S.push(X);
    while(!S.empty())
    {
        vf=S.front();
        for(it=A[vf].begin(); it!=A[vf].end(); it++)
        {
            if(Viz[(*it).first]==0)
            {
                if((*it).first<vf)
                {
                    Viz[(*it).first]=Viz[vf]-(*it).second;
                }
                else
                {
                    Viz[(*it).first]=Viz[vf]+(*it).second;
                }
                S.push((*it).first);
                if((*it).first==Y)
                {
                    fo<<Viz[Y]<<"\n";
                    fi.close();
                    fo.close();
                    return 0;
                }
            }
        }
        S.pop();
    }
    fo<<Viz[Y]<<"\n";
    fi.close();
    fo.close();
    return 0;
}
