#include <bits/stdc++.h>






using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



vector<int> v1[30], v2[30];

int vec[50005], n, AIB[50005];



void xAdd(int poz){

    for(int i = poz; i <= n; i += i & -i)

        AIB[i] ++;

}



int xCount(int poz){

    int rez = 0;

    for(int i = poz; i >= 1; i -= i & -i)

        rez += AIB[i];

    return rez;

}



int main()

{

    string a, b;

    fin >> a >> b;



    n = a.size();

    for(int i = 0; i < n; ++i)

        v1[a[i] - 'a'].push_back(i);

    for(int i = 0; i < n; ++i)

        v2[b[i] - 'a'].push_back(i);

    for(int i = 0; i < 26; ++i)

        if(v1[i].size() > 0)

        {

            if(v1[i].size() != v2[i].size())

            {

                fout << -1 << '\n';

                return 0;

            }

            for(int j = 0; j < v1[i].size(); ++j)

                vec[v1[i][j]] = v2[i][j];

        }

    for(int i = 0; i < n; ++i)

        vec[i] ++;

    int rez = 0;

    for(int i = n - 1; i >= 0; --i){

        rez += xCount(vec[i] - 1);

        xAdd(vec[i]);

    }

    fout << rez << '\n';

    return 0;

}
