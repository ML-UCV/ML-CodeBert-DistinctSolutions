#include<bits/stdc++.h>




using namespace std;



int getSum(int BITree[], int index)

{

    int sum = 0;

    while (index > 0)

    {

        sum += BITree[index];

        index -= index & (-index);

    }

    return sum;

}





void updateBIT(int BITree[], int n, int index, int val)

{

    while (index <= n)

    {

       BITree[index] += val;

       index += index & (-index);

    }

}



void convert(int arr[],int n)

{

    int lst[n];

    for(int i=1;i<=n;i++)

        lst[i]=arr[i];

    sort(lst+1,lst+n+1);

    for(int i=1;i<=n;i++)

        arr[i]=lower_bound(lst+1,lst+n+1,arr[i])-lst;

}



int getInvCount(int arr[], int n)

{

    int invcount = 0;

    convert(arr,n);

    int maxElement = 0;

    for (int i=1; i<=n; i++)

        if (maxElement < arr[i])

            maxElement = arr[i];



    int BIT[maxElement+1];

    for (int i=1; i<=maxElement; i++)

        BIT[i] = 0;



    for (int i=n; i>0; i--)

    {

        invcount += getSum(BIT, arr[i]-1);

        invcount%=9917;

        updateBIT(BIT, maxElement, arr[i], 1);

    }



    return invcount;

}



int main()

{

    int arr[100000],n;

    ifstream fin("inv.in");

    fin>>n;

    for(int i=1;i<=n;i++)

        fin>>arr[i];

    fin.close();

    ofstream fout("inv.out");

    fout<<getInvCount(arr,n)%9917;

    fout.close();



}
