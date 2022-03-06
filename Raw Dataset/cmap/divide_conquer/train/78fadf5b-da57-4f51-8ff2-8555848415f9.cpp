#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>


using namespace std;





struct punct

{

    long long x,y;

};



long long distanta(punct x, punct y)

{

    long long X = x.x - y.x;

    long long Y = x.y - y.y;



    return X*X + Y*Y;

}



void citire(vector <punct>&v, int &n)

{

    ifstream fin("cmap.in");



    fin>>n;

    v.resize(n);



    for(int i=0;i<n;i++)

        fin>>v[i].x>>v[i].y;



    fin.close();

}



bool cmp(punct x, punct y)

{

    return ((x.x<y.x) || (x.x==y.x && x.y<y.y));

}





void interclasare(vector<punct>&v, int st, int m, int dr)

{

    int i = st, j= m+1;

    vector<punct>aux;



    while(i <=m && j <= dr)

    {

        if(v[i].y < v[j].y)

            aux.push_back(v[i++]);

        else aux.push_back(v[j++]);

    }



    while(i <= m)

        aux.push_back(v[i++]);



    while(j <= dr)

        aux.push_back(v[j++]);



    for(i = st, j = 0; i<= dr; i++,j++)

        v[i] = aux[j];

}



long long DIVIDE_ET_IMPERA( vector <punct> &v, int st, int dr)

{

    if(st>=dr)

        return 4e18;



    else if(dr-st==1)

    {

        long long minim = distanta(v[st],v[dr]);





        if(v[st].y > v[dr].y)

            swap(v[st],v[dr]);



        return minim;



    }

    else if(dr-st==2)

    {

        long long minim = min(distanta(v[st],v[st+1]), min(distanta(v[st+1],v[dr]),distanta(v[st],v[dr])));



        interclasare(v,st,st+1,dr);

        return minim;

    }



    else

    {

        int m = (st + dr)/2;



        long long minim=min(DIVIDE_ET_IMPERA(v,st,m),DIVIDE_ET_IMPERA(v,m+1,dr));



        interclasare(v,st,m,dr);





        vector <punct> aux;

        for(int i=st ; i<=dr ; i++)

            if(abs(v[i].x - v[m].x) < minim)

               aux.push_back(v[i]);



        int ssize=aux.size();





        for(int i=0;i<ssize-1;i++)

            for(int j=i+1; j<ssize && j<=i+7; j++)

                minim = min( minim, distanta(aux[i],aux[j]));



        return minim;



    }

}



int main()

{

    int n;

    vector <punct> v;

    ofstream fout("cmap.out");

    citire(v,n);

    sort(v.begin(),v.end(),cmp);



    fout<<fixed<<setprecision(6)<<(double)sqrt( DIVIDE_ET_IMPERA(v,0,n-1));

    fout.close();

    return 0;

}
