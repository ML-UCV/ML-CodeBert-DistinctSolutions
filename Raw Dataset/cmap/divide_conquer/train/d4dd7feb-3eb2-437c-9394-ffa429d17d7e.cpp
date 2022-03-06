#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

const int N=1e5+5;

struct points{

  int x,y;

};

bool cmpx(points a,points b){

  if(a.x==b.x)

    return a.y<b.y;

  return a.x<b.x;

}

bool cmpy(points a,points b){

  if(a.y==b.y)

    return a.x<b.x;

  return a.y<b.y;

}

double minn(double a,double b){

  if(a<b)

    return a;

  return b;

}

points px[N];

points py[N];

double dist(points a,points b){

  double distsq=(double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y);

  distsq=(double)sqrt(distsq);

  return distsq;

}

double abss(double x){

  if(x>=0)

    return x;

  return -x;

}

int init;

points aux[N];

vector <points> strip;

double FindMinDist(int st,int dr,int n){

  double mindist;

  if(n<=3){

    mindist=dist(px[st],px[st+1]);

    for(int i=st;i<=dr;i++){

      py[i]=px[i];

      for(int j=i+1;j<=dr;j++){

        mindist=minn(mindist,dist(px[i],px[j]));

      }

    }

    sort(py+st,py+dr+1,cmpy);

    return mindist;

  }

  double mindist1,mindist2;

  int mid=st+n/2-1;

  mindist1=FindMinDist(st,mid,n/2);

  mindist2=FindMinDist(mid+1,dr,n-n/2);

  mindist=minn(mindist1,mindist2);

  int i=st,j1=st,j2=mid+1;

  while(i<=dr){

    if(j1<=mid && (py[j1].y<py[j2].y || j2>dr)){

      aux[i]=py[j1++];

    }

    else{

      aux[i]=py[j2++];

    }

    i++;

  }

  for(int i=st;i<=dr;i++){

    py[i]=aux[i];

  }

  int nrs=0;

  strip.clear();

  strip.push_back({0,0});

  for(int i=st;i<=dr;i++){

    if(abss(((double)px[mid].x-py[i].x))<=mindist){

      strip.push_back(py[i]);

      nrs++;

    }

  }

  for(int i=1;i<=nrs;i++){

    int j=i+1;

    while(j<=nrs && strip[j].y-strip[i].y<=mindist){

      mindist=minn(mindist,dist(strip[j],strip[i]));

      j++;

    }

  }

  return mindist;

}

int main()

{

    int n;

    fin>>n;



    init=n;

    for(int i=1;i<=n;i++){

      fin>>px[i].x>>px[i].y;



    }

    sort(px+1,px+n+1,cmpx);



    fout<<setprecision(100)<<FindMinDist(1,n,n);

    return 0;

}
