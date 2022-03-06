#include <fstream>
#include <vector>
#include <queue>
#include <climits>






using namespace std;



ifstream fi("apm.in");

ofstream fo("apm.out");



int n,m,nod,s,k;

int cost[200005],b[200005],dist[200005];

bool sel[200005];



vector <pair <int,int> >a[200005];

priority_queue <pair <int,int> > q;



int main()

{

    fi>>n>>m;



    for(int i=1;i<=m;i++)

    {

        int x,y,c;

        fi>>x>>y>>c;



        a[x].push_back({y,c});

        a[y].push_back({x,c});

    }



    for(int i=2; i<=n;i++)

    {

     dist[i]=INT_MAX;

     q.push({-INT_MAX,i});

    }



    q.push({0,1});



    while(1)

    {

        if(k==n)

            break;



        if(q.empty())

            break;



        int i=q.top().second;

        q.pop();



        if(!sel[i])

            {

                sel[i]=true;

                k++;

                for(int j=0;j<a[i].size();j++)

                {

                  nod=a[i][j].first;



                  if(dist[nod]>a[i][j].second and !sel[nod])

                  {

                      dist[nod]=a[i][j].second;

                      b[nod]=i;

                      q.push({-dist[nod],nod});

                  }



                }

            }



    }



    for(int i=1;i<=n;i++)

        s+=dist[i];



    fo<<s<<'\n';

    fo<<n-1<<'\n';



    for(int i=1;i<=n;i++)

    {

        if(b[i])

        fo<<b[i]<<" "<<i<<'\n';

    }



    return 0;

}
