#include <bits/stdc++.h>


using namespace std;

ifstream f ("evaluare.in");

ofstream g ("evaluare.out");



char a[100005];

stack <char> op;

stack <int> val;



int valoare (char c)

{

    if(c=='+' || c=='-')

        return 1;

    if(c=='*' || c=='/')

        return 2;

    return 0;



}

int operatie (int x, int y, char op)

{

    if(op=='+')

        return x+y;

    if(op=='-')

        return x-y;

    if(op=='*')

        return x*y;

    if(op=='/')

        return x/y;





}



int evaluare (int lung )

{



    for(int i=0; i<lung; ++i)

    {

        if(a[i]=='(')

            op.push(a[i]);

       else if(isdigit(a[i]))

        {



            int v=0;

            while(isdigit(a[i]))

            {

                v=v*10+(a[i]-'0');

                ++i;

            }

            val.push(v);

            --i;

        }

        else if(a[i]==')')

        {

            while(!op.empty() && op.top()!='(')

            {

                int doi=val.top();

                val.pop();

                int prim=val.top();

                val.pop();



                char operation=op.top();

                op.pop();



                val.push(operatie(prim,doi,operation));

            }

            if(!op.empty())

                op.pop();

        }



        else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')

        {

            while(!op.empty() && valoare(op.top())>=valoare(a[i]))

            {

                int val2 = val.top();

                val.pop();



                int val1 = val.top();

                val.pop();



                char ops = op.top();

                op.pop();



                val.push(operatie(val1, val2, ops));

            }

            op.push(a[i]);

        }



    }

    while(!op.empty())

    {

        int doi=val.top();

        val.pop();



        int prim=val.top();

        val.pop();



        char operation=op.top();

        op.pop();



        val.push(operatie(prim,doi,operation));

    }



    return val.top();



}

int main()

{

    f.getline(a,100001);

    int x=strlen(a);

    g<<evaluare(x);

    return 0;

}
