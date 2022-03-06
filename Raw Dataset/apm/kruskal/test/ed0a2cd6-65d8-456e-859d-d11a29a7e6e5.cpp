#include <iostream>
#include <bits/stdc++.h>




using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

int N,M;

int r[200005], tata[200005], h[200005];

int counter = 1, cost = 0;

vector<tuple<int,int,int>> muchii;

vector<tuple<int,int,int>> APM;



void initializare(int nod)

{

    tata[nod] = r[nod]=0;

}



int reprez(int nod)

{

   while(tata[nod]!=0)

   {

       nod = tata[nod];

   }

   return nod;

}

void reuneste(int a, int b)

{

    int r1 = reprez(a);

    int r2 = reprez(b);

    if(h[r1]>h[r2])

        tata[r2]=r1;

    else

    {

        tata[r1]=r2;

        if(h[r1]==h[r2])

            h[r2]++;

    }

}

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b)

{

    return get<2>(a) < get<2>(b);

}

int main()

{

    in>>N>>M;

    muchii.reserve(M);

    APM.reserve(N);

    int x,y,z;

    for(int i=1; i<=M; i++)

    {

        in>>x>>y>>z;

        muchii.push_back({x,y,z});

    }

    sort(muchii.begin(),muchii.end(),cmp);

    for(int i=1; i<=N; i++)

        initializare(i);



    for(auto &muchie:muchii)

    {

        x = get<0>(muchie);

        y = get<1>(muchie);

        if(reprez(x)!=reprez(y))

        {

            APM.push_back(muchie);

            cost+= get<2>(muchie);

            reuneste(x,y);

            counter++;

            if(counter==N)

                break;

        }

    }

    out<<cost<<'\n'<<APM.size()<<'\n';

    for(auto &muchie:APM)

        out<<get<0>(muchie)<<' '<<get<1>(muchie)<<'\n';

    return 0;

}
