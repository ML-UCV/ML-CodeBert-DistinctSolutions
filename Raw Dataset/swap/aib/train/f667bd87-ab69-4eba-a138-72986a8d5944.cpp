#include <algorithm>#include <cstring>
#include <stdio.h>
#include <vector>
using namespace std;



int sol;

char strInit[50024], strMod[50024];

int aibAp[50024];

vector <int> vctPoz[26];



inline int aibSum(int x)

{

 int sum = 0;



 for (int i = x; i; i -= (i ^ (i & (i - 1))))

  sum += aibAp[i];



 return sum;

}



inline void aibAdd(int x, int val)

{

 for (int i = x; i < 50024; i += (i ^ (i & (i - 1))))

  aibAp[i] += val;

}





int main()

{

 freopen("swap.in", "r", stdin);

 freopen("swap.out", "w", stdout);



 fgets(strInit + 1, 50024, stdin);

 fgets(strMod + 1, 50024, stdin);



 int n = strlen(strInit + 1) - 1;

 for (int i = 1; i <= n; i++)

  vctPoz[strInit[i] - 'a'].push_back(i);



 for (int i = n; i; i--)

 {

  int loc = vctPoz[strMod[i] -'a'].size();

  if (!loc)

  {

   sol = -1;



   break;

  }

  int poz = vctPoz[strMod[i] - 'a'][loc - 1];

  vctPoz[strMod[i] - 'a'].pop_back();



  sol += aibSum(poz);

  aibAdd(poz, 1);

 }



 printf("%d\n", sol);



 fclose(stdin);

 fclose(stdout);

 return 0;

}
