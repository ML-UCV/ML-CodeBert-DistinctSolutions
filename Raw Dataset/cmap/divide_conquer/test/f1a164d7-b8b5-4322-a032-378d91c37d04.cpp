#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

struct Point

{

    long long x,y;

}p1_sol,p2_sol;



void read(int &n, vector <Point> &v)

{

    fin>>n;

    v.resize(n);



    for(int i=0;i<n;i++)

        fin>>v[i].x>>v[i].y;

}



bool cmp(Point a, Point b)

{

    return ((a.x<b.x) || (a.x==b.x && a.y<b.y));

}



long long distance(Point a, Point b)

{

    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);

}



void merge_function(int st,int m,int dr,vector <Point> &v)

{

    int i=st,j=m+1;

    vector <Point> aux;



    while(i<=m && j<=dr)

    {

        if(v[i].y<v[j].y)

            aux.push_back(v[i++]);

        else aux.push_back(v[j++]);

    }



    while(i<=m)

        aux.push_back(v[i++]);

    while(j<=dr)

        aux.push_back(v[j++]);



    int index=st;

    for( Point a : aux)

    {

        v[index]=a;

        index++;

    }

}



long long divide(int st,int dr, vector <Point> &v)

{

    if(dr-st==1)

    {

        long long minim=distance(v[st],v[dr]);

        if(v[st].y>v[dr].y)

            swap(v[st],v[dr]);



        return minim;



    }

    else if(dr-st==2)

    {

        long long minim=min(distance(v[st],v[st+1]),min(distance(v[st],v[dr]),distance(v[dr],v[st+1])));
        merge_function(st,st,st+1,v);

        merge_function(st,st+1,dr,v);



        return minim;

    }

    else

    {

        int m=(st+dr)/2;

        long long mst=divide(st,m,v);

        long long mdr=divide(m+1,dr,v);



        long long minim=min(mst,mdr);

        merge_function(st,m,dr,v);



        vector <Point> aux;

        for(int i=st ; i<=dr ; i++)

            if(abs(v[i].x-v[m].x)<=minim)

               aux.push_back(v[i]);



        int siz=aux.size();



        for(int i=0;i<siz-1;i++)

            for(int j=i+1; j<siz && j<=i+7; j++)

                    minim = min( minim , distance(aux[i],aux[j]) );



        return minim;



    }

}



int main()

{

    int n;

    vector <Point> v;

    read(n,v);

    sort(v.begin(),v.end(),cmp);



    fout<<fixed<<setprecision(6)<<(double)sqrt( divide(0,n-1,v) );



    fin.close();

    fout.close();

    return 0;

}
