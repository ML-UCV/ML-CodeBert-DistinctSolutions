#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;



priority_queue < pair < double, int > > PQ;



vector < pair < int, double > > v[1505];



double D[1505];



int NR[1505];



bitset < 1505 > inQueue;



int N, M;

void read(){
    freopen("dmin.in", "r", stdin);


    scanf("%d %d", &N, &M);



    int x, y, c;

    while(M--){

        scanf("%d %d %d", &x, &y, &c);



        v[x].push_back(make_pair(y,log(c)));

        v[y].push_back(make_pair(x,log(c)));

    }

    fclose(stdin);
}


void Dijkstra(){

    for(int i=2; i<=N; ++i)

       D[i] = 9999999.0;



    NR[1] = 1;

    PQ.push(make_pair(0.0, 1));

    inQueue[1] = true;



    while(!PQ.empty()){

        double dx = -PQ.top().first;

        int x = PQ.top().second;



        PQ.pop();

        inQueue[x] = false;



        for(typeof(v[x].begin()) it=v[x].begin(); it!=v[x].end(); ++it)

           if(D[(*it).first] - dx - (*it).second > 0.000000001){

               D[(*it).first] = dx + (*it).second;

               NR[(*it).first] = NR[x];



               if(!inQueue[(*it).first]){

                   PQ.push(make_pair(-D[(*it).first], (*it).first));

                   inQueue[(*it).first] = true;

               }

           }

           else if(abs(D[(*it).first] - dx - (*it).second) < 0.000000001)

               NR[(*it).first] = (0LL + NR[(*it).first] + NR[x]) % 104659;

    }
}

void print(){
    freopen("dmin.out", "w", stdout);



    for(int i=2; i<=N; ++i)

       printf("%d ", NR[i]);

    fclose(stdout);
}

int main(){
    read();
    Dijkstra();
    print();

    return 0;
}
