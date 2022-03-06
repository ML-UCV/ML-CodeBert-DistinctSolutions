#include <fstream>
using namespace std;

const int maxN=1e5+1;
const int MOD=9917;

int n,sol;
int v[maxN];
int aux[maxN];

void mergeSort(int st,int dr){
    if(st>=dr)
        return;

    int mij=(st+dr)/2;
    mergeSort(st,mij);
    mergeSort(mij+1,dr);

    int leftIdx=st;
    int rightIdx=mij+1;
    int curr=0;

    while(leftIdx<=mij && rightIdx<=dr)
        if(v[leftIdx]<=v[rightIdx]){
            aux[++curr]=v[leftIdx];
            leftIdx++;
        }else{
            aux[++curr]=v[rightIdx];
            rightIdx++;

            sol+=mij-leftIdx+1;
            while(sol>=MOD)
                sol-=MOD;
        }

    while(leftIdx<=mij){
        aux[++curr]=v[leftIdx];
        leftIdx++;
    }

    while(rightIdx<=dr){
        aux[++curr]=v[rightIdx];
        rightIdx++;
    }

    for(int i=st;i<=dr;i++)
        v[i]=aux[i-st+1];
}

int main() {
    ifstream cin("inv.in");
    ofstream cout("inv.out");

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];

    mergeSort(1,n);

    cout<<sol;

    return 0;
}
