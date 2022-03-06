#include <bits/stdc++.h>
using namespace std;



const int nmax = 1510;



struct el{

int a;

double cost;



 el(int aa,double c){

  a = aa;

  cost = c;

 }

};

vector<el>G[nmax];

queue<int>q;

int N,M,nr[nmax];

double dp[nmax];

bool ok[nmax];



inline void BFS(){

  int nod;



  for(int i = 2; i <= N; ++i)dp[i] = 0x3f3f3f3f;



  nr[1] = 1;

  q.push(1);

  ok[1] = true;



  while(!q.empty()){

    nod = q.front();

    ok[nod] = false;

    q.pop();



    for(auto it: G[nod]){

       if(dp[it.a]-it.cost-dp[nod] >= 1e-10){



          dp[it.a] = dp[nod] + it.cost;

          nr[it.a] = nr[nod];

          if(!ok[it.a]){

            ok[it.a] = true;

            q.push(it.a);

          }

       }

      else if(abs(dp[nod]-dp[it.a]+it.cost) < 1e-10){

        nr[it.a]+=nr[nod];

        if(nr[it.a]>=104659)nr[it.a]-=104659;

      }

    }

  }



}

int main(){

    int i,x,y,c;

    freopen ("dmin.in","r",stdin);

    freopen ("dmin.out","w",stdout);

    scanf("%d %d\n",&N,&M);

    for(i = 1; i <= M; ++i){

        scanf("%d %d %d\n",&x,&y,&c);

        G[x].push_back(el(y,log10(c)));

        G[y].push_back(el(x,log10(c)));

    }

    BFS();



    for(i = 2; i <= N; ++i)

        cout << nr[i] <<' ';



    return 0;

}
