#include <bits/stdc++.h>






using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int v[100010],n;



long long inver(int left, int right)

{

    if (left == right)

        return 0;

    int mid = (left + right)/2;

    long long r1 = inver(left,mid);

    long long r2 = inver(mid+1, right);

    long long p1 = left, p2 = mid + 1, r3 = 0,x = 0;

    vector <int> l;

    while (p1 <= mid && p2 <= right)

    {

        if (v[p1] <= v[p2])

        {

            l.push_back(v[p1]);

            p1++;

        }

        else

        {

            r3 += p2 - p1 -x;

            l.push_back(v[p2]);

            p2++; x++;



        }

    }

    while (p1 <= mid)

    {

        l.push_back(v[p1]);

        p1++;

    }

    while (p2 <=right)

    {

        l.push_back(v[p2]);

        p2++;

    }



    for (int i = left,j = 0; i <= right; i++, j++)

        v[i] = l[j];



    return r1+r2+r3;

}



int main()

{

    int n;

    fin >> n;

    for (int i = 1; i <= n; i++)

        fin >> v[i];

    fout << (inver(1,n)%9917);

    return 0;

}
