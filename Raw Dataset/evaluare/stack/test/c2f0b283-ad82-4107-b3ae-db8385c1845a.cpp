#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
using namespace std;



const int N = 1e5;



char sti[5 + N];

int sir[5 + N];

int v[5 + N];



bool is_operator(char ch) {

    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');

}



int rang(char ch) {

    if(ch == '+' || ch == '-') return 1;

    return 2;

}



int operator_to_int(char ch) {

    if(ch == '+') return -1;

    if(ch == '-') return -2;

    if(ch == '*') return -3;

    if(ch == '/') return -4;

}



int main() {

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    char ch(' '), chprev(' ');

    int vf(0), nr(0);

    while(ch != '\n') {

        ch = getchar();

        if(ch != '\n') {

            if(ch == '(') sti[++vf] = '(';

            else if(ch == ')') {

                if(chprev >= '0' && chprev <= '9') sir[++sir[0]] = nr;

                while(vf > 0 && sti[vf] != '(') {

                    sir[++sir[0]] = operator_to_int(sti[vf]);

                    vf--;

                }

                vf--;

                nr = 0;

            } else if(is_operator(ch)) {

                if(chprev >= '0' && chprev <= '9') sir[++sir[0]] = nr;

                while(vf > 0 && sti[vf] != '(' && rang(sti[vf]) >= rang(ch)) {

                    sir[++sir[0]] = operator_to_int(sti[vf]);

                    vf--;

                }

                sti[++vf] = ch;

                nr = 0;

            } else

                nr = nr * 10 + ch - '0';

            chprev = ch;

        }

    }

    if(nr > 0) sir[++sir[0]] = nr;

    nr = 0;

    while(vf > 0) {

        sir[++sir[0]] = operator_to_int(sti[vf]);

        vf--;

    }



    vf = 0;

    for(int i = 1; i <= sir[0]; i++){

        if(sir[i] < 0){

            if(sir[i] == -1)

                v[vf - 1] += v[vf];

            else if(sir[i] == -2)

                v[vf - 1] -= v[vf];

            else if(sir[i] == -3)

                v[vf - 1] *= v[vf];

            else if(sir[i] == -4)

                v[vf - 1] /= v[vf];

            vf--;

        }

        else v[++vf] = sir[i];

    }

    printf("%d\n", v[1]);

    return 0;

}
