#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;





struct punct{

double x,y;

};







typedef double ull;



punct p[100099],aux[100099],inter[100099];



ull dist(punct a,punct b){

    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);

}



bool cmp(punct a,punct b){return a.x<b.x;}





double minDist(int st,int dr){

    if(dr-st+1 ==3){

        if(p[st].y > p[st+1].y)swap(p[st],p[st+1]);

        if(p[st+1].y > p[st+2].y)swap(p[st+1],p[st+2]);

        if(p[st].y > p[st+1].y)swap(p[st],p[st+1]);



        return min(dist(p[st],p[st+1]),min(dist(p[st+1],p[st+2]),dist(p[st],p[st+2])));

    }if(dr-st+1 ==2){

        if(p[st].y>p[st+1].y)swap(p[st],p[st+1]);

        return dist(p[st],p[st+1]);

    }else{



    int mid = (st+dr)/2;

    double centru=p[mid].x;

    ull delta = min(minDist(st,mid),minDist(mid+1,dr));

    int r= 0;

    int radDelt=sqrt(delta);





    int i,j,k; i=k=st; j=mid+1;

    while(i<=mid && j<=dr){

        if(p[i].y < p[j].y)aux[k++]=p[i++];

            else aux[k++]=p[j++];

    }

    while(i<=mid)aux[k++]=p[i++];

    while(j<=dr) aux[k++]=p[j++];



    for(i=st;i<=dr;i++){

            p[i]=aux[i];

            if(p[i].x-centru <= radDelt && p[i].x-centru >= -radDelt)

                inter[++r]=p[i];

    }



    for(i=1;i<=r;i++)

    { j= min(r,i+7);

            for(k=i+1;k<=j;k++){

                delta= min(delta,dist(inter[i],inter[k]));

            }

    }

    return delta;

    }





}





int main(){

ifstream cin("cmap.in");

  ofstream cout("cmap.out");

    int n,i;

    cin>>n;

    for(i=1;i<=n;i++)cin>>p[i].x>>p[i].y;

   sort(p+1,p+n+1,cmp);

    cout<<setprecision(6)<<fixed<<sqrt(minDist(1,n));





}
