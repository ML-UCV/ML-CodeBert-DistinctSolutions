#include <bits/stdc++.h>


using namespace std;



vector <int> L[210],ans;

int level[210],low[210],viz[210],sol[210];

deque <int> s;

int n,m,i,x,y,tip,idx,nx,ny;



void dfs (int nod){



    level[nod] = low[nod] = ++idx;

    viz[nod] = 1;

    s.push_back(nod);

    for (auto vecin : L[nod]){

        if (!level[vecin]){

            dfs (vecin);

            low[nod] = min (low[nod],low[vecin]);

        } else {

            if (viz[vecin])

                low[nod] = min (low[nod],low[vecin]);

        }

    }

    if (low[nod] == level[nod]){

        int x;

        do{

            x = s.back();

            int nx;

            if (x <= n)

                nx = x + n;

            else nx = x - n;



            if (sol[x] == 0){

                sol[x] = 1;

                sol[nx] = -1;

            }



            s.pop_back();

            viz[x] = 0;



        } while (x != nod);



    }

}



int main (){



    ifstream fin ("party.in");

    ofstream fout ("party.out");



    fin>>n>>m;

    for (i=1;i<=m;i++){

        fin>>x>>y>>tip;

        if (tip == 0){

             nx = x + n;

             ny = y + n;

        } else {

            if (tip == 1){

                nx = x + n;

                ny = y;

                y += n;

            } else {

                if (tip == 2){

                    nx = x;

                    x += n;

                    ny = y + n;

                } else {

                    nx = x;

                    x += n;

                    ny = y;

                    y += n;

                }}}



        L[nx].push_back(y);

        L[ny].push_back(x);

    }





    for (i=1;i<=2*n;i++){

        if (!viz[i])

            dfs (i);

    }



    for (i=1;i<=n;i++)

        if (sol[i] == 1)

            ans.push_back(i);



    sort (ans.begin(),ans.end());

    fout<<ans.size()<<"\n";

    for (auto it : ans)

        fout<<it<<"\n";





    return 0;

}
