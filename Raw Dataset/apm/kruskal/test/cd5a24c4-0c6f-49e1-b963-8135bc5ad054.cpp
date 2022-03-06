#include<iostream>
#include<fstream>
#include<algorithm>




using namespace std;



long long tata[200001], nrmuchii, s;



struct mama

{

    int x, y, cost;

}v[400001];



int findtata(int x)

{

    if(x == tata[x])

        return x;

    else

        return tata[x] = findtata(tata[x]);

}



void uniune(int x, int y)

{

    int sefx, sefy;

    sefx = findtata(x);

    sefy = findtata(y);

    tata[sefx] = sefy;

}



bool cmp(mama a, mama b)

{

    return a.cost < b.cost;

}

int main()

{



    ifstream fin("apm.in");

    ofstream fout("apm.out");



    int i, n, m;



    fin >> n >> m;



    for(i = 1; i <= n; i ++)

        tata[i] = i;



    for(i = 1; i <= m; i ++)

        fin >> v[i].x >> v[i].y >> v[i].cost;



    sort(v + 1, v + m + 1, cmp);



    for(i = 1; i <= m; i ++)

    {

        if(findtata(v[i].x) != findtata(v[i].y))

        {

            uniune(v[i].x, v[i].y);

            nrmuchii ++;

            s += v[i].cost;

            v[i].cost = 1001;

        }

    }

    fout << s << '\n';

    fout << nrmuchii << '\n';

    for(i = 1; i <= m; i ++)

        if(v[i].cost == 1001)

            fout << v[i].x << " " << v[i].y << '\n';



    return 0;



}
