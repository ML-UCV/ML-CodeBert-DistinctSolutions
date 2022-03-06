#include <cstdio>


using namespace std;

int N, List[100005], VA, VB, A[100005], B[100005], i;

long long int Inv=0LL;

void MSort(int left, int right);

void IClass(int left);

int main()

{

    freopen("inv.in", "r", stdin);

    freopen("inv.out", "w", stdout);

    scanf("%d", &N);

    for(i=1; i<=N; ++i)scanf("%d", &List[i]);

    MSort(1, N);

    printf("%lld", Inv%9917);

    return 0;

}

void MSort(int left, int right){

    if(left==right) return;

    int mid=(left+right)/2;

    MSort(left, mid);

    MSort(mid+1, right);

    int i;

    VA=VB=0;

    for(i=left; i<=mid; ++i) A[++VA]=List[i];

    for(i=mid+1; i<=right; ++i) B[++VB]=List[i];

    IClass(left);

    return;

}

void IClass(int left){

    int i, j;

    i=j=1; --left;

    while(i<=VA && j<=VB){

        if(A[i]>B[j]){

            Inv+=(VA-i+1);

            List[++left]=B[j++];

        }

        else List[++left]=A[i++];

    }

    while(i<=VA)List[++left]=A[i++];

    while(j<=VB)List[++left]=B[j++];

    return;

}
