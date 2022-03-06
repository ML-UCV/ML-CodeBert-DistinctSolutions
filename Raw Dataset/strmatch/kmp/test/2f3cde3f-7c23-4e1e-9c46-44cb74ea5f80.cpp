#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char a[2000009];

char b[2000009];

int lga,lgb;

int vala[2000009];

int valb[2000009];

int k;

int nrs;

vector<int>sol;

void citire();

void strmatch();

void afis();

int main()

{citire();

 strmatch();

 afis();

    return 0;

}

void citire()

{

  fin>>(a+1)>>(b+1);

  lga=strlen(a+1);

  lgb=strlen(b+1);

}



void strmatch()

{

    int i;

    for(i=2;i<=lga;i++)

        {

         while( a[i]!= a[k+1] && k)

               k=vala[k];

         if(a[k+1]==a[i])

            k++;

         vala[i]=k;

        }



     if(a[1]==b[1])

        {valb[1]=1;k=1;}else k=0;

     for(i=2;i<=lgb;i++)

        {

         while(a[k+1]!= b[i] && k)

              k=vala[k];

         if(a[k+1]==b[i])

              k++;

         valb[i]=k;

         if(k==lga )

            {nrs++;

              if(sol.size()<1000)

                    sol.push_back(i-lga);

            }

        }

}

void afis()

{

  int i;

  fout<<nrs<<'\n';

  for(i=0;i< sol.size();i++)

    fout<<sol[i]<<" ";

}
