#include <bits/stdc++.h>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



const int MAX = 100001;



int nrctc, t;

vector <int> v[MAX], ct[MAX], disc, low, isInStack;

stack <int> s;



void ctc(int nod)

{

    t++;

    disc[nod] = low[nod] = t;

    s.push(nod);

    isInStack[nod] = true;



    for(auto it : v[nod])

    {

        if(!disc[it])

        {

            ctc(it);

            low[nod] = min(low[nod], low[it]);

        }

        else if(isInStack[it])low[nod] = min(low[nod], disc[it]);

    }



    if(low[nod] == disc[nod])

    {

        while(s.top() != nod)

        {

            ct[nrctc].push_back(s.top());

            isInStack[s.top()] = false;

            s.pop();

        }

        ct[nrctc].push_back(s.top());

        isInStack[s.top()] = false;

        s.pop();

        nrctc++;

    }



}



int main()

{

    int n, m;

    in >> n >> m;

    disc.assign(n, 0);

    low.assign(n, 0);

    isInStack.assign(n, 0);

    for(int i=0; i<m; i++)

    {

        int x, y;

        in >> x >> y; x--; y--;

        v[x].push_back(y);

    }

    for(int i=0; i<n; i++)

        if(!disc[i])

        {

            t = 0;

            ctc(i);

        }

    out << nrctc << '\n';

    for(int i=0; i<nrctc; i++)

    {

        for(auto it : ct[i])

            out << it + 1 << " ";

        out << '\n';

    }

    return 0;

}
