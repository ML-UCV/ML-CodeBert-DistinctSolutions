#include <iostream>
#include <fstream>
using namespace std;

int v1[100001], v2[100001], nr;



void intercl(int left, int mid, int right)

{

    int i = left, j = mid + 1, k = 0;



    while(i <= mid and j <= right)

    {

        if(v1[i] <= v1[j])

            v2[k ++] = v1[i ++];

        else

        {

            nr += mid - i + 1;

            nr = nr % 9917;

            v2[k ++] = v1[j ++];

        }

    }



    while(i <= mid) v2[k ++] = v1[i ++];

    while(j <= right) v2[k ++] = v1[j ++];



    for(k = left; k <= right; k ++)

        v1[k] = v2[k - left];

}



void mergesort(int left, int right)

{

    int mid;



    if(left < right)

    {

        mid = (left + right) / 2;



        mergesort(left, mid);

        mergesort(mid + 1, right);



        intercl(left, mid, right);

    }

}

int main()

{

  ifstream f("inv.in");

  ofstream g("inv.out");

    int n, i;

    f>> n;

    for (i=0;i<n;i++)

        f>>v1[i];

mergesort(0,n-1);





g<<nr;

return 0;

}
