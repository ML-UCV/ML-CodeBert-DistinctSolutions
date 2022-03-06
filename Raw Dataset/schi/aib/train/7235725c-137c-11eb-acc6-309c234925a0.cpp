#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int AIB[30008];

int v[30009];

int place[30009];

int n;



void Read()

{

    int i,j;

    fin>>n;

    for(i=1; i<=n; ++i)

        fin>>v[i];

}



void Update(int pos, int val)

{

    while(pos <= n)

    {

        AIB[pos] += val;

        pos += pos &(-pos);

    }

}



int Query(int pos)

{

    int sum = 0;

    while( pos )

    {

        sum += AIB[pos];

        pos -= pos&(-pos);

    }

    return sum;

}



int BinSearch(int lf ,int rg, int val)

{

    if(lf > rg)

        return n+1;

    int mid = lf + (rg-lf)/2;

    int ans = Query(mid);

    if(ans == val)

        return min(mid, BinSearch(lf, mid-1, val));

    if(ans < val)

        return BinSearch(mid+1,rg, val);

    else return BinSearch(lf, mid-1, val);

}







void Do()

{

    int i,j,ans;

    for(i = 1; i<=n; ++i)

        Update(i, 1);

    for(i = n; i>=1; --i)

    {

        int ans = BinSearch(1,n, v[i]);

        place[ans] = i;

        Update(ans, -1);

    }

    for(i=1; i<=n; ++i)

        fout<<place[i]<<"\n";

}



int main()

{

    Read();

    Do();

    return 0;

}
