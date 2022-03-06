#include <iostream>
#include <fstream>
#include <algorithm>




using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



struct edge{

    int nod1, nod2, cost;

}v[400005];



int cmp(edge a, edge b){

    return a.cost < b.cost;

}



int n, m, r1, r2, suma;

int t[200005], soll;

pair<int, int> sol[200005];



int r(int nod){

    while(t[nod] > 0)

        nod=t[nod];

    return nod;

}



int main (){

    fin>>n>>m;

    for(int i=1; i<=m; i++)

        fin>>v[i].nod1>>v[i].nod2>>v[i].cost;

    sort(v+1, v+m+1, cmp);



    for(int i=1; i<=n; i++)

        t[i]=-1;



    for(int i=1; i<=m; i++){

        r1=r(v[i].nod1);

        r2=r(v[i].nod2);



        if(r1 != r2){



            if(-t[r1] > -t[r2]){

                t[r1]+=t[r2];

                t[r2]=r1;

            }else{

                t[r2]+=t[r1];

                t[r1]=r2;

            }



            suma+=v[i].cost;

            sol[++soll]=make_pair(v[i].nod1, v[i].nod2);

            if(soll == n-1)

                break;

        }

    }



    fout<<suma<<"\n"<<soll<<"\n";

    for(int i=1; i<=soll; i++)

        fout<<sol[i].first<<" "<<sol[i].second<<"\n";

    return 0;

}
