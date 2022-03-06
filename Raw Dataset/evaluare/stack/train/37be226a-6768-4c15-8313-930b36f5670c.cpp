#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;



stack <char> semne;

stack <int> numere;



char s[100050];



int prop(char c)

{

    if(c=='(')return 0;

    if(c=='+'||c=='-')return 1;

    if(c=='*'||c=='/')return 2;

    if(c=='~')return 3;

    return -1;

}





int main()

{

    char ll;

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin.getline(s+1,100050);

    s[0]='(';

    int n=strlen(s);

    s[n]=')';s[++n]=0;

    int i=0,j,b,a;

    char numars[100];

    while(i<n)

    {

        if(s[i]=='(')

            {semne.push(s[i]);i++;}

        else

            if(s[i]=='-'&&prop(s[i-1])>=0)



                     {i++;semne.push('~');}

            else

                if(s[i]==')')

                {

                    while(semne.top()!='(')

                    {

                        if(semne.top()=='~')

                        {semne.pop();numere.top()*=-1;}

                        else if(semne.top()=='*')

                                {

                                    a=numere.top();numere.pop();

                                    b=numere.top();numere.pop();

                                    semne.pop();numere.push(b*a);

                                }

                        else if(semne.top()=='/')

                                {

                                    a=numere.top();numere.pop();

                                    b=numere.top();numere.pop();

                                    semne.pop();numere.push(b/a);

                                }

                        else if(semne.top()=='+')

                                {

                                    a=numere.top();numere.pop();

                                    b=numere.top();numere.pop();

                                    semne.pop();numere.push(b+a);

                                }

                        else if(semne.top()=='-')

                                {

                                    a=numere.top();numere.pop();

                                    b=numere.top();numere.pop();

                                    semne.pop();numere.push(b-a);

                                }

                    }

                    i++;

                    semne.pop();

                }

                else

                    if(prop(s[i])>0)

                    {

                       while(prop(s[i])<=prop(ll=semne.top()))

                        {

                             if(semne.top()=='~')

                                {semne.pop();numere.top()*=-1;}

                                else if(semne.top()=='*')

                                        {

                                            a=numere.top();numere.pop();

                                            b=numere.top();numere.pop();

                                            semne.pop();numere.push(b*a);

                                        }

                                else if(semne.top()=='/')

                                        {

                                            a=numere.top();numere.pop();

                                            b=numere.top();numere.pop();

                                            semne.pop();numere.push(b/a);

                                        }

                                else if(semne.top()=='+')

                                        {

                                            a=numere.top();numere.pop();

                                            b=numere.top();numere.pop();

                                            semne.pop();numere.push(b+a);

                                        }

                                else if(semne.top()=='-')

                                        {

                                            a=numere.top();numere.pop();

                                            b=numere.top();numere.pop();

                                            semne.pop();numere.push(b-a);

                                        }

                        }



                        semne.push(s[i]);

                        i++;

                    }

                else

                {

                    j=i;

                    while(isdigit(s[j]))j++;

                    strncpy(numars,s+i,j-i);

                    numars[j-i]=0;

                    numere.push(atoi(numars));

                    i=j;

                }

    }

    fout<<numere.top();

    return 0;

}
