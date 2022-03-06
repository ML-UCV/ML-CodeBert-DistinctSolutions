#include <bits/stdc++.h>


using namespace std;



struct Trei

{

    int val, ind, nou;

};

Trei a[100005];

int n, aib[100005];

ifstream fin("inv.in");

ofstream fout("inv.out");



void Update(int p, int x)

{

    while(p <= n)

    {

        aib[p] += x;

        p += (p & (-p));

    }

}







int Suma(int p)

{

    int s = 0;

    while(p > 0)

    {

        s += aib[p];

        p -= (p & (-p));

    }

    return s;

}





int CautBin(int p, int s)

{

    int st, dr, poz, mij;

    int sum;

    st = 1; dr= p; poz = -1;

    while(st <= dr)

    {

        mij = (st + dr)/2;

        sum = Suma(mij);

        if (sum == s)

        {

            poz = mij;

            dr = mij -1;

        }

        else if (sum > s) dr = mij -1;

        else st = mij + 1;

    }

    return poz;

}

inline bool Compara1(Trei A, Trei B)

{

    return A.val < B.val;

}

inline bool Compara2(Trei A, Trei B)

{

    return A.ind < B.ind;

}

int main()

{

    int i;

    int x;

    long long cnt = 0;

    fin >> n;

    for (i = 1; i <= n; i++)

    {

        fin >> x;

        a[i].val = x;

        a[i].ind = i;

    }





    sort(a + 1, a + n + 1, Compara1);

    a[1].nou = 1;

    for(i = 2; i <= n; i++)

        if(a[i].val == a[i-1].val)

            a[i].nou = a[i-1].nou;

        else a[i].nou = a[i-1].nou + 1;

    sort(a + 1, a + n + 1, Compara2);

    for(i = n; i >= 1; i--)

    {

        cnt += Suma(a[i].nou - 1);

        Update(a[i].nou, 1);



    }

    cnt %= 9917;

    fout << cnt << "\n";

    fin.close();

    fout.close();

    return 0;

}
