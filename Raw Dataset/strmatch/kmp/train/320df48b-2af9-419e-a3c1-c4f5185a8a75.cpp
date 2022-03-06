#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char pattern[2000001], text[2000001],*p;

int lps[2000001],len,n,nr,v[2000001];



void LPS()

{

     n=strlen(pattern);

lps[0]=0;

int i=1;

  while(i<n)

  {

      if(pattern[i]==pattern[len])

      {

      len++;

      lps[i]=len;

      i++;

      }

      else

          if(len!=0)

        len=lps[len-1];

        else

            lps[i++]=0;

  }

}



void afisare()

 {



    printf("%d\n", nr);

    if(nr>1000)

        nr=1000;

   for(int i=0;i<nr;++i)

    printf("%d ", v[i]);



}



int main()

{

   freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

  scanf("%s\n%s", &pattern, &text);

  int i=0,j=0;

  int m=strlen(text);

  LPS();

  while(i<m)

  {

     if(text[i]==pattern[j])

        i++,j++;

     else

     if(j!=0)

        j=lps[j-1];

     else

        i++;

     if(j==n)

     {

        v[nr++]=i-j;

         j=lps[j-1];

     }



  }



  afisare();



    return 0;

}
