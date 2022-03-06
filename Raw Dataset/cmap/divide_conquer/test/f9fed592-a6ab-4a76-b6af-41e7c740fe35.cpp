#include <iostream>
#include <fstream>#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct punct

{

    int x=0,y=0;

};

double distanta(punct a,punct b)

{

    double x = a.x - b.x;

    double y = a.y - b.y;

    double dist;



    dist = pow(x, 2) + pow(y, 2);

    dist = sqrt(dist);



    return dist;



}

bool cmpX(const punct& a,const punct& b)

{

    return a.x<b.x;

}

bool cmpY(const punct& a,const punct& b)

{

    return a.y<b.y;

}



double dist_min(int st,int dr,vector<punct> &P,vector<punct> &Y)

{

    if((dr-st)==1)

    {

        return 2147483647;
    }

    else if((dr-st)==2)

    {

        if(Y[st].y>Y[st+1].y)

             swap(Y[st],Y[st+1]);

        return distanta(P[0],P[1]);





    }

    int d;

    double min_st,min_dr,min_p;



    d=(st+dr)/2;

    min_st=dist_min(st,d,P,Y);

    min_dr=dist_min(d,dr,P,Y);

    min_p=min(min_st,min_dr);

    vector <punct> aux(dr-st);

    merge(Y.begin()+st,Y.begin()+d,Y.begin()+d,Y.begin()+dr,aux.begin(),cmpY);

    copy(aux.begin(),aux.begin()+(dr-st),Y.begin()+st);

    vector <punct> b;

    for (int i = st; i < dr; ++i)

    {

        if (abs(Y[i].x - P[d].x) <= min_p)

            b.push_back(Y[i]);

    }





    double min_t = min_p;

    for (int i = 0; i<b.size(); ++i)

        for (int j = i + 1; j < b.size() && b[j].y - b[i].y <= min_p; ++j)

        {

            double c = distanta(b[i], b[j]);

            if (c < min_t)

            {

                min_t= c;

            }

        }



    return min_t;
}



int main()

{

    int i,n;

    f>>n;

    vector<punct> P(n);

    for(i=0; i<n; i++)

    {

        f>>P[i].x;

        f>>P[i].y;

    }

    sort(P.begin(),P.end(),cmpX);

    vector <punct> Y=P;

     g << fixed;

    g << setprecision(6) <<dist_min(0,P.size(),P,Y)<<endl;



    return 0;

}
