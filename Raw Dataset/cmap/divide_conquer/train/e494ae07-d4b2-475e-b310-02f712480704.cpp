#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct punct

{

    int x,y;

};

vector<punct> c;

void citire(int &n,vector<punct> &a,vector<punct> &b)

{

        ifstream fin("cmap.in");

        fin>>n;

        punct aux;

        int i;

        for(i=0;i<n;i++)

        {

            fin>>aux.x>>aux.y;

            a.push_back(aux);



        }

        fin.close();

}

long long sqr(int a)

{

    return 1LL*a*a;

}

 long long distanta(const punct a, const punct b){

    return sqr(a.x-b.x)+sqr(a.y-b.y);

}

class compar1

{

public:

    bool operator() (const punct &a,const punct &b)

    {

        return a.y<b.y;

    }

};

class compar

{

    public:

    bool operator ()(const punct &a,const punct &b)const

    {

        if(a.x<b.x)

            return 1;

        else

            if(a.x==b.x)

                if(a.y<b.y){

                    return 1;

                }

                else{

                    return 0;

                }

            else

                return 0;

    }

};

long long minn(long long d1,long long d2)

{

    if(d1<d2)

        return d1;

    else

        return d2;

}



void interclasare(vector<punct> &a,vector<punct> &b,int n,int m,int mid,int dreapta,long long dist)

{

    int i=n,j=mid+1;

    vector<punct> c;

    while(i<=mid && j<=m)

    {

        if(a[i].y<=a[j].y)

        {

                if(dreapta-a[i].x<=dist)

                    b.push_back(a[i]);

                    c.push_back(a[i]);

                i++;

        }

        else

        {

             if(dreapta-a[j].x<=dist)

                    b.push_back(a[j]);

                c.push_back(a[j]);

                j++;

        }



    }

    while(i<=mid)

    {

       if(dreapta-a[i].x<=dist)

                b.push_back(a[i]);

                c.push_back(a[i]);

                i++;

    }

    while(j<=m)

    {

        if(dreapta-a[j].x<=dist)

                b.push_back(a[j]);

                c.push_back(a[j]);

                j++;

    }

    i=n;

    j=0;

    while(j<c.size())

    {

        a[i]=c[j];

        j++;

        i++;

    }



}



long long rezolva(vector<punct> &a,vector <punct>&b,int i,int j)

{

    if(i>=j)

        return 2e81;



    if(j-i==1){

        if(a[i].y>a[i+1].y)

            swap(a[i],a[i+1]);

        return distanta(a[i],a[i+1]);

    }

    int mid=(i+j)/2;

    long long d1=rezolva(a,b,i,mid);

    long long d2=rezolva(a,b,mid+1,j);

    long long d=minn(d1,d2);



    int dr=a[mid].x;

   interclasare(a,b,i,j,mid,dr,d);



    for(int k=0;k<b.size()-1;k++)

        for(int l=k+1;l<=k+8 && l<b.size();l++)

              if(d>distanta(b[k],b[l]) ){

                    d=distanta(b[k],b[l]);

                   }



    b.clear();



    return d;



}

int main()

{



    int n;

    vector<punct> a,b;

   citire(n,a,b);

   compar c;



    sort(a.begin(),a.end(),c);

    int i;

    ofstream fout("cmap.out");

   fout<<fixed<<setprecision(6)<< sqrt(rezolva(a,b,0,n-1));

    return 0;

}
