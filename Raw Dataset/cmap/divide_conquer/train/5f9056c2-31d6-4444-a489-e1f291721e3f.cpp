#include <bits/stdc++.h>




using namespace std;
double calculDist(pair<int, int> a, pair<int, int> b)

{

    double x = a.first - b.first;

    double y = a.second - b.second;

    return sqrt(pow(x,2) + pow(y,2));

}



bool cmpY(const pair<int,int>& a, const pair<int,int> &b)

{

    return a.second < b.second;

}



bool cmpX(const pair<int,int>& a, const pair<int, int> &b)

{

    return a.first < b.first;

}



double DI(int st, int dr, vector<pair<int,int>> &pY,vector<pair<int,int>> &P)

{

    if(dr - st == 1)

        return INT_MAX;

    else if(dr - st == 2)

    {

       if(pY[st].second > pY[st+1].second)

            swap(pY[st], pY[st+1]);

       return calculDist(P[0],P[1]);

    }



    int m = (st + dr)/2,i,j;

    double dist = min(DI(st,m,pY,P),DI(m,dr,pY,P));

    int delta = (int)(ceil(sqrt(dist)));



    vector<pair<int,int>> verif(dr - st);

    merge(pY.begin() + st, pY.begin() + m, pY.begin() + m, pY.begin() + dr, verif.begin(), cmpY);

    copy(verif.begin(), verif.begin() + (dr - st), pY.begin() + st);



    vector<pair<int,int>> z;



    for(unsigned i = st; i < dr; i++)

        if(abs(pY[i].first - P[m].first) <= dist)

            z.push_back(pY[i]);





    for(unsigned i = 0; i < z.size(); i++)

        for(unsigned j = i+1;j< z.size() && z[j].second - z[i].second <= dist; j++)

            dist = min(dist, calculDist(z[i],z[j]));

    return dist;





}



int main()

{

    int n;

    vector<pair<int,int>>P;

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    int x,y,i;

    fin>>n;



    for(i = 0; i < n; i++)

    {

        fin>>x>>y;

        P.push_back(make_pair(x,y));

    }



    sort(P.begin(),P.end(),cmpX);



    vector<pair <int,int>> pY = P;





    fout<<fixed<<setprecision(6)<<(DI(0,n-1,pY,P));

    fin.close();

    fout.close();

    return 0;



}
