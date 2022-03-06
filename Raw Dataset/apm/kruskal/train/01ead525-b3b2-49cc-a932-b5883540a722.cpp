#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchie {

    int operator< (const muchie &b) const {

        return c < b.c;

    }

    int a, b, c;

};



muchie m;

int n, x, y, c, T[200005], cost, mn;

vector<muchie> v;

vector< pair<int, int> > rez;



int rad(int x) {

    while (T[x] > 0)

        x = T[x];

    return x;

}



void process(muchie m) {

    int ra = rad(m.a);

    int rb = rad(m.b);



    if (ra != rb){

        cost += m.c;



        rez.push_back(make_pair(m.a, m.b));



        if (T[ra] < T[rb]) {

            T[ra] += T[rb];

            T[rb] = ra;

        } else {

            T[rb] += T[ra];

            T[ra] = rb;

        }

    }

}



void afisare(pair<int, int> pr) {

    fout << pr.first << " " << pr.second << "\n";

}



int main() {

    fin >> n >> mn;



    while (fin >> m.a >> m.b >> m.c)

        v.push_back(m);



    for (int i=1;i<=n;++i)

        T[i] = -1;



    sort(v.begin(), v.end());



    for_each(v.begin(), v.end(), process);



    fout << cost << "\n" << n-1 << "\n";



    for_each(rez.begin(), rez.end(), afisare);

}
