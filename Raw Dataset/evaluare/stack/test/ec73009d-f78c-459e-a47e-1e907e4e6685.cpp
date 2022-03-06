#include <fstream>
#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;


ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

char e[100005];
int n;

int priority(char o){
    if(o == '+' || o == '-')
        return 1;
    if(o == '*' || o == '/')
        return 2;
    return 0;
}

int compute(int a, int b, int o){
    if(o == '+')
        return a + b;
    if(o == '-')
        return a - b;
    if(o == '*')
        return a * b;
    if(o == '/')
        return a / b;
}

int eval(){
    int i = 0;
    stack <char> op;
    stack <int> val;
    while(i < n){
        if(e[i] == '('){
            op.push(e[i]);
           }
        else if(e[i] == ')'){
            while(!op.empty() && op.top() != '('){
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                char o = op.top();
                op.pop();
                val.push(compute(val1, val2, o));
            }
            op.pop();
        }
        else if(isdigit(e[i])){
            int v = 0;
            while(i < n && isdigit(e[i])){
                v = (v * 10) + (e[i] - '0');
                ++i;
            }
            --i;
            val.push(v);
        }
        else{
            while(!op.empty() && priority(op.top()) >= priority(e[i])){
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                char o = op.top();
                op.pop();
                val.push(compute(val1, val2, o));
            }
            op.push(e[i]);
        }
        ++i;
    }
    while(!op.empty()){
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        char o = op.top();
        op.pop();
        val.push(compute(val1, val2, o));
    }
    return val.top();
}

int main(){

    fin.getline(e, 100005);
    n = strlen(e);
    fout << eval();
    fin.close();
    fout.close();
    return 0;
}
