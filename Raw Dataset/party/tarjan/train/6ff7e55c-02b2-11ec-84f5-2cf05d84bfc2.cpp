#include<fstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<ctime>


std::ifstream in("party.in");

std::ofstream out("party.out");



int N, M;



struct data

{

 int x;

 int y;

 int type;

};



int v[2000];



struct data d[2000];



int check(int i)

{

 if(d[i].type==0)

  return v[d[i].x] || v[d[i].y];

 else if(d[i].type == 1)

  return v[d[i].x] || ! v[d[i].y];

 else if(d[i].type == 2)

  return v[d[i].y] || ! v[d[i].x];

 else

  return !v[d[i].x] || !v[d[i].y];







}



void randomly(int i)

{

 if(rand()%2 == 0)

  v[d[i].x] = !v[d[i].x];

 else

  v[d[i].y] = !v[d[i].y];

}



void read()

{



 in>>N>>M;



 for(int j=1;j<=M;j++)

  in>>d[j].x>>d[j].y>>d[j].type;



 for(int j=1;j<=N;j++)

  v[j] = 1;

}



void calculate()

{

 int i;

 while(true)

 {

  for(i=1;i<=M;i++)

   if(check(i)==0)

   {

    randomly(i);

    break;

   }



  if(i==M+1)

   break;

 }

}



void print()

{

 int NR = 0;

 for(int i=1;i<=N;i++)

  if(v[i] == 1)

   NR++;



 out<<NR<<"\n";



 for(int i=1;i<=N;i++)

  if(v[i] == 1)

   out<<i<<"\n";

}



int main()

{

 read();



 calculate();



 print();







}
