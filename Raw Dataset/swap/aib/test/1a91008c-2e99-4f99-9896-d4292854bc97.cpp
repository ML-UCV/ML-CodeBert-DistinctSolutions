#include<fstream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

int n, i, s, aib[50003], vec[50003];

deque<int> a[30];

char s1[50003], s2[50003];

int query(int p)

{

    int r=0;

    for(;p;p-=(p & -p))

        r+=aib[p];

    return r;

}

void update(int p)

{

    for(;p<=n;p+=(p & -p))

        aib[p]++;

}

int main()

{

    f>>s1>>s2;

    for(i=0;s1[i]!=0;i++)

        a[s1[i]-'a'].push_back(i+1);

    for(i=0;s2[i]!=0;i++)

    {

        if(a[s2[i]-'a'].size()==0)

        {

            g<<-1;

            return 0;

        }

        n++;

        vec[i+1]=a[s2[i]-'a'][0];

        a[s2[i]-'a'].pop_front();

    }

    for(i=n;i>0;i--)

    {

        s=s+query(vec[i]);

        update(vec[i]);

    }

    g<<s;

    return 0;

}
