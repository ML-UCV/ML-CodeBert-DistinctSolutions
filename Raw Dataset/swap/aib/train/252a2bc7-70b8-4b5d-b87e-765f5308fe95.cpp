#include<fstream>
#include<cstring>


using namespace std;

ifstream f ("swap.in");

ofstream g ("swap.out");

char s[50010],sir[50010];

int viz[50],viz2[50],mat[30][50010],v[50010],arb[50010];

int n,m,i,total,nr;

char *p;

char aux[50010];

void update(int poz){

    for(int i=poz;i<=n;i+=(-i)&i){

        arb[i]+=1;

    }

}

int sum(int poz){

    int suma=0;

    for(int i=poz;i>0;i-=(-i)&i){

        suma+=arb[i];

    }

    return suma;

}



int main()

{

    f.getline(s,50010);

    f.getline(sir,50010);

    n=strlen(s);

    m=strlen(sir);

    if(n!=m){

        g<<-1;

        return 0;

    }

    for(i=0;i<n;++i){

        ++viz[s[i]-'a'];

        mat[s[i]-'a'][viz[s[i]-'a']]=i+1;

    }

    for(i=0;i<n;++i){

        ++viz2[sir[i]-'a'];

        v[i+1]=mat[sir[i]-'a'][viz2[sir[i]-'a']];

    }

    for(i=0;i<=26;++i){

        if(viz[i]!=viz2[i]) {

            g<<-1;

            return 0;

        }

    }

    total=0;

    for(i=n;i>0;--i){

        total+=sum(v[i]);

        update(v[i]);

    }

    g<<total<<'\n';

}
