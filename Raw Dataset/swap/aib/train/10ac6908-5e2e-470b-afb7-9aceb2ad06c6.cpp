#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



char c1[50001],c2[50001];

int n,f1[30],f2[30],i,v[50001];

int a[30][50001];

long long sol;



int q(int p){

    int sol=0;

    for(;p;p-=(p&-p))

        sol+=v[p];



    return sol;

}



void u(int p){

    for(;p<=n;p+=(p&-p))

        v[p]++;

}



int main(){

    fin>>c1+1>>c2+1;

    n=strlen(c1+1);



    for(i=1;i<=n;i++){

        f1[ c1[i]-'a'+1 ]++;

        f2[ c2[i]-'a'+1 ]++;



        a[c1[i]-'a'+1][ f1[ c1[i]-'a'+1 ] ]=i;

    }



    for(i=1;i<=26;i++){

        if(f1[i]!=f2[i]){

            fout<<-1;

            return 0;

        }

        f2[i]=0;

    }



    for(i=1;i<=n;i++){

        f2[c2[i]-'a'+1]++;

        sol+=i-1-q(a[c2[i]-'a'+1][f2[c2[i]-'a'+1]]);

        u(a[c2[i]-'a'+1][f2[c2[i]-'a'+1]]);

    }



    fout<<sol;



    return 0;

}
