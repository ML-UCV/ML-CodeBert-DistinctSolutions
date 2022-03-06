#include <bits/stdc++.h>


using namespace std;

ifstream r("strmatch.in");

ofstream w("strmatch.out");

string a, b;

int p[2000005], n, m, rez;

vector<int>f;

void pref()

{

    p[0]=0;

    int cnt=0, ans=1;

    while (ans<n)

    {

        if (a[ans] == a[cnt])

        {

            cnt++;

            p[ans] = cnt;

            ans++;

        }

        else

        {

            if (cnt != 0)

            {

                cnt = p[cnt - 1];

            }

            else

            {

                p[ans] = 0;

                ans++;

            }

        }

    }

}

void kmp()

{

    int i=0, j=0;

    while(j<m)

    {

        if(a[i]==b[j])

        {

            i++;

            j++;

        }

        if(i==n)

        {

            if(rez<1000){

                f.push_back(j-i);

            }

            rez++;

            i=p[i-1];

        }

        else

        {

            if(j<m && a[i] != b[j])

            {

                if(i!=0)

                {

                    i=p[i-1];

                }

                else

                {

                    j++;

                }

            }

        }

    }

}

int main(void)

{

    r>>a;

    r>>b;

    n=a.size(), m=b.size();

    pref();

    kmp();

    w<<rez<<"\n";

    for(int i=0; i<f.size(); i++)

    {

        w<<f[i]<<" ";

    }

    w<<"\n";

    return 0;

}
