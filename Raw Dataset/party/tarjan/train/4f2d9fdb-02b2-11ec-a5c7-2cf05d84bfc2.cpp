#include <bits/stdc++.h>


using namespace std;

int n , sol , g , elem;

vector <int> v[200010];

set <int> sl;

int niv[200010] , low[200010], s[200010] , f[200010] , val[200010];

int invers (int x){

    if (x <= n)

        return x + n;

    else return x - n;

}

void dfs (int nod){

    int vecin,i;

    g++;

    niv[nod]=g;

    low[nod]=g;

    s[++elem]=nod;

    f[nod]=1;

    for (i=0;i<v[nod].size();i++){

        vecin=v[nod][i];

        if (!niv[vecin]){

            dfs(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else if (f[vecin])

            low[nod]=min(low[nod],low[vecin]);

    }

    if (low[nod]==niv[nod]){

        sl.clear();

        do{



            sl.insert(s[elem]);

            f[s[elem]]=0;



            if (sl.find(invers(s[elem])) != sl.end()){

                sol = -1;

            }



            if (val[s[elem]] == -1){

                val[s[elem]] = 1;

                val[invers(s[elem])] = 0;

            }



            elem--;



        } while (s[elem+1]!=nod);



    }

}

int main()

{

    FILE *fin = fopen ("party.in","r");

    FILE *fout = fopen ("party.out","w");

    int m,i,x,y,op;

    fscanf (fin,"%d%d",&n,&m);

    for (i=1;i<=m;i++){

        fscanf (fin,"%d%d%d",&x,&y,&op);

        if (op == 1)

            y = invers(y);

        else if (op == 2)

            x = invers(x);

        else if (op == 3){

            x = invers(x);

            y = invers(y);

        }

        v[invers(x)].push_back(y);

        v[invers(y)].push_back(x);



    }

    for (i=1;i<=2*n;i++)

        val[i] = -1;

    for (i=1;i<=n;i++){

        if (!niv[i])

            dfs (i);

    }

    int nr = 0;

    for (i=1;i<=n;i++)

        nr+=val[i];

    fprintf (fout,"%d\n",nr);

    for (i=1;i<=n;i++)

        if (val[i])

            fprintf (fout,"%d\n",i);

    return 0;

}
