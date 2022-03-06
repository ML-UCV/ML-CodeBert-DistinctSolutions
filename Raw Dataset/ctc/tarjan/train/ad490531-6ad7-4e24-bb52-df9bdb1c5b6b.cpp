#include<stdio.h>
#include<vector>


using namespace std;



const int MAXN = 100001;



vector <int> g[MAXN], dfs_st;

bool viz[MAXN];

bool onS[MAXN];

int min_back[MAXN];

vector <vector <int>> sol;



FILE *in, *out;



void get_ctc(int v) {

    vector<int> rez = vector<int> ();

    while(dfs_st.back() != v) {

        rez.push_back(dfs_st.back());

        onS[dfs_st.back()] = false;

        dfs_st.pop_back();

    }



    rez.push_back(v);

    dfs_st.pop_back();

    onS[v] = false;

    sol.push_back(rez);

}



int tarj(int n) {





    viz[n] = true;

    min_back[n] = dfs_st.size();

    int poz = min_back[n];

    dfs_st.push_back(n);

    onS[n] = true;

    for(auto &it : g[n]) {

        if(!viz[it]) {

            int x = tarj(it);

            min_back[n] = min(min_back[n], x);

        } else {

            if(onS[it]) {

                min_back[n] = min(min_back[n], min_back[it]);

            }

        }

    }



    if(min_back[n] == poz) {

        get_ctc(n);

    }







    return min_back[n];

}
int main () {

    in = fopen("ctc.in", "r");

    out = fopen("ctc.out", "w");



    int n, m;

    fscanf(in, "%d %d", &n, &m);



    for(int i = 0; i < m; i++) {

        int x, y;

        fscanf(in, "%d %d", &x, &y);

        g[x].push_back(y);

    }



    fclose(in);



    for(int i = 1; i <= n; i++) {

        if(!viz[i]) {

            tarj(i);

        }

    }



    fprintf(out, "%d\n", sol.size());

    for(auto &ctc : sol) {

        for(auto &elem : ctc) {

            fprintf(out, "%d ", elem);

        }

        fprintf(out, "\n");

    }



    fclose(out);



    return 0;

}
