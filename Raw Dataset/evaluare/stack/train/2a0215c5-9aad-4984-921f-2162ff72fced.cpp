#include <iostream>
#include <vector>




using namespace std;



struct solComp

{

    int num;

    char c;

};



int solve(string s)

{

    vector<solComp> sol;

    vector<int> stiva;



    int n = s.length(), m, i;



    for(i = 0; i < n; i++)

    {

        if(s[i] == '(')stiva.push_back(s[i]);

        else if(s[i] == '*' || s[i] == '/')

        {

            m = stiva.size() - 1;

            while(m >= 0 && (stiva[m] == '*' || stiva[m] == '/') && stiva[m] != '(')

            {

                solComp aux;



                aux.num = -1;

                aux.c = stiva[m];



                sol.push_back(aux);

                stiva.pop_back();

                m--;

            }



            stiva.push_back(s[i]);

        }

        else if(s[i] == '+' || s[i] == '-')

        {

            m = stiva.size() - 1;

            while(m >= 0 && stiva[m] != '(')

            {

                solComp aux;



                aux.num = -1;

                aux.c = stiva[m];



                sol.push_back(aux);

                stiva.pop_back();

                m--;

            }



            stiva.push_back(s[i]);

        }

        else if(s[i] == ')')

        {

            m = stiva.size() - 1;

            while(stiva[m] != '(')

            {

                solComp aux;



                aux.num = -1;

                aux.c = stiva[m];



                sol.push_back(aux);

                stiva.pop_back();

                m--;

            }

            stiva.pop_back();

        }

        else

        {

            int number = s[i] - '0';



            for(i = i + 1; i < n && '0' <= s[i] && s[i] <= '9'; i++)number = number * 10 + s[i] - '0';



            i--;

            solComp aux;



            aux.num = number;

            aux.c = 0;



            sol.push_back(aux);

        }

    }



    m = stiva.size() - 1;



    while(m >= 0)

    {

        solComp aux;



        aux.num = -1;

        aux.c = stiva[m];



        sol.push_back(aux);

        stiva.pop_back();



        m--;

    }



    n = sol.size();



    for(i = 0; i < n; i++)

        if(sol[i].num == -1)

        {

            if(sol[i].c == '/')stiva[m - 1] = stiva[m - 1] / stiva[m];

            else if(sol[i].c == '*')stiva[m - 1] = stiva[m - 1] * stiva[m];

            else if(sol[i].c == '+')stiva[m - 1] = stiva[m - 1] + stiva[m];

            else stiva[m - 1] = stiva[m - 1] - stiva[m];



            m--;



        }

        else

        {

            m++;

            stiva[m] = sol[i].num;

        }



    return stiva[0];

}



int main()

{

    string s;



    freopen("evaluare.in", "r", stdin);

    freopen("evaluare.out", "w", stdout);



    cin >> s;



    cout << solve(s);



    return 0;

}
