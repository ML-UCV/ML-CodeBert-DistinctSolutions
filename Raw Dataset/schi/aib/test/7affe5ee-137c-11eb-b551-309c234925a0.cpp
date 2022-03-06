#include <bits/stdc++.h>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int N;

int bit[30005], ans[30005];

stack <int> S;



void update(int pos, int val)

{

    for(; pos <= N; pos += ((pos ^ (pos - 1)) & pos))

        bit[pos] += val;

}



int query(int X)

{

    int ret = 0;

    int sum = 0;

    for(int i = 14; i >= 0; i--)

        if(ret + (1 << i) <= N && sum + bit[ret + (1 << i)] < X)

            ret += (1 << i), sum += bit[ret];

    return ret + 1;

}



int main()

{

    fin >> N;

    for(int i = 1; i <= N; i++)

    {

        int x;

        fin >> x;

        S.push(x);

        update(i, 1);

    }

    for(; !S.empty(); S.pop())

    {

        int pos = query(S.top());

        ans[pos] = S.size();

        update(pos, -1);

    }

    for(int i = 1; i <= N; i++)

        fout << ans[i] << "\n";

    return 0;

}
