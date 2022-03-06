#include <algorithm>
#include <cstring>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

ifstream fin ("swap.in");

ofstream fout ("swap.out");

deque <int> A[28];

deque <int> B[28];

int n,i,sol,p,aib[50001];

char s1[50001], s2[50001];

int query (int p){

    int r=0;

    for(;p;p-=p&-p){

        r+=aib[p];

    }

    return r;

}



void update (int p){

    for(;p<=n;p+=p&-p)

        aib[p]++;

}





int main(){

    fin>>s1+1>>s2+1;

    for(i=1;s1[i]!=0;i++) {

        A[s1[i]-'a'+1].push_back(i);

        B[s2[i]-'a'+1].push_back(i);

        ++n;

    }

    for(i=1;i<=26;i++)

        if(A[i].size()!=B[i].size()){

            fout<<-1;

            return 0;

        }

    for(i=1;i<=n;i++){

        p=A[s2[i] - 'a'+1].front();

        A[s2[i] - 'a'+1].pop_front();

        sol+=p-query(p)-1;

        update(p);

    }

    fout<<sol;

}
