#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <utility>
#include <map>




using namespace std;



ifstream cin("dmin.in");

ofstream cout("dmin.out");



const int MAXN = 1505,

            oo = ((1<<31)-1),

           MOD = 104659;



vector< pair<int, double> > Graph[MAXN];

vector< double > Distance(MAXN, (double)oo);

bitset< MAXN > Used;

queue< int > Q;

map <int, int> NRoads;

int N, M;



const inline double Absolute(double a)

{

    if(a > 0)

        return a;

    return -a;

}

const inline bool isequal(double a, double b)

{

    if( Absolute(a-b) <= 1e-10 )

        return true;

    return false;

}



void Read_Data()

{

    cin >> N >> M;

    for(int i = 1 ; i <= M ; ++ i)

    {

        int X, Y, Z;

        cin >> X >> Y >> Z;

        Graph[X].push_back(make_pair(Y, log(Z)));

    }

    cin.close();

}



void BellmanFord()

{

    for(Q.push(1) , Distance[1] = 0, NRoads[1] = 1, Used[1] = true; !Q.empty(); Q.pop() )

    {

        int node = Q.front();

        Used[node] = false;

        for(vector <pair<int, double > > :: iterator it = Graph[node].begin(), fin = Graph[node].end(); it != fin ; ++ it)

            {if(isequal(Distance[node] + it->second, Distance[it->first]))

            {

                NRoads[it->first] += NRoads[node];

                if(NRoads[it->first] > MOD)

                    NRoads[it->first] -= MOD;

            }

            else if(Distance[it->first] > it->second + Distance[node]) {

                Distance[it->first] = it->second + Distance[node];

                NRoads[it->first] = NRoads[node];

                if( !Used[it->first] )

                {

                    Used[it->first] = true;

                    Q.push(it->first);

                }

            }}

    }



}

void Write_Data()

{

    for(int i = 2 ; i <= N; ++ i)

        cout << NRoads[i] << " ";

    cout << "\n";

    cout.close();

}

int main()

{

    Read_Data();

    BellmanFord();

    Write_Data();

    return 0;

}
