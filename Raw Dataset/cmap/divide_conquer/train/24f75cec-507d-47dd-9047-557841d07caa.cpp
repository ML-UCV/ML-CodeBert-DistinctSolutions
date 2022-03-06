#include <bits/stdc++.h>




using namespace std;
vector <pair<int, int>> P;

int n;



long long calculDist(pair<int, int> a, pair<int, int> b)

{

    return (long long) (a.first-b.first) * (a.first-b.first)+ (long long)(a.second - b.second) * (a.second - b.second);

}



bool cmp(pair<int,int> a, pair<int,int>b)

{

    return a.second < b.second;

}



long long DI(int st, int dr)

{

    if(dr - st == 1)

        return calculDist(P[st],P[dr]);

    else if(dr - st == 2)

    {

        long long d1 = calculDist(P[st],P[st+1]);

        long long minim = d1;

        long long d2 = calculDist(P[st],P[st+2]);

        if(d2 < minim )

            minim = d2;

        long long d3 = calculDist(P[st+1],P[st+2]);

        if(d3 < minim)

            minim = d3;

        return minim;

    }



    int m = (st + dr)/2,i,j;

    long long dist = min(DI(st,m),DI(m+1,dr));

    int delta = (int)(ceil(sqrt(dist)));



    vector<pair<int,int>> verif;

    for(i = st; i <= dr; i++)

        if(abs(P[i].first - P[m].first) <= delta)

            verif.push_back(P[i]);

    sort(verif.begin(),verif.end(),cmp);



    for(unsigned i = 0; i < verif.size(); i++)

        for(unsigned j = i+1; j<= i + 7 && j< verif.size(); j++)

            dist = min(dist, calculDist(verif[i],verif[j]));

    return dist;





}



int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    int x,y,i;

    fin>>n;



    for(i = 0; i < n; i++)

    {

        fin>>x>>y;

        P.push_back({x,y});

    }



    sort(P.begin(),P.end());



    fout<<fixed<<setprecision(6)<<sqrt(DI(0,n-1));

    fin.close();

    fout.close();

    return 0;



}
