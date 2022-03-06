#include <fstream>
#include <stack>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



stack<char> sign;

stack<int> num;



char s[100001], t[150001];



inline int Precedence(char ch)

{ if (ch=='*' || ch=='/')

        return 2;

    return 1;

}



int main()

{ int j, i, x, y;

    cin>>s;

    cin.close();

    j=-1;

    for (i=0;s[i];++i)

        if (isdigit(s[i]))

        { while (isdigit(s[i]))

            { t[++j]=s[i];

                ++i;

            }

            t[++j]=' ';

            --i;

        }

        else if (s[i]=='(')

                 sign.push('(');

            else if (s[i]==')')

                { while (sign.top()!='(')

                    { t[++j]=sign.top();

                        sign.pop();

                    }

                    sign.pop();

                }

                else

                { while (!sign.empty() && sign.top()!='(' && Precedence(s[i])<=Precedence(sign.top()))

                    { t[++j]=sign.top();

                        sign.pop();

                    }

                    sign.push(s[i]);

                }

    while (!sign.empty())

    { t[++j]=sign.top();

        sign.pop();

    }



    for (i=0;t[i];++i)

        if (isdigit(t[i]))

        { x=0;

            while (isdigit(t[i]))

            { x=x*10+t[i]-'0';

                ++i;

            }

            num.push(x);

            --i;

        }

        else if (t[i]!=' ')

            { x=num.top();

                num.pop();

                y=num.top();

                num.pop();

                if (t[i]=='*')

                    num.push(x*y);

                else if (t[i]=='/')

                        num.push(y/x);

                    else if (t[i]=='+')

                            num.push(x+y);

                        else

                            num.push(y-x);

            }

    cout<<num.top();

    cout.close();



    return 0;

}
