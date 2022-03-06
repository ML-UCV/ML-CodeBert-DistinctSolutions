#include <bits/stdc++.h>




using namespace std;



char A[2000005], B[2000005];

vector<int> v;



int pr[2000005];



int main()

{

    ios_base::sync_with_stdio(0);

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    cin.getline(A + 1, 2000005);

    cin.getline(B + 1, 2000005);



    int lg1 = strlen(A + 1), lg2 = strlen(B + 1);

    int k = 0;

    for(int i = 2; i <= lg1; ++i){

        while(k > 0 && A[k + 1] != A[i])

            k = pr[k];

        if(A[i] == A[k + 1])

            ++k;

        pr[i] = k;

    }



    k = 0;

    int cnt = 0;

    for(int i = 1; i <= lg2; ++i){

        while(k > 0 && A[k + 1] != B[i])

            k = pr[k];

        if(A[k + 1] == B[i])

            ++k;

        if(k == lg1){

            k = pr[lg1];

            if(v.size() < 1000)

                v.push_back(i - lg1);

            ++cnt;

        }

    }



    cout << cnt << '\n';

    for(auto it: v)

        cout << it << ' ';

    cout << '\n';

    return 0;

}
