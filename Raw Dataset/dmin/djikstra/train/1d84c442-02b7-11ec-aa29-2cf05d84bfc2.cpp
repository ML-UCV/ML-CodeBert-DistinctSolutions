#include<fstream>
#include<vector>
#include<math.h>
using namespace std;
ifstream f("dmin.in");

ofstream g("dmin.out");





int Poz[2100],Fr[2100],Nr_drum[2100];

int last,n,m,i;

double Drum_min[2100];





struct heap{

 double val;

 int poz;

}Heap[2100];



struct nod{

 int varf;

 double dist;

};



vector<nod> L[2100];



inline void read(){



 nod nod2;

 int nod1,x;



 f>>n>>m;



 for(int i=1;i<=m;++i){

  f>>nod1>>nod2.varf>>x;

  nod2.dist=log(x);

  L[nod1].push_back(nod2);

 }



}



inline void initializare(){

 for(int i=1;i<=n;i++){

  Heap[++last].val=2000000000;

  Heap[last].poz=i;

  Poz[i]=i;

 }

 Heap[1].val=0;

 Nr_drum[1]=1;

}



inline int tata(int x){

 return x/2;

}



inline int left_son(int x){

 return 2*x;

}



inline int right_son(int x){

 return 2*x+1;

}



inline void heap_down(int x){



 int aux2,sec;heap aux1;

 int l1,l2;

 while(x!=last){

  l1=left_son(x);

  l2=right_son(x);

  if(l1<=last&&l2<=last){

   if(Heap[l1].val<Heap[l2].val)

    sec=l1;

   else

    sec=l2;

  }

  else{

   if(l1<=last)

    sec=l1;

   else{

    if(l1<=last)

     sec=l2;

    else

     sec=x;

   }

  }

  if(Heap[sec].val>=Heap[x].val)

   break;



  aux2=Poz[Heap[sec].poz];

  Poz[Heap[sec].poz]=Poz[Heap[x].poz];

  Poz[Heap[x].poz]=aux2;

  aux1=Heap[sec];

  Heap[sec]=Heap[x];

  Heap[x]=aux1;

  x=sec;



 }





}



inline void heap_up(int x){

 heap aux1;int aux2,T;

 while(Heap[T=tata(x)].val>Heap[x].val&&x!=1){

  aux2=Poz[Heap[T].poz];

  Poz[Heap[T].poz]=Poz[Heap[x].poz];

  Poz[Heap[x].poz]=aux2;

  aux1=Heap[T];

  Heap[T]=Heap[x];

  Heap[x]=aux1;

  x=T;

 }

}



inline void update(int x){

 heap_up(x);

 heap_down(x);

}



inline int pop(){

 int nod1=Heap[1].poz;



 Drum_min[nod1]=Heap[1].val;



 Poz[Heap[last].poz]=1;



 Heap[1]=Heap[last--];



 update(1);



 return nod1;

}



inline void update_drum(int x){

 int poz;

 for(unsigned int i=0;i<L[x].size();i++){

  poz=Poz[L[x][i].varf];

  if(Heap[poz].val>Drum_min[x]+L[x][i].dist+0.000000001&&Fr[L[x][i].varf]==0){

   Heap[poz].val=Drum_min[x]+L[x][i].dist;

   Nr_drum[L[x][i].varf]=Nr_drum[x];

   update(poz);

  }

  else if(Drum_min[x]+L[x][i].dist-Heap[poz].val<=0.000000001){

   Nr_drum[L[x][i].varf]+=Nr_drum[x];

   if(Nr_drum[L[x][i].varf]>=104659)

    Nr_drum[L[x][i].varf]-=104659;

  }

 }



}



inline void dijkstra(){



 int x;



 while(last!=0){

  x=pop();

  Fr[x]=1;

  update_drum(x);

 }



}



int main(){



 read();



 initializare();



 dijkstra();



 for(i=2;i<=n;i++)

  g<<Nr_drum[i]<<" ";



 f.close();

 g.close();



 return 0;

}
