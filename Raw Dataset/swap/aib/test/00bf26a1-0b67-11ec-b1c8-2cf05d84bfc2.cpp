#include <fstream>
#include <queue>
#include <cstring>


using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");





int n,m,ok,i,x,v[50001],aib[50001],f[50001];

int sol;

char a[50001],b[50001];

queue <int> L[27];



void update(int p){

    for(int i=p;i<=n;i+=(i&-i))

        aib[i]++;

}

int query(int p){

    int sol=0;

    for(int i=p;i>=1;i-=(i&-i))

        sol += aib[i];

    return sol;

}



int main (){



    fin>>a+1>>b+1;
    n = strlen (b+1);

    for (i=1;i<=n;i++)

        L[b[i]-'a'+1].push (i);



    for (i=1;i<=n;i++){

        if (L[a[i]-'a'+1].size () == 0){



            fout<<-1;

            return 0;

        }

        x = L[a[i]-'a'+1].front();

        sol += x - 1- query (x);

        update (x);

        L[a[i]-'a'+1].pop();

    }





    fout<<sol;



    return 0;

}
