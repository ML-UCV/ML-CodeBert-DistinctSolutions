#include <bits/stdc++.h>




using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



struct node{

    int v;

    node *next;

}*L[100005], *LT[100005], *cpt[100005];



int N,M,comp;

stack <int> finalizare;

bool parcurs1[100005], parcurs2[100005];



void add(int x, int y, node *L[]){

    node *p = new node;

    p->v = y; p->next = L[x];

    L[x] = p;

}



void citire(){

    f>>N>>M;

    int x,y;

    for(int i=1; i<=M; i++){

        f>>x>>y;

        add(x,y,L);

        add(y,x,LT);

    }

}



void dfs1(int i, bool parcurs[], node *L[]){

    parcurs[i] = 1;

    for(node *p = L[i]; p != nullptr; p = p->next)

        if(parcurs[p->v] == 0)

            dfs1(p->v, parcurs, L);

    finalizare.push(i);

}



void dfs2(int i, bool parcurs[], node *L[]){

    parcurs[i] = 1;

    for(node *p = L[i]; p != nullptr; p = p->next)

        if(parcurs[p->v] == 0)

            dfs2(p->v, parcurs, L);

    add(comp,i,cpt);

}



void tareConex(){

    while(!finalizare.empty()){

        if(parcurs2[finalizare.top()] == 0){

            dfs2(finalizare.top(), parcurs2, LT);

            comp++;

        }

        finalizare.pop();

    }

    g<<comp<<"\n";

    for(int i=0; i<comp; i++){

        while(cpt[i] != nullptr){

            g<<cpt[i]->v<<" ";

            cpt[i] = cpt[i]->next;

        }

        g<<"\n";

    }

}



int main(){

   citire();

   for(int i=1; i<=N; i++)

        if(parcurs1[i] == 0)

            dfs1(i, parcurs1, L);

   tareConex();

}
