#include <fstream>
#include <stack>
using namespace std;

int pi[2000005],res[1005];

stack<int> s;

int main()

{

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");

    int l=0,n,m,cnt=0,r=0,c2=0,i;

    string a,b;

    cin >> a;

    cin >> b;

    n=a.size();

    m=b.size();

    for(int i=1;i<a.size();i++)

    {

        if(a[i]==a[l])

            l++;

        while(l>0 && a[l-1]!=a[i])

            l=pi[l-1];

        pi[i]=l;

    }

    l=0;

    i=0;

    while (i < m)

    {

        if (a[l] == b[i])

        {

            l++;

            i++;

        }

        if (l == n)

        {

            if(cnt<1000)

            {

                s.push(i-l);

                cnt++;

            }

            r++;

            l = pi[l - 1];

        }

        else if (i < m && a[l] != b[i])

        {

            if (l != 0)

                l = pi[l - 1];

            else

                i = i + 1;

        }

    }

    cout << r << '\n';

    while(s.size()>0)

    {

        res[c2]=s.top();

        c2++;

        s.pop();

    }

    for(int i=c2-1;i>=0;i--)

        cout << res[i] << " ";

    return 0;

}
