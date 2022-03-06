#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include <string>




using namespace std;



int b,n;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void invers(int a,int b,int &x,int &y)

{

   if(!b)

   {

      x = 1;

      y = 0;

   }

   else

   {

      int x0,y0;

      invers(b,a%b,x0,y0);

      {

         x = y0;

         y = x0 - a/b * y0;

      }

   }

}



int main()

{

   fin>>b>>n;

   int x,y;



   invers(b,n,x,y);

   while(x<0)

      x+=n;

   fout<<x;



}
