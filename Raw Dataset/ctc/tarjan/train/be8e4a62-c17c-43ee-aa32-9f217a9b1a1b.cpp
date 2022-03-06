#include <fstream>
#include <vector>
#include <stack>
#include <set>




using namespace std;



int n, m, i, j, k, start, ord[100003], levMin[100003];

vector<int> vec[100003], comp[100003];

stack<int> stiva;

set<int> s;



void func(int nod) {

    int p, x;



    ord[nod] = start;

    levMin[nod] = start;

    start++;

    stiva.push(nod);

    s.insert(nod);



    for(p = 0; p < vec[nod].size(); p++)

        if(!ord[vec[nod][p]]) {

            func(vec[nod][p]);

            levMin[nod] = min(levMin[nod], levMin[vec[nod][p]]);

        }

        else if(s.find(vec[nod][p]) != s.end())

           levMin[nod] = min(levMin[nod], ord[vec[nod][p]]);



    if(ord[nod] == levMin[nod])

        while(!stiva.empty()) {

            x = stiva.top();

            stiva.pop();

            s.erase(x);

            comp[k].push_back(x);

            if(x == nod) {

                k++;

                break;

            }

        }

}



int main() {

    ifstream f("ctc.in");

    ofstream g("ctc.out");



    f >> n >> m;

    while(m) {

        f >> i >> j;



        vec[i].push_back(j);

        m--;

    }

    f.close();



    k = 0;

    start = 1;

    for(i = 1; i <= n; i++)

        if(!ord[i])

            func(i);

    g << k << '\n';



    for(i = 0; i < k; i++, g << '\n')

        for(j = 0; j < comp[i].size(); j++)

            g << comp[i][j] << ' ';



    g.close();



    return 0;

}
