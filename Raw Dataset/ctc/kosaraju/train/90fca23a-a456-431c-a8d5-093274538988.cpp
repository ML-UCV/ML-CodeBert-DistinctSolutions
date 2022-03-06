#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>






using namespace std;



const char iname[] = "ctc.in";

const char oname[] = "ctc.out";







vector <int> Go[100005], Gi[100005], G[100005];



void read_in(vector <int>* Go, vector <int>* Gi, int& n, const char iname[])

{

    ifstream in(iname);

    int cnt_edges, x, y;



    in >> n;

    for (in >> cnt_edges; cnt_edges > 0; -- cnt_edges) {

        in >> x >> y;

        x --, y --;

        Go[x].push_back(y);

        Gi[y].push_back(x);

    }

    in.close();

}



vector <int> discovered, used;



void DFP(const int n, vector <int>* G)

{

    vector <int>::iterator it;

    used[n] = true;

    for (it = G[n].begin(); it != G[n].end(); ++ it)

        if (used[*it] == false)

            DFP(*it, G);

    discovered.push_back(n);

}



vector <int> where;



void DFM(const int n, vector <int>* G, const int which)

{

    vector <int>::iterator it;

    where[n] = which;

    for (it = G[n].begin(); it != G[n].end(); ++ it)

        if (where[*it] == -1)

            DFM(*it, G, which);

}



void print_out(const vector <int>* G, const int n, const char oname[])

{

    ofstream out(oname);

    vector <int>::const_iterator it;



    out << n <<'\n';

    for (int i = 0; i < n; ++ i) {

        for (it = G[i].begin(); it != G[i].end(); ++ it)

            out << *it + 1 << " ";

        out << '\n';

    }

    out.close();

}



int main(void)

{
    int n;
    read_in(Go, Gi, n, iname);
    used.resize(n);
    used.assign(used.size(), 0);
    for (int i = 0; i < n; ++ i) if (used[i] == false)
            DFP(i, Go);
    where.resize(n);
    where.assign(where.size(), -1);
    int count = 0;
    for (; discovered.size(); discovered.pop_back())
        if (where[discovered.back()] == -1) {
            DFM(discovered.back(), Gi, count);
            count ++;
        }
    for (int i = 0; i < n; ++ i)
        G[where[i]].push_back(i);
    print_out(G, count, oname);
    return 0;

}
