#include <fstream>
#include <string>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int SumDif(int &pos);

int ProdCat(int &pos);

int BracketVal(int &pos);



string S;



int SumDif(int &pos)

{

    int ans = ProdCat(pos);



    while(pos < (int)S.size() && (S[pos] == '+' || S[pos] == '-'))

    {

        pos++;



        if(S[pos - 1] == '+')

            ans += ProdCat(pos);

        else

            ans -= ProdCat(pos);

    }



    return ans;

}



int ProdCat(int &pos)

{

    int ans = BracketVal(pos);



    while(pos < (int)S.size() && (S[pos] == '*' || S[pos] == '/'))

    {

        pos++;



        if(S[pos - 1] == '*')

            ans *= BracketVal(pos);

        else

            ans /= BracketVal(pos);

    }



    return ans;

}



int BracketVal(int &pos)

{

    if(S[pos] == '(')

    {

        pos++;

        int res = SumDif(pos);

        pos++;



        return res;

    }



    int nr = 0;



    while(isdigit(S[pos]) && pos < (int)S.size())

    {

        nr = nr * 10 + (S[pos] - '0');

        pos++;

    }



    return nr;

}



int main()

{

    fin >> S;



    int pos = 0;

    fout << SumDif(pos) << '\n';



    return 0;

}
