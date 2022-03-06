#include <iostream>
#include <fstream>

using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");

int a,n;

int phi(int n)
{
    int p = n;
    int i,j,cnt = 0;
    int sus = 1,jos = 1;
    for (i=2; i*i<=n; i++)
    {
        if (n%i == 0)
        {
           while (n%i == 0)
           {
               n /= i;
           }
           sus *= (i-1);
           jos *= i;
       }
    }
    if (n != 1)
    {
       sus *= (n-1);
       jos *= n;
    }
    return p/jos*sus;
}

int ridica(int a,int p)
{
    int rasp = 1;
    while (p != 0)
    {
       if (p%2 == 0)
       {
          a = (long long)a*a%n;
          p /= 2;
       }
       else
       {
          rasp = (long long)rasp*a%n;
          p--;
       }
    }
    return rasp;
}

int main()
{
    in >> a >> n;

    out << ridica(a,phi(n)-1);
    return 0;
}
