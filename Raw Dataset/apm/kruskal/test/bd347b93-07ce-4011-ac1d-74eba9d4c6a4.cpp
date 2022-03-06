#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



const int maxn = 200005;



int UF_array[maxn], x[maxn], y[maxn], c[maxn];

int n, m, rez, ind[maxn];

vector<int> v_rez;



void afisare_UF_array(){

 fout<<"\n------------------------------------------------------------\n";

 for (int i=1; i<=n; i++)

 fout<<UF_array[i]<<" ";

 fout<<"\n------------------------------------------------------------\n";

}



bool my_cmp(int i,int j){

 return(c[i] < c[j]);

}



int findd(int i){

 if (UF_array[i] == i)

        return i;

 UF_array[i] = findd(UF_array[i]);

 return UF_array[i];

}



void reuniune(int i,int j){

 UF_array[findd(i)] = findd(j);

}



int main()

{

    int i;

 fin>>n>>m;

 for(i=1; i<=m; i++){

  fin>>x[i]>>y[i]>>c[i];

  ind[i] = i;

 }

 for(i=1; i<=n; i++)

        UF_array[i] = i;



    sort(ind+1, ind+m+1, my_cmp);



 for(i=1; i<=m; i++){







  if (findd(x[ind[i]]) != findd(y[ind[i]])){

   rez += c[ind[i]];

            reuniune(x[ind[i]],y[ind[i]]);

   v_rez.push_back(ind[i]);

  }

 }

 fout<<rez<<"\n"<<n-1<<"\n";

 for(i=0; i<n-1; i++)

  fout<<y[v_rez[i]]<<" "<<x[v_rez[i]]<<"\n";



 return 0;

}
