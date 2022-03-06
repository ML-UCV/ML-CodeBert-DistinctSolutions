#include <bits/stdc++.h>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



string sir;

struct nod

{

    bool isNum=1;

    int num;

    char exp='\0';

}a[100002];

int Q;

int End[100002];



int solve(int poz)

{

    int sum=0;

    int start=poz;

    poz++;



    int semn=1,val;

    while( a[poz].exp!=')' )

    {

        if(!a[poz].isNum)

        {

            if(a[poz].exp=='(')

            {

                val=solve(poz);

                poz=End[poz];

            }

            else

                semn*=(a[poz].exp=='-'?-1:1);

        }

        else

            val=a[poz].num;



        if(a[++poz].isNum)

            val=a[poz].num;

        else if(a[poz].exp=='(')

        {

            val=solve(poz);

            poz=End[poz];

        }

        else

            poz--;



        poz++;

        while(a[poz].exp!='+' && a[poz].exp!='-' && a[poz].exp!=')')

        {

            if(a[poz].exp=='*')

            {

                if(a[++poz].exp=='(')

                {

                    val*=solve(poz);

                    poz=End[poz];

                }

                else

                    val*=a[poz].num;

            }

            else

            {

                if(a[++poz].exp=='(')

                {

                    val/=solve(poz);

                    poz=End[poz];

                }

                else

                    val/=a[poz].num;

            }



            poz++;

        }



        sum+=semn*val;

        semn=1;

    }



    End[start]=poz;



    return sum;

}



int main()

{

    in>>sir;



    Q=0;

    a[0].isNum=0;



    for(auto lit:sir)

        if(isalnum(lit))

        {

            if(!a[Q].isNum)

                Q++;

            a[Q].num=a[Q].num*10+lit-'0';

        }

        else

        {

            a[++Q].isNum=0;

            a[Q].exp=lit;

        }



    a[0].exp='(';

    a[++Q].isNum=0;

    a[Q].exp=')';



    out<<solve(0);



    return 0;

}
