#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");





vector<int> adiacenta[100009];

vector<int> transpusa[100009];

vector<int> componente_conexe[100009];

int vizitat [100009];

stack<int> stiva;





int nr_comp;



void DFS(int nod)

{

   vizitat[nod] = 1;

    for(size_t i=0; i<adiacenta[nod].size(); i++) {

        if(!vizitat[adiacenta[nod][i]])

            DFS(adiacenta[nod][i]);

    }



    stiva.push(nod);



}





void DFS2(int nod)

{

   vizitat[nod] = 2;

   componente_conexe[nr_comp].push_back(nod);



    for(size_t i=0; i<transpusa[nod].size();i++) {

        if(vizitat[transpusa[nod][i]] == 1)

            DFS2(transpusa[nod][i]);

    }





}



int main()

{

    int N,M,x,y;

    in>>N>>M;

     for(int i =1; i <=M ;i++)

    {

        in>>x>>y;

        adiacenta[x].push_back(y);

        transpusa[y].push_back(x);



    }







    for(int i = 1; i <= N; i++)

    {

        if(!vizitat[i])

            DFS(i);

    }







    while(!stiva.empty())

    {

        int nod = stiva.top();

        if(vizitat[nod] == 1)

        {

            nr_comp ++;

            DFS2(nod);

        }



        stiva.pop();

    }





    out<<nr_comp<<"\n";







    for(int i = 1; i <= nr_comp; i++)

    {

        for(size_t j = 0; j < componente_conexe[i].size(); j++)

            out<<componente_conexe[i][j]<<" ";



        out<<"\n";

    }



    return 0;

}
