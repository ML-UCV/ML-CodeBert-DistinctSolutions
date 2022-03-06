#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



char ch1[50005],ch2[50005];

int poz[26][21000];

int us2[26],us[26];

int p[50005];

int sol;



int _mergeSort(int arr[], int temp[], int left, int right);

int merge(int arr[], int temp[], int left, int mid, int right);







int mergeSort(int arr[], int array_size)

{

    int *temp = (int *)malloc(sizeof(int)*array_size);

    return _mergeSort(arr, temp, 0, array_size - 1);

}







int _mergeSort(int arr[], int temp[], int left, int right)

{

  int mid, inv_count = 0;

  if (right > left)

  {





    mid = (right + left)/2;







    inv_count = _mergeSort(arr, temp, left, mid);

    inv_count += _mergeSort(arr, temp, mid+1, right);





    inv_count += merge(arr, temp, left, mid+1, right);

  }

  return inv_count;

}







int merge(int arr[], int temp[], int left, int mid, int right)

{

  int i, j, k;

  int inv_count = 0;



  i = left;

  j = mid;

  k = left;

  while ((i <= mid - 1) && (j <= right))

  {

    if (arr[i] <= arr[j])

    {

      temp[k++] = arr[i++];

    }

    else

    {

      temp[k++] = arr[j++];





      inv_count = inv_count + (mid - i);

    }

  }







  while (i <= mid - 1)

    temp[k++] = arr[i++];







  while (j <= right)

    temp[k++] = arr[j++];





  for (i=left; i <= right; i++)

    arr[i] = temp[i];



  return inv_count;

}





int main()

{

    freopen("swap.in" ,"r" ,stdin);

    freopen("swap.out","w" ,stdout);

    scanf("%s\n%s\n",&ch1,&ch2);



    int len2 = strlen(ch2);

    for(int i= 0 ;i< len2; ++i){

        ++us2[ ch2[i]-'a' ];

        poz[ ch2[i]-'a' ][us2[ch2[i]-'a'] ] = i+1;

    }

    int len = strlen(ch1);

    if(len != len2){

        printf("-1");

        return 0;

    }

    for(int i=0;i<len;++i){

        ++us[ch1[i]-'a'];

        p[ i ] = poz[ ch1[i]-'a' ][ us[ch1[i]-'a'] ];

        if( !p[i] ){

            printf("-1");

            return 0;

        }





    }



    sol = mergeSort(p,len);
    printf("%d",sol);



    return 0;

}
