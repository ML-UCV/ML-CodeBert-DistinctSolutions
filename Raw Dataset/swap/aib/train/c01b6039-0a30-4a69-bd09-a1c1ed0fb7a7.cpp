#include <fstream>
#include <cstring>






using namespace std;



ifstream f("swap.in");

ofstream g("swap.out");



int n, i, lga, lgb, s, ok;

int qqa[303], qqb[303], order[50050], position[303][50050], aib[50050];

char a[50050];

char b[50050];

int p[50050];



void tree_update(int value, int pos)

{

    int j;

    for(j=pos; j<=n; j+=(j&(-j)))

    aib[j]+=value;

}



int tree_query(int position)

{

    int s=0;

    for(i=position; i>=1; i-=(i&(-i))) s+=aib[i];

    return s;

}



int main()

{

    f.getline(a, 50050);

    f.getline(b, 50050);



    lga=strlen(a);

    for(i=0;i<lga;++i)

    {

        ++qqa[a[i]];

        order[i]=qqa[a[i]];

    }

    lgb=strlen(b);

    for(i=0;i<lgb;++i)

    {

        ++qqb[b[i]];

        position[b[i]][qqb[b[i]]]=i+1;

    }

    ok=0;

    for(i='a'; i<='z' && !ok; ++i)

    if(qqa[i]!=qqb[i]) ok=1;



    if(ok) g<<"-1";

    else

    {

        for(i=0; i<lga; ++i)

        p[i+1]=position[a[i]][order[i]];



        n=lga;

        for(int j=lga; j>=1; --j)

        {

            s+=tree_query(p[j]);

            tree_update(1, p[j]);

        }

        g<<s;

    }

    return 0;

}
