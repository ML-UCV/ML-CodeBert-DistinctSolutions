#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>


using namespace std;



struct punct{

 int x, y;

} *X, *Y, *LY;

int n;



bool cmpX(punct a, punct b){

 return a.x<b.x;

}



bool cmpY(punct a, punct b){

 return a.y<b.y;

}



long long dist(punct a, punct b){

   return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y);

}





long long divide(int st, int dr, punct y[], int nr){

 int i, j, noSt=0, noDr=0, k=0;

 long long minDr, minSt, minD, minDSqrt;

 punct *DY=new punct[nr+1];

 punct *SY=new punct[nr+1];



 if(dr-st==1) return dist(X[dr],X[st]);

 if(dr-st==2) return min(dist(X[dr],X[dr+1]),min(dist(X[dr],X[st]),dist(X[dr+1],X[st])));

 int mij=(st+dr)/2;



 for(i=0;i<=nr;i++)

    if(y[i].x<X[mij].x){

       SY[noSt].x=y[i].x; SY[noSt].y=y[i].y;

       noSt++;

    }

    else{

       DY[noDr].x=y[i].x; DY[noDr].y=y[i].y;

       noDr++;

    }



 minSt=divide(st,mij,SY,noSt-1); minDr=divide(mij+1,dr,DY,noDr-1);

 minD=min(minSt,minDr);

 minDSqrt=ceil(sqrt(minD));





 for(i=0;i<=nr;i++)

    if( abs( y[i].x - X[mij].x ) <= minDSqrt ) {

         LY[k].x=y[i].x; LY[k].y=y[i].y;

         k++;

    }



 for(i=0;i<k;i++)

   for(j=i+1; j<=(i+7) && j<k; j++)

      minD= min( minD, dist(LY[i],LY[j]) );



 delete [] DY; delete [] SY;

 return minD;

}





int main(){

 ifstream in("cmap.in");

 ofstream out("cmap.out");



 int i;

 in>>n;

 X=new punct[n+1]; Y=new punct[n+1]; LY=new punct[n+1];



 for(i=0;i<n;i++){

  in>>X[i].x>>X[i].y;

  Y[i].x=X[i].x; Y[i].y=X[i].y;

 }



 sort(X,X+n,cmpX);

 sort(Y,Y+n,cmpY);



 out<<fixed<<setprecision(6)<<sqrt(divide(0,n-1,Y,n-1));



 delete [] X; delete [] Y; delete [] LY;

 in.close(); out.close();

 return 0;

}
