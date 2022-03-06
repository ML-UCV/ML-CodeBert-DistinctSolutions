#include<fstream>
#include<cstring>
#include<list>
using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");

list <int> v[26];

char a[50005],b[50005];

int n,ch,sol,ap1[26],ap2[26],A[50005],V[50005];

inline void update(int p)

{

    int i;

    for (i=p;i<=n;i+=(i&-i))

        ++V[i];

}

inline int query(int p)

{

    int i,sum=0;

    for (i=p;i>0;i-=(i&-i))

        sum+=V[i];

    return sum;

}

int main()

{

    int i;

    fin.getline(a+1,50005);

    fin.getline(b+1,50005);

    n=strlen(a+1);

    for (i=1;i<=n;++i)

    {

        ++ap1[a[i]-'a'], ++ap2[b[i]-'a'];

        v[a[i]-'a'].push_back(i);

    }

    for (i=0;i<26;++i)

        if (ap1[i]!=ap2[i])

        {

            fout<<"-1\n";

            return 0;

        }

    for (i=1;i<=n;++i)

    {

        ch=b[i]-'a';

        A[i]=v[ch].front();

        v[ch].pop_front();

    }

    for (i=1;i<=n;++i)

    {

        sol+=query(A[i]-1);

        update(A[i]);

    }

    if (n&1)

        sol=((n-1)>>1)*n-sol;

    else

        sol=(n>>1)*(n-1)-sol;

    fout<<sol<<"\n";

    return 0;

}
