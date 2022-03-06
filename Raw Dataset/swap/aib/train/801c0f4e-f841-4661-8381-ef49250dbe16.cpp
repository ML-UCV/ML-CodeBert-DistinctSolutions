#include<fstream>
#include<cstring>
#include<queue>
using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

int i,n,sol,k;

int v[50005],aib[50005];

char c[50005],d[50005];

deque<int>H[27];

void update(int p){

    for(;p<=n;p+=(p&-p)){

        aib[p]++;

    }

}

int querry(int p){

    int r=0;

    for(;p;p-=(p&-p)){

        r+=aib[p];

    }

    return r;

}

int main(){

    fin>>c+1>>d+1;

    n=strlen(c+1);

    for(i=1;c[i]!=0;i++){

        H[c[i]-'a'+1].push_back(i);

    }

    for(i=1;i<=n;i++){

        if(H[d[i]-'a'+1].empty()){

            fout<<"-1";

            return 0;

        }

        k=H[d[i]-'a'+1].front();

        H[d[i]-'a'+1].pop_front();

        sol+=k-querry(k)-1;

        update(k);

    }

    fout<<sol;

    return 0;

}
