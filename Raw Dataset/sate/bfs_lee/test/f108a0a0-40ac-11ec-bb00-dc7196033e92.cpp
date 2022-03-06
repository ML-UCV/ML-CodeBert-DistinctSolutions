#include <fstream>
#include <deque>
#include <vector>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

const int NMAX = 30005;
const int inf = 1e9;

struct variabila{
    int lo, hi;
};

vector <variabila> v[NMAX];
deque <int> q;
int n,m,x,y;
int dist[NMAX];
string s,sup;

void bfs(){
    int node,i;
    while(!q.empty()){
        node = q.front();
        q.pop_front();
        for(i = 0 ; i < v[node].size(); i++)
            if(v[node][i].hi + dist[node] < dist[v[node][i].lo]){
                dist[v[node][i].lo] = v[node][i].hi + dist[node];
                q.push_back(v[node][i].lo);
            }
    }

}

int main(){
    int i,a,b,d,j,li;
    variabila A;
    f >> n >> m >> x >> y;
    getline(f,s);
    for(i = 1 ; i <= m ; i++){
        getline(f,s);

        //f >> sup;
        //s += sup;
        //g << s << "\n";
        a = b = d = 0;
        j = 0;
        while(!(s[j] >= '0' && s[j] <= '9'))
            j++;

        li = j;
        j++;
        while(s[j] >= '0' && s[j] <= '9')
            j++;

        for(int k = li ; k < j ; k++)
            a = a * 10 + s[k] - '0';

        while(!(s[j] >= '0' && s[j] <= '9'))
            j++;

        li = j;
        j++;

        while(s[j] >= '0' && s[j] <= '9')
            j++;

        for(int k = li ; k < j ; k++)
            b = b * 10 + s[k] - '0';

        while(!(s[j] >= '0' && s[j] <= '9'))
            j++;

        li = j;
        j++;

        while(s[j] >= '0' && s[j] <= '9' && j < s.size())
            j++;

        for(int k = li ; k < j ; k++)
            d = d * 10 + s[k] - '0';

        s.clear();
        //f.get();
        //getline(f,s);
       // s.clear();

        //g << a << " " << b << " " << d << "\n";
        //f >> a >> b >> d;
        A.lo = b;
        A.hi = d;
        v[a].push_back(A);
        A.lo = a;
        A.hi = -d;
        v[b].push_back(A);
    }

    for(i = 1 ; i <= n ; i++)
        dist[i] = inf;

    q.push_back(x);
    dist[x] = 0;
    bfs();

    g << dist[y];
    return 0;
}
