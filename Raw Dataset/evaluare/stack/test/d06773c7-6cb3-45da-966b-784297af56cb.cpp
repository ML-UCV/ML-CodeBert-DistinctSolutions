#include <iostream>
#include <fstream>
#include <queue>
#include <stack>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



struct type

{

    union

    {

        int i;

        char c;

    };

    char t;

};



queue <type> v;

stack <char> op;



int main()

{

    char c[100000];

    f>>c;

    char *p=c;

    type e;

    while(*p!='\00')

    {

        if(*p>='0' && *p<='9')

        {

            int x=0;

            while(*p>='0' && *p<='9')

                x=x*10+*p-'0',++p;

            e.t='i';

            e.i=x;

            v.push(e);

        }

        else

        {

            if(op.empty())

                op.push(*p);

            else

            switch(*p)

            {

            case '*':

                while(!op.empty() && (op.top()=='*' || op.top()=='/'))

                    e.t='c',e.c=op.top(),v.push(e),op.pop();

                op.push(*p);

                break;

            case '/':

                while(!op.empty() && (op.top()=='*' || op.top()=='/'))

                    e.t='c',e.c=op.top(),v.push(e),op.pop();

                op.push(*p);

                break;

            case '+':

                while(!op.empty() && op.top()!='(')

                    e.t='c',e.c=op.top(),v.push(e),op.pop();

                op.push(*p);

                break;

            case '-':

                while(!op.empty() && op.top()!='(')

                    e.t='c',e.c=op.top(),v.push(e),op.pop();

                op.push(*p);

                break;

            case '(':

                op.push(*p);

                break;

            case ')':

                while(!op.empty() && op.top()!='(')

                    e.t='c',e.c=op.top(),v.push(e),op.pop();

                op.pop();

                break;

            }

            ++p;

        }

    }

    while(!op.empty())

        e.t='c',e.c=op.top(),v.push(e),op.pop();

    stack <int> st;

    queue <type> aux=v;

    while(!aux.empty())

    {

        if(aux.front().t=='i')

            cout<<aux.front().i<<' ';

        else

            cout<<aux.front().c<<' ';

        aux.pop();

    }

    cout<<'\n';

    while(!v.empty())

    {

        if(v.front().t=='i')

            st.push(v.front().i);

        else

        {

            int x=st.top();

            st.pop();

            int y=st.top();

            st.pop();

            switch(v.front().c)

            {

            case '+':

                st.push(x+y);

                break;

            case '-':

                st.push(y-x);

                break;

            case '*':

                st.push(x*y);

                break;

            case '/':

                st.push(y/x);

                break;

            }

        }



        v.pop();

    }

    g<<st.top();

    return 0;

}
