#include <bits/stdc++.h>


using namespace std;



int a[100005], b[100005], n, cnt;



ifstream fin("inv.in");

ofstream fout("inv.out");



int Int(int st, int m, int dr)

{

    int i, j, k;

    i = st; j = m + 1; k = 0;

    while(i <= m && j <= dr)

        if(a[i] <= a[j])b[++k] = a[i++];

        else

        {

            cnt += (m - i + 1);

            cnt = cnt % 9917;

            b[++k] = a[j++];

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

    if(dr - st <= 1)

    {

        if(a[st] > a[dr])

        {

            cnt++;

            if(cnt == 9917)cnt = 0;

            swap(a[st], a[dr]);

        }

    }

    else

    {

        int m = (st + dr) / 2;

        MSort(st, m);

        MSort(m + 1, dr);

        Int(st, m, dr);

    }

}



int main()

{

    int i;

    fin >> n;

    for(i = 1; i <= n; i++)

        fin >> a[i];

    MSort(1, n);

    fout << cnt;

    fin.close();

    fout.close();

    return 0;

}
