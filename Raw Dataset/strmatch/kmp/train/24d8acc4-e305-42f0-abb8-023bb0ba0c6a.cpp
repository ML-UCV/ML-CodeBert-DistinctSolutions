#include <bits/stdc++.h>
using namespace std;



const int N = 2e6 + 10;



int a[2 * N];

string A , B;

vector < int > start;



signed main()

{



  ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , freopen("strmatch.in" , "r" , stdin) , freopen("strmatch.out" , "w" , stdout);





    cin >> A;

    cin >> B;



    int ans = 0 , M = A.size();



    A += "#" + B;



    for(int i = 1 ; i < A.size() ; i++)

    {

        int j = a[i - 1];



        while(j && A[j] != A[i])

            j = a[j - 1];



        a[i] = j + (A[j] == A[i]);



        if(a[i] == M)

            start.push_back(i - M + 1);

    }



    cout << start.size() << '\n';



    for(int i = 0 ; i < min(1000 , (int)start.size()) ; i++)

        cout << start[i] - M - 1 << ' ';



    return 0;

}
