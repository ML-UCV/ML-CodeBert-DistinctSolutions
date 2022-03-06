#include<stdio.h>
#include<vector>
#include<math.h>


using namespace std;
FILE*f=fopen("dmin.in","r");

FILE*g=fopen("dmin.out","w");



int n,m,i,j,x,y,cst,H[1505],Poz[1505],Nr[1505],nod,nodvcn,L,Viz[1505],nodbst;

vector< pair<int,double> >G[1505]; double lg,D[1505],cstvcn,bst;



inline void citire () {



 fscanf(f,"%d %d",&n,&m);



 for ( i = 1 ; i <= m ; ++i ){

  fscanf(f,"%d %d %d",&x,&y,&cst);

  lg = log(cst);

  G[x].push_back(make_pair(y,lg));

  G[y].push_back(make_pair(x,lg));

 }

}



inline void swap ( int &a, int &b ){

 int aux = a;

 a = b;

 b = aux;

}



inline double aabs ( double j ){

 if ( j < 0 )

  return -j;

 return j;

}





inline void urca ( int poz ){



 while ( poz && D[H[poz>>1]] > D[H[poz]] ){

  swap(H[poz>>1],H[poz]);

  swap(Poz[H[poz>>1]],Poz[H[poz]]);

  poz = poz >> 1;

 }

}



inline void coboara ( int x ){

 int y = (1<<29);



 while ( x != y ){

  y = x;

  if ( (y<<1) <= L && D[H[y<<1]] < D[H[x]] ) x = y << 1;

  if ( (y<<1) + 1 <= L && D[H[(y<<1)+1]] < D[H[x]] ) x = (y<<1) + 1;

  swap(H[x],H[y]);

  swap(Poz[H[x]],Poz[H[y]]);

 }

}





inline void insert_heap( int nod ){

 H[++L] = nod;

 Poz[nod] = L;

 urca(L);

}



inline int delete_first( ){

 int nod = H[1];

 swap(H[1],H[L--]);

 coboara(1);

 Poz[nod] = 0;

 return nod;

}





inline void dijkstra () {



 for ( Nr[1] = 1, i = 2 ; i <= n ; ++i ){

  D[i] = (1<<29);

 }
 for ( i = 1 ; i <= n ; ++i ){

  bst = (1<<29);

  for ( j = 1 ; j <= n ; ++j ){

   if ( !Viz[j] && D[j] < bst )

    nodbst = j,bst = D[j];

  }

  Viz[nodbst] = 1; nod = nodbst;

  for ( j = 0 ; j < G[nodbst].size() ; ++j ){

   nodvcn = G[nod][j].first; cstvcn = G[nod][j].second;



   if ( aabs(D[nod] + cstvcn - D[nodvcn] ) < 1e-10 ){

    Nr[nodvcn] += Nr[nod];

    if ( Nr[nodvcn] >= 104659 )

     Nr[nodvcn] -= 104659;

   }

   else{

    if ( D[nod] + cstvcn - D[nodvcn] < 1e-10 ){

     D[nodvcn] = D[nod] + cstvcn;

     Nr[nodvcn] = Nr[nod];

    }

   }



  }

 }



 for ( i = 2 ; i <= n ; ++i ){

  fprintf(g,"%d ",Nr[i]);

 }

}





int main () {



 citire();



 dijkstra();



 fclose(f);

 fclose(g);



 return 0;

}
