#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <assert.h>
#include <fstream>






using namespace std;

using ll = long long;





ifstream cin("evaluare.in"); ofstream cout("evaluare.out");
string s;







bool isOp(char c) {

    return c == '+' || c == '-' || c == '/' || c == '*';

}



int priority(char op) {

    if (op == '/' || op == '*') return 2;

    if (op == '-' || op == '+') return 1;

    return -1;

}



void process_op(stack <int>& st, char op) {

    int r = st.top(); st.pop();

    int l = st.top(); st.pop();



    switch (op) {

        case '+': st.push(l + r); break;

        case '-': st.push(l - r); break;

        case '/': st.push(l / r); break;

        case '*': st.push(l * r); break;

    }

}



int evaluate(string& s) {

    stack <int> st;

    stack <char> op;



    for (int i = 0; i < (int)s.size(); i++) {



        if (s[i] == '(') {

            op.push('(');

        }

        else if (s[i] == ')') {

            while (op.top() != '(') {

                process_op(st, op.top());

                op.pop();

            }

            op.pop();

        }

        else if (isOp(s[i])) {

            char curr_op = s[i];

            while (!op.empty() && priority(op.top()) >= priority(curr_op)) {

                process_op(st, op.top());

                op.pop();

            }

            op.push(curr_op);

        }

        else {



            int num = 0;

            while (i < (int)s.size() && isalnum(s[i]))

                num = num * 10 + s[i++] - '0';

            --i;

            st.push(num);

        }

    }



    while (!op.empty()) {

        process_op(st, op.top());

        op.pop();

    }

    return st.top();

}







int main() {



    cin >> s;

    cout << evaluate(s);



    return 0;

}
