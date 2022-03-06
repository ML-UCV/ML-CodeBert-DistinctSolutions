#include <fstream>
#include <string>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int PlusMinus(int &p);

int ProdCat(int &p);

int ParantezeNumere(int &p);



string s;



int PlusMinus(int &p)

{

    int ans = ProdCat(p);



    while((s[p] == '+' || s[p] == '-') && p < s.size())

    {

        int semn;



        if(s[p] == '+')

            semn = 1;

        else

            semn = -1;



        p++;

        ans += semn * ProdCat(p);

    }



    return ans;

}



int ProdCat(int &p)

{

    int ans = ParantezeNumere(p);



    while((s[p] == '*' || s[p] == '/') && p < s.size())

    {

        int op;



        if(s[p] == '*')

            op = 1;

        else

            op = -1;



        p++;



        if(op == 1)

            ans *= ParantezeNumere(p);

        else

            ans /= ParantezeNumere(p);

    }



    return ans;

}



int ParantezeNumere(int &p)

{

    int ans = 0;



    if(s[p] == '(')

    {

        p++;

        ans = PlusMinus(p);

        p++;

    }

    else

    {

        while(isdigit(s[p]) && p < s.size())

            ans = ans * 10 + s[p] - '0', p++;

    }



    return ans;

}



int main()

{

    fin >> s;



    int p = 0;

    fout << PlusMinus(p) << '\n';



    return 0;

}
