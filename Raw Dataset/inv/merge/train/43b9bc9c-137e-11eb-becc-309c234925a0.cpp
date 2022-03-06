#include <bits/stdc++.h>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int n, a[100005], b[100005];

long long cnt;



void Intercl(int st, int m, int dr)

{

    int i, j, k = 0;

    i = st;

    j = m + 1;

    while(i <= m && j <= dr)

    {

        if(a[i] <= a[j]) b[++k] = a[i++];

        else

        {

            cnt = cnt + (m - i + 1);

            cnt %= 9917;

            b[++k] = a[j++];

        }

    }

    while(i <= m)

        b[++k] = a[i++];

    while(j <= dr)

        b[++k] = a[j++];

    j = 1;

    for(i = st; i <= dr; i++)

        a[i] = b[j++];

}



void MSort(int st, int dr)

{

    int m;

    if(dr - st <= 1)

    {

        if(a[st] > a[dr])

        {

            swap(a[st], a[dr]);

            cnt++;

        }

    }

    else

    {

        m = (st + dr) / 2;

        MSort(st, m);

        MSort(m + 1, dr);

        Intercl(st, m, dr);

    }

}



int main()

{

    cnt = 0;

    fin >> n;

    for(int i = 1; i <= n; i++)

        fin >> a[i];

    MSort(1, n);

    cnt %= 9917;

    fout << cnt << "\n";

    return 0;

}
