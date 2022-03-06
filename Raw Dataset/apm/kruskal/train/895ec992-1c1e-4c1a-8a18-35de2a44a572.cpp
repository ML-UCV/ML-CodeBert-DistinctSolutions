#include <bits/stdc++.h>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int DIM = 2e5 + 7;



int p[DIM];



vector < pair <int, int > > rez;



vector < pair <int, pair <int,int> > > v;



struct

{

    bool operator()(pair <int , pair <int,int> > x,pair <int, pair <int,int > > y)

    {

        return x.first < y.first;

    }

}cmp;



int findp(int x)

{

    if(p[x] < 0)

        return x;



    return findp(p[x]);

}



void unionp(int x,int y)

{

    if(p[x] < p[y])

    {

        p[x] = p[x] + p[y];

        p[y] = x;

    }

    else

    {

        p[y] = p[y] + p[x];

        p[x] = y;

    }

}





int main()

{

    int n, m;

    in >> n >> m;



    for(int i = 1; i <= n; i++)

        p[i] = -1;



    while(m--)

    {

        int x, y, c;

        in >> x >> y >> c;



        v.push_back(make_pair(c,make_pair(x, y)));

    }



    int sum = 0;



    sort(v.begin(), v.end(), cmp);



    int cnt = 0;



    for(int i = 0; i < v.size(); i++)

    {

        int nod1 = v[i].second.first;

        int nod2 = v[i].second.second;



        int p1 = findp(nod1);

        int p2 = findp(nod2);



        if(p1 != p2)

        {

            unionp(p1, p2);

            if(p[p1] < 0)

            {

                rez.push_back({nod1,nod2});

            }

            else

                rez.push_back({nod2,nod1});

            sum += v[i].first;

            cnt++;

            if(cnt == n - 1)

                break;

        }

    }



    out << sum <<'\n'<< n - 1 <<'\n';



    for(int i = 0; i < rez.size(); i++)

        out << rez[i].first <<" "<< rez[i].second <<'\n';



    return 0;

}
