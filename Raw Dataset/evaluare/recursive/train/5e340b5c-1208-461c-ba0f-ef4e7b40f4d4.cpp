#include <fstream>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



string s;



int i;



inline int Evaluate(), Term(), Factor(), Power(), Exponent();



int main()

{ ios_base::sync_with_stdio(false);

    cin.tie(nullptr), cout.tie(nullptr);

    cin>>s;

    cin.close();

    cout<<Evaluate();

    cout.close();



    return 0;

}



inline int Evaluate()

{ int ans, j, x;

    ans=Term();

    while (s[i]=='+' || s[i]=='-')

    { j=i;

        ++i;

        x=Term();

        if (s[j]=='+')

            ans+=x;

        else

            ans-=x;

    }

    return ans;

}



inline int Term()

{ int ans, j, x;

    ans=Factor();

    while (s[i]=='*' || s[i]=='/')

    { j=i;

        ++i;

        x=Factor();

        if (s[j]=='*')

            ans*=x;

        else

            ans/=x;

    }

    return ans;

}



inline int Power(int b, int e)

{ int ans;

    ans=1;

    while (e)

    { if (e%2)

            ans*=b;

        b*=b;

        e/=2;

    }

    return ans;

}



inline int Factor()

{ int ans, sign;

    if (s[i]=='(')

    { ++i;

        ans=Evaluate();

        ++i;

    }

    else

    { if (s[i]=='-')

        { sign=-1;

            ++i;

        }

        else

            sign=1;

        ans=0;

        while (isdigit(s[i]))

        { ans=ans*10+s[i]-'0';

            ++i;

        }

        ans*=sign;

    }

    while (s[i]=='^')

    { ++i;

        ans=Power(ans, Factor());

    }

    return ans;

}
