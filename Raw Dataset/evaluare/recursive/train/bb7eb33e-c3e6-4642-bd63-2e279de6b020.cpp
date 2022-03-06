#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



typedef long long ll;



string ex;

int idx;



ll eval();

ll termen();

ll factor();



ll eval(){

    ll ans = termen();



    while(ex[idx] == '+' || ex[idx] == '-'){

        if(ex[idx] == '+'){

            idx++;

            ans += termen();

        } else if(ex[idx] == '-'){

            idx++;

            ans -= termen();

        }

    }



    return ans;

}



ll termen(){

    ll ans = factor();



    while(ex[idx] == '*' || ex[idx] == '/'){

        if(ex[idx] == '*'){

            idx++;

            ans *= factor();

        } else if(ex[idx] == '/'){

            idx++;

            ans /= factor();

        }

    }



    return ans;

}



ll factor(){

    ll ans = 0;



    if(ex[idx] == '('){

        idx++;

        ans = eval();

        idx++;

    } else {

        while(ex[idx] >= '0' && ex[idx] <= '9'){

            ans = ans * 10 + (ex[idx] - '0');

            idx++;

        }

    }



    return ans;

}



int main()

{

    fin >> ex;

    fout << eval();



    return 0;

}
