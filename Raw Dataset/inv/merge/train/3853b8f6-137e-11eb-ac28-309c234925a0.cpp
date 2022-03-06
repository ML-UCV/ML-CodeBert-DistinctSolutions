#include<cstdio>

using namespace std;

const int MOD = 9917;
int v[100000], n;

long long Merge(int arr[], int aux[], int left, int mid, int right) {
    int i, j, k = 0;
    long long inv_count = 0;
    i = left, j = mid, k = left;
    while(i <= mid-1 && j <= right) {
        if(arr[i] <= arr[j])
            aux[k++] = arr[i++];
        else {
            aux[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while(i <= mid-1)
        aux[k++] = arr[i++];
    while(j <= right)
        aux[k++] = arr[j++];
    for(i=left; i<=right; i++)
        arr[i] = aux[i];
    return inv_count;
}

long long mergeSort(int arr[], int aux[], int left, int right) {
    long long inv_count = 0;
    if(left < right) {
        int mid = (left + right) >> 1;
        inv_count = mergeSort(arr,aux,left,mid);
        inv_count += mergeSort(arr,aux,mid+1,right);
        inv_count += Merge(arr,aux,left,mid+1,right);
    }
    return inv_count;
}

int main() {
    long long ans;
    int aux[100000];
    FILE *fin, *fout;
    fin = fopen("inv.in","r");
    fout = fopen("inv.out","w");
    fscanf(fin,"%d",&n);
    for(int i=0; i<n; i++)
        fscanf(fin,"%d",&v[i]);
    ans = mergeSort(v,aux,0,n-1);
    fprintf(fout,"%lld\n",ans%MOD);
    fclose(fin);
    fclose(fout);
    return 0;
}
