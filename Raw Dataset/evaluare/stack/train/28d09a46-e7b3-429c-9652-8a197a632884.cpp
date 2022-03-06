#include <bits/stdc++.h>
typedef unsigned long long ul;

typedef long long ll;

using namespace std;



bool is_op(char c){

    return (c == '+' or c == '-' or c == '*' or c == '/');

}



int priority(char c){

    if (c == '+' or c == '-')

        return 1;

    if (c == '*' or c == '/')

        return 2;

    return -1;

}



void process(stack<int> &stk, char op){

    int r = stk.top();

    stk.pop();

    int l = stk.top();

    stk.pop();



    if (op == '+')

        stk.push(l + r);

    else if (op == '-')

        stk.push(l - r);

    else if (op == '*')

        stk.push(l * r);

    else if (op == '/')

        stk.push(l / r);

}



int evaluare(string s){

    stack<int> val;

    stack<char> op;



    for (int i = 0; i < s.length(); i++){

        if (s[i] == '(')

            op.push('(');



        else if (s[i] == ')'){

            while (op.top() != '('){

                process(val, op.top());

                op.pop();

            }

            op.pop();

        }



        else if (is_op(s[i])){

            char curr = s[i];

            while(!op.empty() and priority(op.top()) >= priority(curr)){

                process(val, op.top());

                op.pop();

            }

            op.push(curr);

        }



        else {

            int num = 0;

            while (i < s.length() and isdigit(s[i]))

                num = num * 10 + s[i++] - '0';

            --i;

            val.push(num);

        }

    }



    while(!op.empty()){

        process(val, op.top());

        op.pop();

    }



    int ans = val.top();

    val.pop();

    return ans;

}



int main(){

    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ifstream cin("evaluare.in");

    ofstream cout("evaluare.out");



    string s;

    cin >> s;

    cout << evaluare(s);



    return 0;

}
