#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

ifstream si("swap.in");

ofstream so("swap.out");



int n,u,num,rez,p[250000],vs[250000];

string s;

vector<int> pos[300];

void make(int node,int st,int dr) {

    if(st==dr) {

        p[++num]=node;

        return;

    }

    int md=(st+dr)/2;

    make(2*node,st,md);

    make(2*node+1,md+1,dr);

}

int take(int node,int sum) {

    if(node==1)

        return sum;

    if(node/2*2+1!=node)

        vs[node/2*2+1]++;

    return take(node/2,sum+vs[node]);

}

int main() {

    getline(si,s);

    n=s.size();

    for(int i=n-1; i>=0; i--)

        pos[s[i]-96].push_back(i);

    make(1,1,n);

    rez=-n;

    getline(si,s);

    for(int i=0; i<n; i++) {

        if(!pos[s[i]-96].size()) {

            so<<-1<<'\n';

            return 0;

        }

        u=pos[s[i]-96].back()+1;

        num=take(p[u],0);

        rez+=u-num;

        pos[s[i]-96].pop_back();

    }

    so<<rez<<'\n';

    return 0;

}
