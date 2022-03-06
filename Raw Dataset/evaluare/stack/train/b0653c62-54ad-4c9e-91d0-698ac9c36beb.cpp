#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



string s;



inline int Precedence(char ch)

{

    if (ch == '^')

        return 3;

    if (ch == '*' || ch == '/')

        return 2;

    return 1;

}



inline void InfixToPostfix()

{

    int i;

    string t;

    stack<char> st;

    for (i = 0; s[i]; ++i)

        if (isdigit(s[i]) || (s[i]=='-' && (!i || s[i-1]=='(') && isdigit(s[i+1])))

        {

            if (s[i] == '-')

            {

                t.push_back('-');

                ++i;

            }

            while (isdigit(s[i]))

            {

                t.push_back(s[i]);

                ++i;

            }

            t.push_back(' ');

            --i;

        }

        else if (s[i] == '(')

            st.push('(');

        else if (s[i] == ')')

        {

            while (st.top() != '(')

            {

                t.push_back(st.top());

                t.push_back(' ');

                st.pop();

            }

            st.pop();

        }

        else

        {

            while (!st.empty() && st.top() != '(' && Precedence(s[i]) <= Precedence(st.top()))

            {

                t.push_back(st.top());

                t.push_back(' ');

                st.pop();

            }

            st.push(s[i]);

        }

    while (!st.empty())

    {

        t.push_back(st.top());

        t.push_back(' ');

        st.pop();

    }

    s = t;

}



inline int Power(int b, int e)

{

    int ans;

    ans = 1;

    while (e)

    {

        if (e % 2)

            ans = ans * b;

        b = b * b;

        e /= 2;

    }

    return ans;

}



inline int Calc(int a, int b, char op)

{

    if (op == '^')

        return Power(a, b);

    if (op == '*')

        return a * b;

    if (op == '/')

        return a / b;

    if (op == '+')

        return a + b;

    return a - b;

}



inline int Evaluate()

{

    int i, sign, x;

    vector<int> st;

    for (i = 0; s[i]; ++i)

        if (isdigit(s[i]) || (s[i]=='-' && isdigit(s[i+1])))

        {

            if (s[i] == '-')

            {

                sign = -1;

                ++i;

            }

            else

                sign = 1;

            x = 0;

            while (isdigit(s[i]))

            {

                x = x * 10 + s[i] - '0';

                ++i;

            }

            st.push_back(sign * x);

            --i;

        }

        else if (s[i] != '(' && s[i] != ')' && s[i]!=' ')



            {

                x = Calc(st[st.size() - 2], st[st.size() - 1], s[i]);

                st.pop_back(), st.pop_back();

                st.push_back(x);

            }

    return st.back();

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr), cout.tie(nullptr);

    cin >> s;

    cin.close();

    InfixToPostfix();

    cout << Evaluate();

    cout.close();



    return 0;

}
