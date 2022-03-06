#include <fstream>
#include <vector>
#include <iostream>


using namespace std;



vector<int> nums;

int temp[100000];



long long merge(vector<int> &arr, int left, int right) {

    int mid = (right + left) / 2;

    int i = left, j = mid + 1, k = left;

    long long inv_count = 0;



    while(i <= mid && j <= right) {

        if(arr[i] <= arr[j]) {

            temp[k++] = arr[i++];

        } else {

            temp[k++] = arr[j++];

            inv_count += (mid - i + 1) % 9917;

        }

    }



    while(i <= mid)

        temp[k++] = arr[i++];



    while(j <= right)

        temp[k++] = arr[j++];



    for(i = left; i <= right; i++)

        arr[i] = temp[i];



    return inv_count % 9917;

}



long long mergeSort(vector<int> &arr, int left, int right) {

    long long inv_count = 0;

    int mid;



    if(right > left) {

        mid = (right + left) / 2;



        inv_count += mergeSort(arr, left, mid);

        inv_count += mergeSort(arr, mid + 1, right);



        inv_count += merge(arr, left, right);

    }



    return inv_count % 9917;

}



int main() {

    ifstream fin("inv.in");

    ofstream fout("inv.out");



    int n;



    fin >> n;

    for(int i = 0; i < n; i++) {

        int x;

        fin >> x;

        nums.push_back(x);

    }



    fout << mergeSort(nums, 0, n - 1);

}
