#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>




using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");

char vp[42949678],s[42949678],exp[42949678];

stack <int> st;

int n,kexp;





int prioritate(int c)

{

    if (s[c]=='(' || s[c]==')')

        return 0;

    if (s[c]=='*' || s[c]=='/')

        return 2;

    return 1;

}



void formare_nr(int &k)

{

    while (s[k]>='0'&& s[k]<='9')

    {

        exp[++kexp]=s[k];



        k++;

    }

    k--;

    exp[++kexp]=' ';

}





void forma_poloneza()

{

      for (int i=0;i<=n;i++)

    {

        if (s[i]>='0' && s[i]<='9')

            formare_nr(i);

        else if (prioritate(i)!=0)

        {

            if (st.empty())

                st.push(i);

            else

            {

                int a=prioritate(i);

                while (!st.empty() && prioritate(st.top())>=a)

                {

                    exp[++kexp]=s[st.top()];

                    st.pop();

                }

                st.push(i);

            }

        }

        else

        {

            if (s[i]=='(')

                    st.push(i);

            else

            {

                while (!st.empty()&& s[st.top()]!='(')

                {

                    exp[++kexp]=s[st.top()];

                    st.pop();

                }

                exp[++kexp]=' ';

                if (!st.empty()&& s[st.top()]=='(')

                        st.pop();

            }

        }



    }

       while (!st.empty()) exp[++kexp]= s[st.top()], st.pop();



}



int transf_int (int &k)

{ int nr=0;

    while (exp[k]>='0' && exp[k]<='9')

    {

        nr =nr*10 + (exp[k]-'0');

        k++;

    }



    return nr;





}



int calcul(int i, int a,int b)

{



    if (exp[i]=='-')

        return a-b;

     if (exp[i]=='+')

        return a+b;

     if (exp[i]=='*')

        return a*b;

    return a/b;



}



int evaluare(int k)

{

    while (!st.empty())

        st.pop();

    for (int i=1;i<=k;i++)

        {if (exp[i]>='0' && exp[i]<='9')

          st.push(transf_int(i));

          if (st.size()>=2 && exp[i]!=' ')

          {

              int a,b;

              a=st.top();

              st.pop();

              b=st.top();

              st.pop();



              st.push(calcul(i,b,a));

          }

        }

    return st.top();



}



int main()

{

    f>>s;

    n=strlen(s)-1;

    forma_poloneza();



g<<evaluare(kexp);
}
