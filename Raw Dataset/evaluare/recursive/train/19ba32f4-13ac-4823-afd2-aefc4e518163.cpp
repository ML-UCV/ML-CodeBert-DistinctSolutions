#include <bits/stdc++.h>


using namespace std;



string s;

int eval();

int termen();

int factor();

int p;



int eval(){

    int val = termen();

    while(s[p] == '+' || s[p] == '-'){

        if(s[p] == '+'){

            p++;

            val += termen();

        }

        else{

            p++;

            val -= termen();

        }

    }

    return val;

}



int termen(){

    int val = factor();

    while(s[p] == '*' || s[p] == '/'){

        if(s[p] == '*'){

            p++;

            val *= factor();

        }

        else{

            p++;

            val /= factor();

        }

    }

    return val;

}



int factor(){

    int semn = 1, val = 0;

    while(s[p] == '-'){

        semn = -semn;

        p++;

    }

    if(s[p] == '('){

        p++;

        val = eval();

        p++;

        return val * semn;

    }

    while(isdigit(s[p])){

        val = val * 10 + s[p] - '0';

        p++;

    }

    return val * semn;

}



int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    getline(fin, s);

    fout << eval();

    return 0;

}
