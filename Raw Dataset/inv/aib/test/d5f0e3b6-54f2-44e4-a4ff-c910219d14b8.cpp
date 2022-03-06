#include <bits/stdc++.h>
using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int N, answer;

pair <int, int> v[100000 + 5];



int bit[100000 + 5];

vector <int> pos;



void update(int x)

{

    for (int i = x; i <= N; i += (((i - 1) ^ i) & i))

        bit[i]++;

}



int query(int x)

{

    int ret = 0;

    for (int i = x; i >= 1; i -= (((i - 1) ^ i) & i))

        ret += bit[i];

    return ret;

}



int main()

{

    fin >> N;

    for (int i = 1; i <= N; i++)

    {

        fin >> v[i].first;

        v[i].second = i;

    }

    sort(v + 1, v + N + 1);

    reverse(v + 1, v + N + 1);

    for (int i = 1; i <= N; i++)

    {

        int j = i;

        while (j <= N && v[j].first == v[i].first)

        {

            pos.push_back(j);

            answer = (answer + query(v[j].second)) % 9917;

            j++;

        }

        for (auto &it: pos)

            update(v[it].second);

        pos.clear();

        if (j > i)

            i = j - 1;

    }

    fout << answer << "\n";

    return 0;

}
