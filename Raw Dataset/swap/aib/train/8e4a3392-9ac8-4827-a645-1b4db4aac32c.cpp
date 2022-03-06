#include <bits/stdc++.h>


using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



const int nmax = 50005;

int n, m, aib[nmax];

string a, b;

vector <int> G[30];



int Query(int i){

    int sum = 0;

    for (; i > 0; i -= ( (i ^ (i - 1)) & i )){

        sum += aib[i];

    }

    return sum;

}



void Update(int i){

    for (; i <= n; i += ( (i ^ (i - 1)) & i )){

        aib[i] += 1;

    }

}



int main(){

    fin >> a >> b;

    n = a.size();

    m = b.size();

    if (n != m){

        fout << -1;

        return 0;

    }

    for (int i = n - 1; i >= 0; --i){

        G[a[i] - 'a'].push_back(i + 1);

    }

    int ans = 0;

    for (int i = 0; i < m; ++i){

        if (G[b[i] - 'a'].size() == 0){

            fout << -1;

            return 0;

        }

        int index = G[b[i] - 'a'].back();

        G[b[i] - 'a'].pop_back();

        int index2 = index + Query(n) - Query(index - 1);

        ans += (index2 - (i + 1));

        Update(index);

    }

    fout << ans;

    fin.close();

    fout.close();

    return 0;

}
