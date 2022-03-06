#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const long long infinit = 4e18;



struct triplet

{

    pair<long long,long long> p1,p2;



    long long distanta;

};





void interclasare(int p, int m, int q, vector< pair<long long,long long> > & v)

{

    vector< pair<long long,long long> > aux;



    int i = p, j = m;



    while(i<m && j<q)

        if(v[i].first <= v[j].first)

            aux.push_back(v[i++]);

        else

            aux.push_back(v[j++]);



    while(i<m)

        aux.push_back(v[i++]);



    while(j<q)

        aux.push_back(v[j++]);



    for(int i=0; i < (int)aux.size(); i++)

        v[p+i] = aux[i];

}



long long dist(pair<long long,long long> a, pair<long long,long long> b)

{

    return ((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));

}



triplet DI(int st, int dr, vector< pair<long long,long long> > & v, vector< pair<long long,long long> > & u)

{

    if(dr-st < 2)

    {

        triplet inf;



        inf.distanta = infinit;



        inf.p1 = {infinit,infinit};



        inf.p2 = {infinit,infinit};



        return inf;

    }



    if(dr-st == 2)

    {

        if(u[st].first > u[dr-1].first)

            swap(u[st],u[dr-1]);



        triplet d;



        d.distanta = dist(v[st],v[dr-1]);



        d.p1 = v[st];



        d.p2 = v[dr-1];



        return d;

    }



    int m=(st+dr)/2;



    triplet D1 = DI(st, m, v, u);



    triplet D2 = DI(m, dr, v, u);



    triplet D_min;



    if(D1.distanta < D2.distanta)

        D_min = D1;

    else

        D_min = D2;



    interclasare(st, m, dr, u);



    vector< pair<long long,long long> > proxim;



    for(int i=st ;i < dr; i++)

        if(abs(u[i].second-v[m].first) <= D_min.distanta)

            proxim.push_back(u[i]);



    for(int i=0; i < (int)proxim.size()-1; i++)

        for(int j=i+1; j < (int)proxim.size() && j-i<8 ; j++)

            if(D_min.distanta > dist(proxim[i],proxim[j]))

            {

                D_min.distanta = dist(proxim[i],proxim[j]);



                D_min.p1.first = proxim[i].second;



                D_min.p1.second = proxim[i].first;



                D_min.p2.first = proxim[j].second;



                D_min.p2.second = proxim[j].first;

            }



    return D_min;

}



int main()

{

    int n;



    fin>>n;



    vector< pair<long long,long long> > v(n);



    for(int i=0; i<n; i++)

        fin>>v[i].first>>v[i].second;



    sort(v.begin(), v.end());



    vector< pair<long long,long long> > u(n);



    for(int i=0; i<n; i++)

    {

        u[i].first = v[i].second;



        u[i].second = v[i].first;

    }



    triplet mini = DI(0, n, v, u);



    fout<<fixed<<setprecision(6)<<sqrt(mini.distanta);



    return 0;

}
