#include <bits/stdc++.h>


using namespace std;







ifstream f("evaluare.in");

ofstream g("evaluare.out");





long long operatie[100001],q[100001],n,numIndex,opIndex,number;

char s[100001];
inline void readInput()

{

    f.getline(s, 100001);

    n = strlen(s);

}



int grad(char c)

{

    if(c == '+' || c == '-') return 1;

    if(c == '*' || c == '/') return 2;

    return 0;

}



void calculeaza(int a,int b)

{

    if(operatie[b]=='+')

    {

        q[a-1]+=q[a];

    }

    if(operatie[b]=='-')

    {

        q[a-1]-=q[a];

    }

    if(operatie[b]=='*')

    {

        q[a-1]*=q[a];

    }

    if(operatie[b]=='/')

    {

        q[a-1]/=q[a];

    }

    return;

}



inline void Solution()

{

    for(int i = 0 ; i < n ; ++ i)

    {

        if(isdigit(s[i]))

        {

            number = 0;

            while(isdigit(s[i]))

            {

                number *= 10;

                number += (s[i] - '0');

                i++;

            }

            i--;

            q[++numIndex] = number;

        }

        else

        {

            if(opIndex == 0 || s[i] == '(' || grad(operatie[opIndex]) < grad(s[i]))

            {

                operatie[++ opIndex] = s[i];

            }

            else if(s[i] == ')')

            {

                while(operatie[opIndex] != '(')

                {

                    calculeaza(numIndex, opIndex);

                    numIndex --;

                    opIndex --;

                }

                opIndex --;

            }

            else

            {

                while(grad(s[i]) <= grad(operatie[opIndex]))

                {

                    calculeaza(numIndex, opIndex);

                    numIndex --;

                    opIndex --;

                }

                operatie[++ opIndex] = s[i];

            }

        }



    }

    while(opIndex)

    {

        calculeaza(numIndex, opIndex);

        numIndex --;

        opIndex --;

    }

}



inline void Output()

{

    g << q[1];

}



int main()

{

    readInput();

    Solution();

    Output();

    return 0;

}
