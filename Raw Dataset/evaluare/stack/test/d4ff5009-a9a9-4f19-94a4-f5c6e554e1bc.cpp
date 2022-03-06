#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int l, nr, i;

string s;

stack<char> obj;

stack<int> numb;



void calc_nr();

void test_nr();



int main()

{



    fin >> s;

    l = s.length();



    for(i = 0; i < l; ++i){

        if(s[i] >= '0' && s[i] <= '9'){

            calc_nr();

            test_nr();

        }

        else if(s[i] == ')'){

            nr = numb.top();

            numb.pop();

            while(obj.top() != '('){

                nr += numb.top(); numb.pop();

                obj.pop();

            }

            obj.pop();



            test_nr();

        }

        else obj.push(s[i]);

    }



    nr = numb.top(); numb.pop();

    while(obj.size()){

        nr += numb.top(); numb.pop();

        obj.pop();

    }



    numb.push(nr);



    fout << numb.top();



    return 0;

}



void calc_nr(){

    nr = 0;

    while(i < l && s[i] >= '0' && s[i] <= '9'){

        nr = nr * 10 + (s[i] - '0');

        ++i;

    }



    --i;

}



void test_nr(){



    if(obj.size()){

        if(obj.top() == '*'){

            int other = numb.top(); numb.pop();

            obj.pop();

            numb.push(nr * other);

        }

        else if(obj.top() == '/'){

            int other = numb.top(); numb.pop();

            obj.pop();

            numb.push(other / nr);

        }

        else if(obj.top() == '-'){

            obj.pop(); obj.push('+');

            numb.push(-nr);

        }

        else numb.push(nr);

    }

    else numb.push(nr);



}
