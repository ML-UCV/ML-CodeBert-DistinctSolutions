#include <fstream>
#include <vector>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



const int Mod = 9917;



int inv;



void merge(vector <int> &Arr, int lft, int mid, int rgt) {



 int i = lft;

 int j = mid + 1;



 vector <int> mergedArr;

 mergedArr.reserve(rgt - lft + 1);



 while (i <= mid and j <= rgt)

  if (Arr[i] <= Arr[j])

   mergedArr.push_back(Arr[i++]);

  else {



   inv += mid - i + 1;

   inv %= Mod;



   mergedArr.push_back(Arr[j++]);

  }



 while (i <= mid) mergedArr.push_back(Arr[i++]);

 while (j <= rgt) mergedArr.push_back(Arr[j++]);



 for (int idx = lft, mergedArrIdx = 0; idx <= rgt; ++idx, ++mergedArrIdx)

  Arr[idx] = mergedArr[mergedArrIdx];

}



void mergeSort(vector <int> &Arr, int lft, int rgt) {



 if (rgt == lft)

  return;

 else {



  int mid = (lft + rgt) / 2;



  mergeSort(Arr, lft, mid);

  mergeSort(Arr, mid + 1, rgt);

  merge(Arr, lft, mid, rgt);

 }

}



int main() {



 int n;

 fin >> n;



 vector <int> Arr(n);

 for (int &itm : Arr)

  fin >> itm;



 mergeSort(Arr, 0, n - 1);



 fout << inv;

}
