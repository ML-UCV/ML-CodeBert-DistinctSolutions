#include <iostream>
#include <fstream>
#include <string.h>




using namespace std;



const char iname[] = "swap.in";

const char oname[] = "swap.out";



char s1[50006], s2[50006];

int i, j, k, m, n, P[50006], val, sol;

int sum[3 * 50006], Sigma[27][50006], last[50006], last2[50006], Sigma2[27][50006];



ifstream fin(iname);

ofstream fout(oname);



void update(int nod, int left, int right)

{

 if(left == right)

 {

  sum[nod] = 1;

  return;

 }

 else

 {

  int middle = (left + right) >> 1;

  if(val <= middle)

   update(2 * nod, left, middle);

  else

   update(2 * nod + 1, middle + 1, right);

 }

 sum[nod] = sum[2 * nod] + sum[2 * nod + 1];

}



void query(int nod, int left, int right, int lm, int rm)

{

 if(lm <= left && right <= rm)

 {

  sol = sol + sum[nod];

  return;

 }

 else

 {

  int middle = (left + right) >> 1;

  if(lm <= middle)

   query(2 * nod, left, middle, lm, rm);

  if(middle < rm)

   query(2 * nod + 1, middle + 1, right, lm, rm);

 }

}



int main()

{

 fin.getline(s1, 50006);

 fin.getline(s2, 50006);

 n = strlen(s1);

 m = strlen(s2);

 m = strlen(s2);

 for(i = 0; i < n; i ++)

  Sigma[s1[i] - 'a'][last[s1[i] - 'a']++] = i + 1;



 for(i = 0; i < m; i ++)

  Sigma2[s2[i] - 'a'][last2[s2[i] - 'a']++] = i + 1;

 for(i = 0; i <= 29; i ++)

 {

   if(last[i] != last2[i])

   {

    fout << "-1\n";

    exit(0);

   }

   for(j = 0; j < last[i]; j ++)

     P[Sigma[i][j]] = Sigma2[i][j];

 }



 for(i = n; i >= 1; i --)

 {

  val = P[i];

  update(1, 1, n);

  query(1, 1, n, 1, val);

 }

 if(sol == 1)

  fout << "1\n";

 else

  fout << sol - n << "\n";

 return 0;

}
