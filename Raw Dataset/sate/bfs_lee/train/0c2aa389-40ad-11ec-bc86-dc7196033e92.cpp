#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#define MAXN 30005

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n,m,sat_inceput,sat_sfarsit,dp[MAXN];
bool viz[MAXN];
vector< pair<int,int> >graf[MAXN];
queue<int>stiva;


int bfs(){
    stiva.push(sat_inceput);
    viz[sat_inceput] = true;

    while(stiva.front() != sat_sfarsit){
        int sat = stiva.front();
        stiva.pop();

        for(int i = 0; i < graf[sat].size(); ++i){
            int sat_curent = graf[sat][i].first;
            if(!viz[sat_curent]){
                stiva.push(sat_curent);
                viz[sat_curent] = true;
                if(sat_curent != sat_inceput){
                    if(sat_curent >= sat)
                        dp[sat_curent] = dp[sat] + graf[sat][i].second;
                    else if(sat_curent < sat)
                        dp[sat_curent] = dp[sat] - graf[sat][i].second;
                    //cout<<"Distanta de la "<<sat_inceput<<" la "<<sat_curent<<" este : "<<dp[sat_curent]<<endl;
                }
            }

        }
    }
    return dp[sat_sfarsit];
}

int main()
{
    in.tie(NULL);
    out.tie(NULL);
    ios::sync_with_stdio(false);

    in>>n>>m>>sat_inceput>>sat_sfarsit;

    int sat1,sat2;
    for(int i = 1; i <= m; ++i){
        int lung;
        in>>sat1>>sat2>>lung;
        graf[sat1].push_back({sat2,lung});
        graf[sat2].push_back({sat1,lung});

    }
    out<<bfs();


    return 0;
}
