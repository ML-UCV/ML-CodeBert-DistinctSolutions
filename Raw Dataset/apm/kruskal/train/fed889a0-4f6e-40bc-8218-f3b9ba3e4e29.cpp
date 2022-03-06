#include <bits/stdc++.h>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



int n, m, rez;

int Union[200001], UnSize[200001];

tuple <int, int, int> muchie[400001];

stack <pair<int, int>> per;



int rad(int nod)

{

    while(nod != Union[nod])

        nod = Union[nod];



    return nod;

}



int main()

{

    in >> n >> m;



    for(int i, j, c, k = 1; k <= m; k++)

    {

        in >> i >> j >> c;

        muchie[k] = make_tuple(c, i, j);

    }



    sort(muchie + 1, muchie + 1 + m);



    for(int i = 1; i <= n; i++)

    {

        Union[i] = i;

        UnSize[i] = 1;

    }



    for(int q = n-1, k = 1; q; k++)

    {

        int c, i, j, ri, rj;

        tie(c, i, j) = muchie[k];

        ri = rad(i);

        rj = rad(j);



        if(ri == rj)

            continue;



        q--;

        rez += c;

        per.push({i,j});



        if(UnSize[ri] < UnSize[rj])

            swap(ri, rj);



        UnSize[ri] += UnSize[rj];

        Union[rj] = ri;

    }



    out << rez << '\n';

    out << n-1 << '\n';



    while(!per.empty())

    {

        out << per.top().first << ' ' << per.top().second << '\n';

        per.pop();

    }



    return 0;

}
