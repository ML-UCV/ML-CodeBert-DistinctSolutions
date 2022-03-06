#include <iostream>
#include <fstream>


std::ifstream f;

long merge(long arr[], long left, long mid, long right)

{

 long count = 0;

 long i, j, k;



 long n1 = mid - left + 1;

 long n2 = right - mid;



 long* L = new long[n1];

 long* R = new long[n2];



 for (i = 0; i < n1; i++)

  L[i] = arr[left + i];



 for (j = 0; j < n2; j++)

  R[j] = arr[mid + 1 + j];
 k = left;

 i = 0;

 j = 0;



 while (i < n1 && j < n2)

 {

  if (L[i] <= R[j]) {

   arr[k] = L[i];

   i++;



  }

  else {

   arr[k] = R[j];

   j++;

   count += n1 - i;

  }

  k++;

 }



 while (i < n1)

 {

  arr[k++] = L[i++];

 }



 while (j < n2)

 {

  arr[k++] = R[j++];

 }



 delete[] L;

 delete[] R;



 return count;

}

long mergeSort(long arr[], long left, long right)

{

 if (left == right)

  return 0;

 long inv_count = 0;

 if (left < right)

 {

  long mid = (left + right) / 2;



  inv_count += mergeSort(arr, left, mid);

  inv_count += mergeSort(arr, mid + 1, right);



  inv_count += merge(arr, left, mid, right);

 }

 return inv_count;

}



int main()

{

 long n, a[100010];



 f.open("inv.in");



 f >> n;

 for (long i = 0; i < n; i++)

  f >> a[i];

 f.close();



 std::ofstream g("inv.out");

 long solutie = mergeSort(a, 0, n - 1);

 g << solutie % 9917;



 g.close();



 return 0;

}
