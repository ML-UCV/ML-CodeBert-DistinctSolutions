#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");

int t[200010], S[200010];

int a, b, ra, rb, n, m, i, sol, alese;



int rad(int x) {



    while(t[x] > 0)

        x = t[x];

    return x;

}



pair< int, pair<int, int> > v[400010];



int main (){

    fin>>n>>m;

    for (i=1;i<=m;i++)

        fin>>v[i].second.first>>v[i].second.second>>v[i].first;

    sort(v+1, v+m+1);



    for (i=1;i<=n;i++)

        t[i] = -1;



    for (i=1;i<=m;i++) {

        a = v[i].second.first;

        b = v[i].second.second;



        ra = rad(a);

        rb = rad(b);



        if (ra != rb) {

            if (-t[ra] > -t[rb]) {



                t[ra] += t[rb];

                t[rb] = ra;

            } else {

                t[rb] += t[ra];

                t[ra] = rb;

            }

            sol += v[i].first;



            alese++;

            S[alese] = i;

            if (alese == n-1)

                break;

        }

    }

    fout<<sol<<"\n"<<n-1<<"\n";

    for (i=1;i<=alese;i++)

        fout<<v[ S[i] ].second.first<<" "<<v[ S[i] ].second.second<<"\n";

    return 0;

}
