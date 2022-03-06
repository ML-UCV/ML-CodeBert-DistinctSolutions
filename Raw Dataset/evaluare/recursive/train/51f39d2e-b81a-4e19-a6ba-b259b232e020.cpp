#include <bits/stdc++.h>
#include <fstream>


using namespace std;



ifstream fin("evaluare.in"); ofstream fout("evaluare.out");







string s;

int i, ans;







int sum();

int product();

int parantheses();



int sum(){

    int ans = product();

    while (s[i] == '+' || s[i] == '-'){

        if (s[i] == '+'){

            i++;

            ans += product();

        } else {

            i++;

            ans -= product();

        }

    }

    return ans;

}



int product(){

    int ans = parantheses();

    while (s[i] == '*' || s[i] == '/'){

        if (s[i] == '*'){

            i++;

            ans *= parantheses();

        } else {

            i++;

            ans /= parantheses();

        }

    }

    return ans;



}



int parantheses(){

    int ans = 0;



    if (s[i] == '('){

        i++;

        ans = sum();

        i++;

    }

    else {

        while (i < s.size() && '0' <= s[i] && s[i] <= '9'){

            ans *= 10;

            ans += s[i] - '0';

            i++;

        }

    }

    return ans;

}





int main() {



    fin >> s;

    fout << sum();

    return 0;

}
