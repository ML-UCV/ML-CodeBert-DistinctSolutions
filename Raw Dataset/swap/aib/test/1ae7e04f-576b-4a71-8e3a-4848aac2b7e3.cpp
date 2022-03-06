#include <fstream>
#include <cstring>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

int i,ok=1,n,f[130],f1[130],sol,v[50010],poz[50010],w[50010],nr,cnt,k,a[130][50010];

char s[50010],c[50010];

int query(int p){

    int sol=0;

    for(;p;p-=(p&-p))

        sol+=v[p];

    return sol;

}

void update(int p){

    for(;p<=n;p+=(p&-p))

        v[p]++;

}

int main(){

    fin>>(s+1);

    for(i=1;s[i]!=0;i++)

        f[s[i]]++;

    fin>>(c+1);

    for(i=1;c[i]!=0;i++)

        f1[c[i]]++;

    for(char t='a';t<='z';t++)

        if(f[t]!=f1[t]){

            ok=0;

            break;

        }

    if(!ok){

        fout<<-1;

        return 0;

    }

    n=strlen(s+1);

    for(i=1;i<=n;i++)

        f[s[i]]=f1[s[i]]=0;



    for(i=1;i<=n;i++)

        a[c[i]-'0'][++f[c[i]]]=i;



    for(i=1;i<=n;i++){

        f1[s[i]]++;

        w[i]=a[s[i]-'0'][f1[s[i]]];



    }

    for(i=1;i<=n;i++){

        sol+=(query(n)-query(w[i]));

        update(w[i]);

    }

    fout<<sol;

    return 0;

}
