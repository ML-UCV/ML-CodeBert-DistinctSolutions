#include<stdio.h>
#include<vector>
#include<limits.h>
#include<math.h>
#include<set>
#include<algorithm>




using namespace std;







int N;



struct pair_compare {

    bool operator() (const std::pair<int,int> & p1, const std::pair<int,int> & p2) const {

  if(p1.first == p2.first)

   return (p1.second < p2.second);

  else

   return (p1.first < p2.first);

    }

};



vector<pair<int,int>> P;



long long findpoints(int left,int right){

 long long dist=LLONG_MAX,dx,dy;

 if((right-left)<=2){

  for(int i=left;i<right;i++){

   for(int j=i+1;j<=right;j++){

    dx=P[i].first-P[j].first; dx*=dx;

    dy=P[i].second-P[j].second; dy*=dy;

    if((dx+dy)<dist){

     dist=dx+dy;

    }

   }

  }

  return dist;

 }

 int mid=(left+right)/2;

 long long d1=findpoints(left,mid);

 long long d2=findpoints(mid+1,right);

 dist=(d1<d2) ? d1 : d2;



 vector<pair<int,int>> Q;

 for(int i=left;i<=right;i++){

  dx=P[i].first-P[mid].first; dx*=dx;

  if(dx<dist)

   Q.push_back(make_pair(P[i].second,i));

 }



 sort(Q.begin(),Q.end(),pair_compare());



 int l=Q.size();

 for(int i=0;i<l;i++){

  for(int j=i+1;j<l && j<=(i+7);j++){

   if(Q[i].second<=mid && Q[j].second<=mid){

    continue;

   }

   if(Q[i].second>mid && Q[j].second>mid){

    continue;

   }

   dx=P[Q[i].second].first-P[Q[j].second].first; dx*=dx;

   dy=P[Q[i].second].second-P[Q[j].second].second; dy*=dy;

   if((dx+dy)<dist){

    dist=dx+dy;

   }

  }

 }



 return dist;

}





int main(){



 freopen("cmap.in","rt",stdin);



 freopen("cmap.out","wt",stdout);



 scanf("%d",&N);



 int x,y;

 for(int i=0;i<N;i++){

  scanf("%d %d",&x,&y);

  P.push_back(make_pair(x,y));

 }



 sort(P.begin(),P.end(),pair_compare());

 long long rez=findpoints(0,N-1);

 printf("%f\n",sqrt((double)rez));



 return 0;

}
