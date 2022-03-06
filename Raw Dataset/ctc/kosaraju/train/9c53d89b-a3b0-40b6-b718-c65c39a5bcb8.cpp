#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>






using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int N, M;

stack<int> S;

vector<int> adiac[100005];

vector<int> inv_adiac[100005];

vector<int> ctc[100005];

int nr_ctc;

char vizitat[100005];



void DFSP(vector<int> m[], int nod)

{

    int i;



    vizitat[nod] = 1;



    for(i = 0; i < m[nod].size(); i++)

        if(vizitat[m[nod][i]] != 1)

            DFSP(m, m[nod][i]);



    S.push(nod);

}



void DFSS(vector<int> m[], int nod)

{

    int i;



    vizitat[nod] = 2;

    ctc[nr_ctc].push_back(nod);



    for(i = 0; i < m[nod].size(); i++)

        if(vizitat[m[nod][i]] != 2)

            DFSS(m, m[nod][i]);

}



int main()

{

    int x, y, i, j;



    in >> N >> M;

    for(i = 0; i < M; i++) {

        in >> x >> y;



        adiac[x].push_back(y);

        inv_adiac[y].push_back(x);

    }



    for(i = 1; i <= N; i++)

        if(!vizitat[i])

            DFSP(inv_adiac, i);



    while(!S.empty()) {

        if(vizitat[S.top()] == 1) {

            DFSS(adiac, S.top());

            nr_ctc++;

        }

        S.pop();

    }



    out << nr_ctc << '\n';

    for(i = 0; i < nr_ctc; i++) {

        for(j = 0; j < ctc[i].size(); j++)

            out << ctc[i][j] << ' ';

        out << '\n';

    }



    in.close();

    out.close();



    return 0;

}
