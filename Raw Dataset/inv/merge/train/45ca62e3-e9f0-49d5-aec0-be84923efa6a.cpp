#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");

int v[100005];



long long interclasare (int l1,int r1,int l2,int r2)

{

   vector <int> c;

   long long rezultat=0;

   int c_l1=l1,c_l2=l2;

    while (c_l1<=r1&&c_l2<=r2)

    {

        if (v[c_l1]>v[c_l2])

        {

            rezultat+=r1-c_l1+1;

            c.push_back(v[c_l2]);

            c_l2++;

        }

        else

        {

            c.push_back(v[c_l1]);

            c_l1++;

        }

    }

    while (c_l1<=r1)

    {

     c.push_back(v[c_l1]);

            c_l1++;

    }

    while (c_l2<=r2)

    {

        c.push_back(v[c_l2]);

            c_l2++;

    }

    int contor=l1;

    for (int aux : c)

        {v[contor]=aux;

        contor++;}

    return rezultat;

}



long long calcul (int left,int right)

{ int mid=(left+right)/2;

    if (left==right) return 0;



    long long r1=calcul (left,mid);

    long long r2=calcul (mid+1,right);



    long long r3=interclasare(left,mid,mid+1,right);



    return r1+r2+r3;





}



int main()

{

    int n;

    fin>>n;

    for (int i=1;i<=n;i++)

        fin>>v[i];

    fout<<calcul (1,n)%9917;

    return 0;

}
