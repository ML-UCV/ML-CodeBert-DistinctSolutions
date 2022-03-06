#include<fstream>
#include<vector>
#include<string>


using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");





const int NMAX = 50005;



int i, n, k, j,contor,st,dr,x,y,m;

string a, b;

vector <int> frecB[30], frecA[30];

int v[NMAX];

long long int sol;



void merge(int a[], int stanga, int mij, int dreapta)

{

    int b[500005];

    int x , y , k;

    k = stanga;

    x = stanga;

    y = mij + 1;

    int contor = 0;

    while(x <= mij && y <= dreapta)

    {

        if(a[x] < a[y])

        {

            b[k++] = a[x];

            x++;

            sol = sol + contor;

        }

        else if(a[y] < a[x])

        {

            b[k++] = a[y];

            y++;

            contor++;

        }

        else

        {

            sol = sol + contor;

            contor++;

            b[k++] = a[x];

            b[k++] = a[y];

            x++;

            y++;

        }

    }

    while(x <= mij)

    {

        b[k++] = a[x];

        x++;

        sol = sol + contor;

    }

    while(y <= dreapta)

    {

        b[k++] = a[y];

        y++;

    }

    for(i = stanga; i <= dreapta; i++)

    {

        a[i] = b[i];

    }





}



void mergeSort(int a[], int stanga, int dreapta)

{

    if(stanga < dreapta)

    {

        int mij = (stanga + dreapta) / 2;

        mergeSort(a, stanga, mij);

        mergeSort(a, mij + 1, dreapta);

        merge(a, stanga, mij, dreapta);

    }



}





int main()

{

    fin >> a >> b;



    n = a.length();

    a = ' ' + a;

    b = ' ' + b;

    for(i = 1; i <= n; i++)

    {

        int letter = a[i] - 'a';

        frecA[letter].push_back(i);



        letter = b[i] - 'a';

        frecB[letter].push_back(i);



    }

    bool ok = true;

    for(i = 0; i <= 25; i++)

    {

        if(frecB[i].size() != frecA[i].size())

        {

            ok = false;

        }



        for(j = 0; j < frecB[i].size(); j++)

        {



        }



    }

    if(ok == false)

    {

        fout <<"-1\n";

        return 0;

    }

    else

    {

        for(i = 0; i <= 25; i++)

        {

            frecA[i].clear();

        }

        for(i = 1; i <= n; i++)

        {

            int letter = a[i] - 'a';

            int nr = frecA[letter].size();

            v[i] = frecB[letter][nr];

            frecA[letter].push_back(i);







        }

        sol = 0;

        mergeSort(v, 1, n);

        fout << sol << "\n";

        for(i = 1; i <= n; i++)

        {



        }



    }



}
