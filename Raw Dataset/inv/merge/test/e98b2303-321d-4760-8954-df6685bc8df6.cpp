#include <iostream>
#include <fstream>


const int MAXN = 1e5 + 5,MOD = 9917;



using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



int n,v[MAXN],aux[MAXN],ans = 0;

pair<int,int> nume[MAXN];



void combina(int left,int mid,int right){

    int i = left,j = mid + 1,index = left - 1;

    while(i <= mid and j <= right){

        while(v[i] > v[j] and j <= right){

            aux[++index] = v[j];

            j++;

            ans += mid - i + 1;

        }

        while(v[j] >= v[i] and i <= mid){

            aux[++index] = v[i];

            i++;

        }

    }

    while(i <= mid)

        aux[++index] = v[i++];

    while(j <= right)

        aux[++index] = v[j++];

    for(int i = left; i <= right; i++)

        v[i] = aux[i];

    ans %= MOD;

}

void divide(int left = 1,int right = n){

    if(left == right)

        return;

    int mid = (left + right) / 2;

    divide(left,mid);

    divide(mid + 1,right);

    combina(left,mid,right);

}



int main()

{

    in>>n;

    for(int i = 1; i <= n; i++)

        in>>v[i];

    divide();

    out<<ans<<"\n";

    return 0;

}
