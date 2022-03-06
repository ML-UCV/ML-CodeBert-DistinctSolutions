#include <fstream>
#include <cstring>
#include <queue>
using namespace std;



ifstream fin("strmatch.in");



ofstream fout("strmatch.out");



char a[2000005];



char b[2000005];



int c[20000005];



queue <int> coada;



int k = 0;



void pattern(char *pat, int M, int *lps)



{



 int len = 0;



 lps[0] = 0;



 int i = 1;



 while (i < M)



 {



  if (pat[i] == pat[len])



  {



   len++;



   lps[i] = len;



   i++;



  }



  else



  {



   if(len!=0)



   len = lps[len - 1];



   else



   {



    c[i] = 0;



    i++;



   }



  }



 }



}



void KMP(char *pat,char *txt)



{



 int M = strlen(pat);



 int N = strlen(txt);



 pattern(pat, M, c);



 int i = 0;



 int j = 0;



 while (i < N)



 {



  if (pat[j] == txt[i])



  {



   i++;



   j++;



  }



  if (j == M)



  {



   if (k < 1000)



   {



    coada.push(i - j);







   }



   k++;



   j = c[j - 1];



  }



  else



   if (i < N && pat[j] != txt[i])



   {



    if (j != 0)



     j = c[j - 1];



    else



     i++;



   }



 }



}



int main()



{



 fin.getline(a, 2000005);



 fin.getline(b, 2000005);



 KMP(a, b);



 fout << k << "\n";



 while (!coada.empty())



 {



  fout << coada.front() << " ";



  coada.pop();



 }



 return 0;



}
