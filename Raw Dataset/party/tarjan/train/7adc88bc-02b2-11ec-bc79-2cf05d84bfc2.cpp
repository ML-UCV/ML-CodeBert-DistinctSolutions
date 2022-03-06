#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



const int NMAX = 1010;

const int MMAX = 10010;



int N, M;

int Bl[MMAX][4];

int val[NMAX];



void citire()

{

 cin >> N >> M;

 for(int i = 1 ; i <= M ; i++)

  cin >> Bl[i][1] >> Bl[i][2] >> Bl[i][0];

}



bool corect(int rel, int x, int y)

{

 switch(rel)

 {

 case 0: return(x || y);

 case 1: return(x || (!x && !y));

 case 2: return(y || (!y && !x));

 case 3: return(!x || !y);

 }

}



bool dif_zero()

{

 for(int i = 1 ; i <= N ; i++)

  if(val[i])

   return 1;

 return 0;

}



void rezolva()

{

 int gasit, esuat;

 srand(time(NULL));

 for(int i = 1 ; i <= N ; i++)

  val[i] = rand()%2;

 for(int i = 1 ; i <= 50 * N ; i++)

 {

  gasit = 1; esuat = 1;

  for(int j = 1 ; j <= M ; j++)

   if(!corect(Bl[j][0], val[Bl[j][1]], val[Bl[j][2]]))

   {

    gasit = 0;

    esuat = j;

    break;

   }

  if(gasit == 1 && dif_zero())

   return;

  if(rand() % 2 + 1 == 1)

   val[Bl[esuat][1]] ^= 1;

  else

   val[Bl[esuat][2]] ^= 1;

 }



}



void scriere()

{

 int NR = 0;

 for(int i = 1 ; i <= N ; i++)

  if(val[i])

   NR++;

 printf("%d\n", NR);

 for(int i = 1 ; i <= N ; i++)

  if(val[i])

   printf("%d\n", i);

}



int main()

{

 freopen("party.in", "r", stdin);

 freopen("party.out", "w", stdout);

 citire();

 rezolva();

 scriere();

 return 0;

}
