#include <fstream>
#include <stack>
using namespace std;

string zero=" ";

int pi[2000005],s[1005];

int main()

{

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");

    int k,la,lb,l=0,cnt=0,res=0;

    string a,b;

    cin >> a;

    cin >> b;

    la=a.size();

    lb=b.size();

    a=zero+a;

    a+=zero;

    b=zero+b;

    for(int i=2;i<=la;i++)

    {

        while(l>0 && a[l+1]!=a[i])

            l=pi[l];

        if(a[l+1]==a[i])

            l++;

        pi[i]=l;

    }

    l=0;

    for(int i=1;i<=lb;i++)

    {

        while(l>0 && a[l+1]!=b[i])

            l=pi[l];

        if(a[l+1]==b[i])

            l++;

        if(l==la)

        {

            if(cnt<1000)

            {

                s[cnt]=i-la;

                cnt++;

            }

            res++;

        }

    }

    cout << res << '\n';

    for(int i=0;i<cnt;i++)

        cout << s[i] << " ";

    return 0;

}
