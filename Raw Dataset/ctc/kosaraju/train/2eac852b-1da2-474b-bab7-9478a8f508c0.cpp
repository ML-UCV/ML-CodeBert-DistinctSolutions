#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>


using namespace std;

FILE *fin, *fout;

vector <int>g[100009], gt[100009], gr[100009];

deque <int>s;

int n, ap[100009], nr=0;

void dfs(int a) {

    ap[a]=1;

    for (int i=0;i<g[a].size();i++) {

        int next=g[a][i];

        if (ap[next]==0) {

            dfs(next);

        }

    }

    s.push_back(a);

}

void dfss(int a) {

    ap[a]=2;

    gr[nr].push_back(a);

    for (int i=0;i<gt[a].size();i++) {

        int next=gt[a][i];

        if (ap[next]==1) {

            dfss(next);

        }

    }

}

int main()

{

    int m, a, b, i;

    fin=fopen("ctc.in" ,"r");

    fout=fopen("ctc.out" ,"w");

    fscanf(fin, "%d%d" ,&n ,&m);

    for (i=0;i<m;i++) {

        fscanf(fin, "%d%d" ,&a ,&b);

        g[a].push_back(b);

        gt[b].push_back(a);

    }

    for (i=1;i<=n;i++) {

        if (ap[i]==0) {

            dfs(i);

        }

    }

    while (!s.empty()) {

        if (ap[s.back()]==1) {



            nr++;

            dfss(s.back());

        }

        s.pop_back();

    }

    fprintf(fout, "%d\n" ,nr);

    for (i=1;i<=nr;i++) {

        for (int l=0;l<gr[i].size();l++) {

            fprintf(fout, "%d " ,gr[i][l]);

        }

        fprintf(fout, "\n");

    }

    cout << "Hello world!" << endl;

    return 0;

}
