#include <bits/stdc++.h>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char ss[100001];



int main(){



    f >> ss;

    stack <int> st, ops;



    for(int i = 0;ss[i];){



        if(isdigit(ss[i])){

            int Nr = 0;

            while(isdigit(ss[i]))

                Nr = Nr * 10 + (ss[i] - '0'), i++;

            st.push(Nr);

            i--;

        }



        if(ss[i] == '+') {i++; ops.push(1); continue;}

        if(ss[i] == '-') {i++; ops.push(1); st.push(-1); ops.push(3); continue;}

        if(ss[i] == '*') {i++; ops.push(3); continue;}

        if(ss[i] == '/') {i++; ops.push(4); continue;}

        if(ss[i] == '(') {i++; ops.push(5); continue;}



        if(ss[i] == ')') {

            while(ops.top() != 5){

                int Nr = st.top();

                st.pop();

                st.top() += Nr;

                ops.pop();

            }

            ops.pop();

        }





        while(!ops.empty() && (ops.top() == 3 || ops.top() == 4)){



            int Nr = st.top();

            st.pop();

            if(ops.top() == 3) st.top() *= Nr;

            if(ops.top() == 4) st.top() /= Nr;

            ops.pop();

        }



        i++;

    }



    long long answ = 0;

    while(!st.empty()){

        answ += st.top();

        st.pop();

        ops.pop();

    }



    g << answ;



}
