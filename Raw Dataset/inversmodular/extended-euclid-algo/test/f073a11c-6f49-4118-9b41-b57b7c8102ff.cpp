#include<fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void euclid(int a, int b, int& x, int& y)

{

 if (b == 0)

 {

  x = 1, y = 1;

 }

 else

 {

  int x1, y1;

  euclid(b, a%b, x1, y1);

  x = y1;

  y = x1 - a / b * y1;

 }

}



int main()

{

 int A, N;

 fin >> A >> N;

 int x, y;

 euclid(A, N, x, y);

 while (x < 0)

  x += N;

 fout << x;

 fin.close(), fout.close();

 return 0;



}
