#include <fstream>
#include <cstring>
#include <vector>


using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

int n,m;

int fr1[29],fr2[29],v[50011],aib[50011];

char A[50011],B[50011];



vector<int> L[36];

vector<int>::iterator it[36];



int query(int p){

    int r=0;

    for(;p;p-=(p&(-p))) r+=aib[p];

    return r;

}



void update(int p){

    for(;p<=n;p+=(p&(-p))) aib[p]++;

}



int main(void){

    register int i,j;





    f>>B+1>>A+1;

    n=strlen(A+1),m=strlen(B+1);

    if(n!=m){

        g<<"-1";

        f.close();

        g.close();

        return 0;

    }

    for(i=1;i<=n;i++) fr1[A[i]-'a']++,L[A[i]-'a'].push_back(i);

    for(i=0;i<=27;i++) it[i]=L[i].begin();

    for(i=1;i<=m;i++){

        fr2[B[i]-'a']++;

        v[i]=*it[B[i]-'a'];

        it[B[i]-'a']++;

    }

    for(i=0;i<=26;i++)

        if(fr1[i]!=fr2[i]){

            g<<"-1";

            f.close();

            g.close();

            return 0;

        }

    long long sol=0;

    for(i=1;i<=n;i++){

        sol-=query(v[i]);

        update(v[i]);

    }

    sol+=1LL*n*(n-1)/2;

    g<<sol;

    f.close();

    g.close();

    return 0;

}
