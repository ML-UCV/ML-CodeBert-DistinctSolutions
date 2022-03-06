#include <fstream>	
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

const int DIM = 1e5;


int l;
char s[DIM + 5];
long long SumaDif(int &p);
long long ProdCat(int &p);
long long ParantezeVal(int &p);



long long SumaDif(int &p)
{

    long long res = ProdCat(p);
    while(p <= l && (s[p] == '+' || s[p] == '-')) {

        if(s[p] == '+')

            p++, res += ProdCat(p);

        else

            p++, res -= ProdCat(p);
    }
    return res;

}



long long ProdCat(int &p)
{
 long long res = ParantezeVal(p);
    while(p <= l && (s[p] == '*' || s[p] == '/')) {
        if(s[p] == '*')
            p++, res *= ParantezeVal(p);
        else
            p++, res /= ParantezeVal(p);

    }
    return res;

}
long long ParantezeVal(int &p)
{

    if(s[p] == '(')
        {
            p++;
            long long res = SumaDif(p);
            p++;
            return res;

        }
    long long nr = 0;
    while(isdigit(s[p])) {
        nr = nr * 10LL + (s[p] - '0');
        p++;
    }
    return nr;
}
int main()
{

    fin >> s; l = strlen(s) - 1;
    int p = 0;
    fout << SumaDif(p) << '\n';
    return 0;

}
