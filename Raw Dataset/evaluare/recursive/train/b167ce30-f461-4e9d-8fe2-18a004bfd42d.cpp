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

{ int r = termen();

    while(s[i] == '+' || s[i] == '-')

        { if(s[i] == '+')

                { i++;

                    r = r + termen();

                }

            else

                { i++;

                    r = r - termen();

                }

        }

    return r;

}



int termen()

{ int r = factor();

    while(s[i] == '*' || s[i] == '/')

        { if(s[i] == '*')

                { i++;

                    r = r * factor();

                }

            else

                { i++;

                    r = r / factor();

                }

        }

    return r;

}



int factor()

{ int r = 0;

    if(s[i] == '(')

        { i++;

            r = eval();

            i++;

        }

    else

        { while(s[i] >= '0' && s[i] <= '9')

                { r = r * 10 + s[i] - '0';

                    i++;

                }

        }

    return r;

}



int main()

{

    f >> s;

    g << eval() << '\n';

    return 0;

}
