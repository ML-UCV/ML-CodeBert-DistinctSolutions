#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int N = 200005;



int tt[N], rnk[N];



int n, m;



struct muchie

{

    int x, y, c;

};



vector<muchie> v;

vector<pair<int, int> > rez;





bool comp(muchie a, muchie b)

{

    return a.c < b.c;

}



int root(int x)

{

    int R, y;

    for(R=x; R!=tt[R]; R=tt[R]);



    while(x != tt[x])

    {

        y = tt[x];

        tt[x] = R;

        x = y;

    }

    return R;

}



void unite(int x, int y)

{

    if(rnk[x] > rnk[y])

    {

        tt[y] = x;

    }

    else

    {

        tt[x] = y;

    }

    if(rnk[x] == rnk[y])

    {

        rnk[y]++;

    }

}



int kruskal()

{

    int cmin = 0;

    sort(v.begin(), v.end(), comp);

    int nr = 0, i = 0;



    while(nr < n-1)

    {

        int n1 = v[i].x, n2 = v[i].y, cst = v[i].c;

        int rx = root(n1), ry = root(n2);

        if(rx != ry)

        {

            unite(rx, ry);

            cmin += cst;

            nr++;

            rez.push_back({n1, n2});

        }

        i++;

    }



    return cmin;



}





int main()

{

    int i, j, a, b, C;

    fin>>n>>m;

    for(i=1; i<=m; i++)

    {

        fin>>a>>b>>C;

        v.push_back({a, b, C});

    }



    for(i=1; i<=n; i++)

    {

        tt[i] = i;

        rnk[i] = 1;

    }

    fout<<kruskal()<<'\n';

    fout<<rez.size()<<'\n';

    for(i=0; i<rez.size(); i++)

    {

        fout<<rez[i].first<<' '<<rez[i].second<<'\n';

    }

    fin.close();

    fout.close();

    return 0;

}
