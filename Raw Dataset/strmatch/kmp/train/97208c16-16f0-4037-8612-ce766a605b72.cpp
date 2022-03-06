#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;



const int MAX_LENGTH = 2000000;



char a[MAX_LENGTH + 1];

char b[MAX_LENGTH + 1];

char united[2 * MAX_LENGTH + 1];

int pi[2 * MAX_LENGTH];



void calc_pi(char s[]) {

  int n;



  n = strlen(s);

  pi[0] = 0;

  for (int i = 1; i < n; i++) {

    int index = i - 1;



    while (s[i] != s[pi[index]] && index > 0)

      index = pi[index] - 1;



    if (index >= 0 && s[i] == s[pi[index]])

      pi[i] = pi[index] + 1;

    else

      pi[i] = 0;

  }

}



int main() {

  freopen("strmatch.in", "r", stdin);

  freopen("strmatch.out", "w", stdout);



  scanf("%s\n%s", a, b);



  int n1, n2, n;



  n1 = strlen(a);

  n2 = strlen(b);

  n = n1 + 1 + n2;



  for (int i = 0; i < n1; i++)

    united[i] = a[i];



  united[n1] = '*';



  for (int i = 0; i < n2; i++)

    united[n1 + 1 + i] = b[i];





  calc_pi(united);



  vector<int> sol;

  for (int i = 2 * n1; i < n; i++) {

    if (pi[i] == n1)

      sol.push_back(i - 2 * n1);

  }



  printf("%d\n", sol.size());

  for (int i = 0; i < min(1000, (int)sol.size()); i++)

    printf("%d ", sol[i]);

  printf("\n");



  return 0;

}
