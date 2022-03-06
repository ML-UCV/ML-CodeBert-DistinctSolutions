#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

const int NMAX=100005;

int op[NMAX],polo[NMAX];

int top_op,top_polo;

int pr(char ch)

{

    switch(ch)

    {

        case '+': return 1;

        case '-': return 1;

        case '*': return 2;

        case '/': return 2;

        default: return 0;

    }

}

void eval()

{

    if(op[top_op]=='+')

        polo[top_polo-1]=polo[top_polo-1]+polo[top_polo];

    if(op[top_op]=='-')

        polo[top_polo-1]=polo[top_polo-1]-polo[top_polo];

    if(op[top_op]=='*')

        polo[top_polo-1]=polo[top_polo-1]*polo[top_polo];

    if(op[top_op]=='/')

        polo[top_polo-1]=polo[top_polo-1]/polo[top_polo];

    top_op--;

    top_polo--;

}

int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    int nr;

    char ch;

    scanf("%c",&ch);

    while(isdigit(ch) || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')')

    {

        if(isdigit(ch))

        {

            nr=0;

            while(isdigit(ch))

            {

                nr=nr*10+(ch-'0');

                scanf("%c",&ch);

            }

            polo[++top_polo]=nr;

        }

        else

        {

            if(top_op==0 || ch=='(' || pr(op[top_op])<pr(ch))

               op[++top_op]=ch;

            else

            {

                if(ch==')')

                {

                    while(op[top_op]!='(')

                        eval();

                    top_op--;

                }

                else

                {

                    while(pr(op[top_op])>=pr(ch))

                        eval();

                    op[++top_op]=ch;

                }

            }

            scanf("%c",&ch);

        }

    }

    while(top_op)

        eval();

    printf("%d",polo[1]);

    fclose(stdin);

    fclose(stdout);

    return 0;

}
