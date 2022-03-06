#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");







int n,m,x,y,c;





vector <tuple < int ,int , int > > Muchii;

vector < pair <int, int > > muchii_sol;

bool cmp(tuple < int ,int , int > st, tuple < int ,int , int > dr)

{

    if(get<2>(st) < get<2>(dr))

        return 1;

    return 0;

}



 void Citire()

 {

     fin>>n>>m;

     for(int i=1;i<=m;i++)

     {

         fin>>x>>y>>c;

         Muchii.push_back(make_tuple(x,y,c));

     }







      sort(Muchii.begin(),Muchii.end(),cmp);

 }



int sol1=0;

int tata[200001],h[200001];





int Find(int x)

{

    int r=x,y;

    while(tata[r])

    {

        r=tata[r];



    }



    while(tata[x])

    {

        y=tata[x];

        tata[x]=r;

        x=y;

    }





    return r;



}



void Union(int x,int y)

{

    if(h[x]>h[y])

    {

        tata[y]=x;



    }

    else

    {

        tata[x]=y;

        if(h[x]==h[y])

            h[y]++;



    }





}
void Kruskal()

{

    for(int i=0;i<m;i++)

   {

       int A=Find(get<0>(Muchii[i]));

       int B=Find(get<1>(Muchii[i]));



       if(A!=B)

        {Union(A,B);

         sol1+=get<2>(Muchii[i]);

       muchii_sol.push_back(make_pair(get<1>(Muchii[i]),get<0>(Muchii[i])));

        }

   }





}

void Afisare()

{



    fout<<sol1<<endl;

    fout<<muchii_sol.size()<<endl;

    for(int i=0;i<muchii_sol.size();i++)

        fout<<muchii_sol[i].first<<" "<<muchii_sol[i].second<<"\n";





}





int main()

{



      Citire();

      Kruskal();

      Afisare();





    return 0;

}
