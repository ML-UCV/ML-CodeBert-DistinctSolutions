#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

int A, B, X, Y;

void Modular_Inverse(int &X, int &Y, int A, int B)
{
    if (B==0)
        X=1, Y=0;
    else
    {
        Modular_Inverse(X, Y, B, A % B);
        int AUX=X;
        X=Y;
        Y=AUX-Y*(A / B);
    }
}

int main()
{
    fin >> A >> B;
    Modular_Inverse(X, Y, A, B);
    X%=B;
    if (X<0)
        X+=B;
    fout << X << '\n';
    fin.close();
    fout.close();
    return 0;
}
