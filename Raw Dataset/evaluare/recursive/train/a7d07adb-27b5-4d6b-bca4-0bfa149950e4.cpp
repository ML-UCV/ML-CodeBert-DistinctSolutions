#include <iostream>
#include <fstream>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



int i;

string s;



int eval();

int termen();

int factor();



int eval()

{ int val = termen();

    while(s[i] == '+' || s[i] == '-')

        { if(s[i] == '+')

                i++, val = val + termen();

            else

                i++, val = val - termen();

        }

    return val;

}



int termen()

{ int val = factor();

    while(s[i] == '*' || s[i] == '/')

        { if(s[i] == '*')

                i++, val = val * factor();

            if(s[i] == '/')

                i++, val = val / factor();

        }

    return val;

}



int factor()

{ int val = 0;

    if(s[i] == '(')

        { i++;

            val = eval();

            i++;

        }

    else

        { while(s[i] >= '0' && s[i] <= '9')

                { val = val * 10 + s[i] - '0';

                    i++;

                }

        }

    return val;

}



int main()

{

    f >> s;

    g << eval() << '\n';

    return 0;

}
