#include <fstream>
#include <cstring>






using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



int n, i;



int stiv_num[100005];

char stiv_sign[100005], x[100005];

int numbers = 0, signs = 0;



int getNr()

{

    int rez = 0;

    for(i = i; i < n && (x[i] >= '0' && x[i] <= '9'); i++)

        rez = rez * 10 + (x[i] - '0');



    i--;

    return rez;

}

void solveParanthese()

{

    int rez = 0;

    while(stiv_sign[signs] != '(')

    {

        int nrNow = stiv_num[numbers];

        numbers--;



        if(stiv_sign[signs] == '+')

            rez += nrNow;

        if(stiv_sign[signs] == '-')

            rez -= nrNow;

        signs--;

    }

    signs--;



    stiv_num[numbers] += rez;

    if(stiv_sign[signs] == '*')

    {

        int nrNow = stiv_num[numbers];

        numbers--; signs--;



        stiv_num[numbers] *= nrNow;

    }

    if(stiv_sign[signs] == '/')

    {

        int nrNow = stiv_num[numbers];

        numbers--; signs--;



        stiv_num[numbers] /= nrNow;

    }

}



int main()

{

    f.getline(x, 100005);

    n = strlen(x);



    stiv_sign[++signs] = '(';

    for(i = 0; i < n; i++)

    {

        if(x[i] == '(')

            stiv_sign[++signs] = '(';



        if(x[i] >= '0' && x[i] <= '9')

        {

            int nrNow = getNr();



            if(stiv_sign[signs] == '*')

            {

                stiv_num[numbers] *= nrNow;

                signs--;

                continue;

            }

            if(stiv_sign[signs] == '/')

            {

                stiv_num[numbers] /= nrNow;

                signs--;

                continue;

            }



            stiv_num[++numbers] = nrNow;

            continue;

        }



        if(x[i] == '*' || x[i] == '/' || x[i] == '+' || x[i] == '-')

            stiv_sign[++signs] = x[i];



        if(x[i] == ')')

            solveParanthese();

    }

    solveParanthese();



    g << stiv_num[1];

    return 0;

}
