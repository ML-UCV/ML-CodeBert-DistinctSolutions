#include <fstream>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int N, pow = 1;

int v[30005], sol[30005];

int aib[30005];



inline int LastBit(int x)

{

    return x & (-x);

}



void Update(int pos, int value)

{

    for(int i = pos; i <= N; i += LastBit(i))

        aib[i] += value;

}



int Search(int pos)

{

    int cursor = 0;

    int step = pow;



    for(; step > 0; step >>= 1)

        if(cursor + step <= N && aib[cursor + step] < pos)

        {

            cursor += step;

            pos -= aib[cursor];



            if(pos == 0)

                break;

        }



    return cursor + 1;

}



int main()

{

    fin >> N;

    for(; pow <= N; pow <<= 1);



    for(int i = 1; i <= N; i++)

        Update(i, 1);



    for(int i = 1; i <= N; i++)

        fin >> v[i];



    for(int i = N; i >= 1; i--)

        {

            int resSearch = Search(v[i]);



            sol[resSearch] = i;

            Update(resSearch, -1);

        }



    for(int i = 1; i <= N; i++)

        fout << sol[i] << '\n';



    return 0;

}
