#include <bits/stdc++.h>
using namespace std;

vector<int> get_precedence()
{
    vector<int> ans(256, 0);
    ans['-'] = ans['+'] = 1;
    ans['*'] = ans['/'] = 2;

    return ans;
}

vector<string> transform_to_postfix(string S)
{
    vector<int> precedence = get_precedence();
    vector<string> postfix;
    vector<char> operators;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            int j = i;
            while (i + 1 < S.size() && S[i + 1] >= '0' && S[i + 1] <= '9')
                i++;
            postfix.push_back(S.substr(j, i - j + 1));
            continue;
        }
        if (S[i] == ')')
        {
            while (!operators.empty() && operators.back() != '(')
            {
                postfix.push_back(string(1, operators.back()));
                operators.pop_back();
            }
            operators.pop_back();
            continue;
        }

        if (S[i] == '(' || operators.empty() || precedence[S[i]] > precedence[operators.back()])
            operators.push_back(S[i]);
        else
        {
            while (!operators.empty() && operators.back() != '(' && precedence[operators.back()] >= precedence[S[i]])
            {
                postfix.push_back(string(1, operators.back()));
                operators.pop_back();
            }
            operators.push_back(S[i]);
        }
    }


    while (!operators.empty())
    {
        postfix.push_back(string(1, operators.back()));
        operators.pop_back();
    }

    return postfix;
}

int convert_string_to_number(string S)
{
    int ans = 0;
    for (int i = 0; i < S.size(); i++)
        ans = ans * 10 + S[i] - '0';

    return ans;
}

int evaluate(vector<string> postfix)
{
    vector<int> operands;
    for (auto elem : postfix)
        if (elem[0] >= '0' && elem[0] <= '9')
            operands.push_back(convert_string_to_number(elem));
        else
        {
            int y = operands.back();
            operands.pop_back();
            int x = operands.back();
            operands.pop_back();
            int res;
            if (elem[0] == '+')
                res = x + y;
            if (elem[0] == '-')
                res = x - y;
            if (elem[0] == '*')
                res = x * y;
            if (elem[0] == '/')
                res = x / y;
            operands.push_back(res);
        }

    return operands.back();
}

int main()
{
    freopen("evaluare.in", "r", stdin);
    freopen("evaluare.out", "w", stdout);
    cin.sync_with_stdio(false);

    string S;
    cin >> S;
    vector<string> postfix = transform_to_postfix(S);
    cout << evaluate(postfix) << "\n";
    return 0;
}
