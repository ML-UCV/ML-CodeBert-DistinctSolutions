#include <iostream>
#include <fstream>
#include <bitset>
#include <math.h>
#include <vector>
using namespace std;



int mat [250005][20];

int currentRow;

vector<int> vec;



void MakeRow(int newRow, int index);

int GetResult(int row, int index);



int main()

{

 ifstream fin("stramosi.in");

 ofstream fout("stramosi.out");

 int n, m;

 fin >> n >> m;



 for (int i = 1; i <= n; i++)

 {

     int a;

     currentRow = i;

  fin >> a;

        MakeRow(a,0);

 }



 for (int i = 1; i <= m; i++)

    {

        int q, p;

        fin >> q >> p;

        bitset<20> bin(p);

        vec.clear();

        for(int j = 0; j < 20; j++)

        {

            if(bin[j] == 1)

            {

                vec.push_back(j);



            }

        }



        fout << GetResult(q, 0) << "\n" ;

    }
}



int GetResult(int row, int index)

{

    int newRow = mat[row][vec[index]];

    if(index == vec.size() - 1)

        return newRow;

    return GetResult(newRow,index+1);

}



void MakeRow(int newRow, int index)

{

    mat[currentRow][index] = newRow;

    if(newRow!=0)

        MakeRow(mat[newRow][index], index+1);

}
