#include <fstream>
#include <vector>
#include <set>


using namespace std;



struct muchie {

    int nod;

    int cost;

    bool operator <(const muchie& alt) const{

        return this->cost < alt.cost;

    }

};



const int N = 2e5, INF = 1 << 30;



vector<muchie> gr[N];

multiset<muchie> s;

int cmin[N], cor[N];

bool exista[N];

pair<int, int> rez[N];



void cost_minim(int nod) {

    for (auto i : gr[nod])

        if (!exista[i.nod] && i.cost < cmin[i.nod]) {

            cmin[i.nod] = i.cost;

            cor[i.nod] = nod;

            s.insert(i);

        }

}



int main() {

    ifstream in("apm.in");

    ofstream out("apm.out");



    int n, m, x, y, c;

    in >> n >> m;

    while (m--) {

        in >> x >> y >> c;

        --x, --y;

        gr[x].push_back({ y, c });

        gr[y].push_back({ x, c });

    }

    for (int i = 0; i < N; ++i)

        cmin[i] = INF;

    cost_minim(0);

    exista[0] = true;

    int nod, cost, ctot = 0;

    for (int i = 1; i < n; ++i) {

        nod = s.begin()->nod;

        while (exista[nod]) {

            s.erase(s.begin());

            nod = s.begin()->nod;

        }

        s.erase(s.begin());

        exista[nod] = true;

        cost = cmin[nod];

        ctot += cost;

        rez[i - 1] = { nod, cor[nod] };

        cost_minim(nod);

    }

    out << ctot << '\n' << n - 1 << '\n';

    for (int i = 0; i < n - 1; ++i)

        out << rez[i].first + 1 << ' ' << rez[i].second + 1 << '\n';



    in.close();

    out.close();

    return 0;

}
