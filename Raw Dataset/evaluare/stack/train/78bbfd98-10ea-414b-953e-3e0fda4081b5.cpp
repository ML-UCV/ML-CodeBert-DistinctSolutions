#include <fstream>
#include <cstring>
using namespace std;

ifstream cin ("evaluare.in");

ofstream cout ("evaluare.out");

char vc[100005];

int v[100005],st[100005];

int main()

{

    int n,i,nr,cnt=0,k=0,ok=0;

    cin>>vc+1;

    n=strlen(vc+1);

    i=1;

    while (i<=n)

    {

        if (vc[i]>='0'&&vc[i]<='9')

        {

            nr=0;

            while (vc[i]>='0'&&vc[i]<='9')

            {

                nr=nr*10+vc[i]-'0';

                i++;

            }

            v[++cnt]=nr;

            i--;

        }

        else

        {

            if (vc[i]=='(')

                st[++k]=-1;

            else

            if (vc[i]==')')

            {

                while (st[k]!=-1)

                {

                    v[++cnt]=st[k];

                    k--;

                }

                k--;

            }

            else

            if (vc[i]=='+')

            {

                while (st[k]!=-1&&k)

                {

                    v[++cnt]=st[k];

                    k--;

                }

                st[++k]=-3;

            }

            else

            if (vc[i]=='-')

            {

                while (st[k]!=-1&&k)

                {

                    v[++cnt]=st[k];

                    k--;

                }

                st[++k]=-4;

            }

            else

            if (vc[i]=='*')

            {

                while (st[k]==-5||st[k]==-6)

                {

                    v[++cnt]=st[k];

                    k--;

                }

                st[++k]=-5;

            }

            else

            {

                while (st[k]==-5||st[k]==-6)

                {

                    v[++cnt]=st[k];

                    k--;

                }

                st[++k]=-6;

            }

        }

        i++;

    }

    while (k)

    {

        v[++cnt]=st[k];

        k--;

    }



    for (i=1;i<=cnt;i++)

    {

        if (v[i]>=0)

            st[++k]=v[i];

        else

        {

            if (v[i]==-5)

            {



                if (k<=1)

                    st[k]=0;

                else

                {

                    k--;

                    st[k]=st[k]*st[k+1];

                }

            }

            else

            if (v[i]==-6)

            {



                k--;

                st[k]/=(st[k+1]);

            }

            else

            if (v[i]==-3)

            {

                k--;

                st[k]+=st[k+1];

            }

            else

            {

                k--;

                st[k]-=st[k+1];

            }

        }

    }

    cout<<st[1];

    return 0;

}
