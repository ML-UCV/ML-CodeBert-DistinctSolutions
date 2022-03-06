#include <bits/stdc++.h>


using namespace std;

ifstream fin("dmin.in");

ofstream fout("dmin.out");

const int NMAX = 15010;

const int MOD = 104659;

const double EPS = 1e-10;

int n, m;

vector<pair<int, double>> graf[NMAX];

double dist[NMAX];

int counter[NMAX];

bool use[NMAX];

struct comp

{

  bool operator()(int a, int b)

  {

      return dist[a]>dist[b];

  }

};

void dij()

{

    priority_queue<int, vector<int>, comp> cue;

    cue.push(1);

    fill(dist, dist+NMAX, INT_MAX);

    dist[1] = 0;

    counter[1] = 1;

    use[1] = 1;

    while(cue.size())

    {

        for(auto i:graf[cue.top()])

        {

            double newLength = (double)dist[cue.top()]+ (double)i.second;

            if(dist[i.first]>newLength || (dist[i.first]<newLength+EPS && dist[i.first]>newLength-EPS))

            {

                if((dist[i.first]<newLength+EPS && dist[i.first]>newLength-EPS))

                {

                    counter[i.first]=(counter[i.first]+counter[cue.top()])%MOD;

                }

                else

                {

                    counter[i.first]=counter[cue.top()]%MOD;

                    if(!use[i.first]) cue.push(i.first),use[i.first]=1;

                    dist[i.first]=newLength;

                }

            }

        }

        use[cue.top()]=0;

        cue.pop();

    }

}

int main()

{

    fin>>n>>m;

    while(m--)

    {

        int a, b, c;

        fin>>a>>b>>c;

        graf[a].push_back({b,(double)log2((double)c)});

        graf[b].push_back({a,(double)log2((double)c)});

    }

    dij();

    for(int i = 2;i<=n;i++) fout<<counter[i]%MOD<<" ";

    return 0;

}
