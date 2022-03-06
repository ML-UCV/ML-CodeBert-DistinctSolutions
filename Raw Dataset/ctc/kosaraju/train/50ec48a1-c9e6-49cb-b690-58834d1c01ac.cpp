#include <bits/stdc++.h>






using namespace std;



FILE *fin = fopen("ctc.in" , "r");

FILE *fout = fopen("ctc.out" , "w");



vector <int> muchii1[100005] , muchii2[100005] , H;

int n , m;

bool viz[100005];



vector <vector <int> > ans;



void DFS1(int nod)

{

    viz[nod] = 1;

    for(int i = 0 ; i < muchii1[nod].size() ; i ++)

        if(!viz[muchii1[nod][i]])

            DFS1(muchii1[nod][i]);

    H.push_back(nod);

}



void DFS2(int nod)

{

    viz[nod] = 1;

    for(int i = 0 ; i < muchii2[nod].size() ; i ++)

        if(!viz[muchii2[nod][i]])

            DFS2(muchii2[nod][i]);

    ans.back().push_back(nod);

}



int main()

{

    fscanf(fin , "%d%d" , &n , &m);

    for(int i = 1 ; i <= m ; i ++)

    {

        int x , y;

        fscanf(fin , "%d%d" , &x , &y);

        muchii1[x].push_back(y);

        muchii2[y].push_back(x);

    }

    for(int i = 1 ; i <= n ; i ++)

        if(!viz[i])

            DFS1(i);

    memset(viz , 0 , sizeof(viz));

    for(int i = H.size() - 1 ; i >= 0 ; i --)

        if(!viz[H[i]])

        {

            ans.push_back(vector <int> ());

            DFS2(H[i]);

        }

    fprintf(fout , "%d\n" , ans.size());

    for(int i = 0 ; i < ans.size() ; i ++)

    {

        for(int j = 0 ; j < ans[i].size() ; j ++)

            fprintf(fout , "%d " , ans[i][j]);

        fprintf(fout , "\n");

    }

    return 0;

}
