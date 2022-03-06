#include <fstream>
using namespace std;

ifstream in("evaluare.in");

ofstream out("evaluare.out");

string s;

int i,steve[100001],cnt,signsteve[100001],cnt1,steva[100001],contor;

int formnr()

{

    int rez=0;

    for(; i<s.size()&&s[i]>='0'&&s[i]<='9'; i++)

        rez=rez*10+s[i]-'0';

    i--;

    steve[++cnt]=rez;

}

void codif()

{

    for(i=0; i<s.size(); i++)

    {

        if(s[i]>='0'&&s[i]<='9')

            formnr();

        else if(s[i]=='+'||s[i]=='-')

        {

            while(cnt1&&signsteve[cnt1]<=-2)

            {

                steve[++cnt]=signsteve[cnt1];

                cnt1--;

            }

            if(s[i]=='+')

                signsteve[++cnt1]=-2;

            else

                signsteve[++cnt1]=-3;

        }

        else if(s[i]=='/'||s[i]=='*')

        {

            while(cnt1&&signsteve[cnt1]<=-4)

            {

                steve[++cnt]=signsteve[cnt1];

                cnt1--;

            }

            if(s[i]=='*')

                signsteve[++cnt1]=-4;

            else

                signsteve[++cnt1]=-5;

        }

        else

        {

            if(s[i]=='(')

                signsteve[++cnt1]=-1;

            else

            {

                while(cnt1&&signsteve[cnt1]!=-1)

                {

                    steve[++cnt]=signsteve[cnt1];

                    cnt1--;

                }

                cnt1--;

            }

        }

    }

    while(cnt1)

    {

        steve[++cnt]=signsteve[cnt1];

        cnt1--;

    }

}

int main()

{

    in>>s;

    codif();

    for(i=1; i<=cnt; i++)

    {

        if(steve[i]<=-1)

        {

            if(steve[i]==-2)

            {

                steva[contor-1]+=steva[contor];

                contor--;

            }

            else if(steve[i]==-3)

            {

                steva[contor-1]-=steva[contor];

                contor--;

            }

            else if(steve[i]==-4)

            {

                steva[contor-1]*=steva[contor];

                contor--;

            }

            else if(steve[i]==-5)

            {

                steva[contor-1]/=steva[contor];

                contor--;

            }

        }

        else

            steva[++contor]=steve[i];

    }

    out<<steva[1];

    return 0;

}
