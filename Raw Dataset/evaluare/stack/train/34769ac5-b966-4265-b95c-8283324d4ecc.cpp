#include <bits/stdc++.h>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

string s;

int a[1001];

char o[1001];

int preced(char op)

{

    if(op=='+' or op=='-')

        return 1;

    if(op=='*' or op=='/')

        return 2;

        return 0;

}

int Calcul(int a,int b,char op)

{

    switch(op){case '+':return a+b;

    case '-':return a-b;

    case '*':return a*b;

    case '/':return a/b;}

}

int eval(string tokens){

int i;char op;

stack <int> values;

stack <char> ops;

for(i=0;i<tokens.length();i++){

    if(tokens[i]==' ')continue;

    else if(tokens[i]=='(')

                ops.push(tokens[i]);

    else if(isdigit(tokens[i]))

    {

        int val=0;

        while(i<tokens.length() && isdigit(tokens[i]))

        {

            val=val*10+(tokens[i]-'0');i++;}i--;

        values.push(val);

    }else if(tokens[i]==')')

    {

        while(!ops.empty() && ops.top()!='(')

        {

            int val2=values.top();

            values.pop();

            int val1=values.top();

            values.pop();

            op = ops.top();

            ops.pop();

            values.push(Calcul(val1,val2,op));

        }

        if(!ops.empty())

            ops.pop();

    }

    else

    {

        while(!ops.empty()&&preced(ops.top())>=preced(tokens[i]))

        {

            int val2=values.top();

            values.pop();

            int val1=values.top();

            values.pop();

            char op=ops.top();

            ops.pop();

            values.push(Calcul(val1,val2,op));

        }

        ops.push(tokens[i]);

    }

}

while(!ops.empty())

{

    int val2=values.top();

    values.pop();

    int val1=values.top();

    values.pop();

    char op=ops.top();

    ops.pop();

    values.push(Calcul(val1,val2,op));

}

return values.top();

}

int main()

{

    getline(fin,s);

    fout << eval(s) << '\n';

    return 0;

}
