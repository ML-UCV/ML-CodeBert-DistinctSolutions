#include <bits/stdc++.h>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int step = 0;

string expresie;



long eval();



long factor(){

    int r = 0;



    if(expresie[step]=='('){

        step++;

        r = eval();

        step++;

    }

    else{

        while(expresie[step]<='9' && expresie[step]>='0'){

            r = r*10 + expresie[step] - '0';

            step++;

        }

    }



    return r;

}



long termen(){

    int r = factor();



    while(expresie[step]=='*' || expresie[step]=='/'){

        switch(expresie[step]){

        case '*':

            step++;

            r *= factor();

            break;

        case '/':

            step++;

            r /= factor();



        }

    }



    return r;

}



long eval(){

    int r = termen();



    while(expresie[step]=='+' || expresie[step]=='-'){

        switch(expresie[step]){

        case '+':

            step++;

            r+=termen();

            break;



        case '-':

            step++;

            r-=termen();

            break;

        }

    }



    return r;



}

int main()

{



    getline(fin, expresie, '\n');



    fout<<eval();



}
