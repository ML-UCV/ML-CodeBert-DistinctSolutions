#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



struct stackchar

{

    char val[100000];

    int varf;

};



struct stackint

{

    int val[100000];

    int varf;

};



int priority(char op)

{

    if(op=='*' || op=='/')

        return 2;

    if(op=='+' || op=='-')

        return 1;

    return 0;

}



void postfix(char *exp, char *post)

{

    stackchar stiva;

    stiva.varf=-1;



    int j=0;



    for(int i=0;exp[i]!=0;)

    {

        if(exp[i]>='0' && exp[i]<='9')

        {

            while(exp[i]>='0' && exp[i]<='9')

                post[j++]=exp[i++];

            post[j++]=' ';

        }



        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')

        {

            if(stiva.varf==-1)

                stiva.val[++stiva.varf]=exp[i++];

            else

            {

                while(priority(exp[i])<=priority(stiva.val[stiva.varf]))

                {

                    post[j++]=stiva.val[stiva.varf--];

                    post[j++]=' ';

                }

                stiva.val[++stiva.varf]=exp[i++];

            }

        }



        if(exp[i]=='(')

        {

            stiva.val[++stiva.varf]=exp[i++];

        }

        if(exp[i]==')')

        {

            while(stiva.val[stiva.varf]!='(')

            {

                post[j++]=stiva.val[stiva.varf--];

                post[j++]=' ';

            }

            stiva.val[stiva.varf--];

            ++i;

        }

    }



    while(stiva.varf!=-1)

    {

        post[j++]=stiva.val[stiva.varf--];

        post[j++]=' ';

    }

    post[j]=0;

}



int evaluare(char *exp)

{

    stackint stiva;

    stiva.varf=-1;

    int nr;

    for(int j=0;exp[j]!=0;)

    {

        if(exp[j]==' ')

            ++j;

        if(exp[j]>='0' && exp[j]<='9')

        {

            nr=0;

            while(exp[j]>='0' && exp[j]<='9')

                nr=nr*10+(exp[j++]-'0');

            stiva.val[++stiva.varf]=nr;

        }



        if(exp[j]=='+' || exp[j]=='/' || exp[j]=='*' || exp[j]=='-')

        {

            nr=stiva.val[stiva.varf--];

            if(exp[j]=='+')

                stiva.val[stiva.varf]+=nr;

            if(exp[j]=='-')

                stiva.val[stiva.varf]-=nr;

            if(exp[j]=='*')

                stiva.val[stiva.varf]*=nr;

            if(exp[j]=='/')

                stiva.val[stiva.varf]/=nr;

                j++;

        }

    }

    return stiva.val[stiva.varf];

}



char exp[100001], post[300001];

int rez;



int main()

{

    fin.getline(exp, 100000);

    postfix(exp, post);

    rez=evaluare(post);

    fout<<rez;

    return 0;

}
