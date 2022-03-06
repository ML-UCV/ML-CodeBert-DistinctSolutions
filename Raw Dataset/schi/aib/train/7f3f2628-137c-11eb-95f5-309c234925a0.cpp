#include <fstream>


using namespace std;

ifstream cin("schi.in");

ofstream cout("schi.out");

int aib[30005],n,i,v[30005],solutie[30005];

void Update(int x,int quantity){

    int i;



    for(i = x;i <= n;i+=(i ^ (i-1)) & i){

        aib[i] += quantity;

    }

}

int sum(int x){

    int i,sol = 0;

    for(i = x;i > 0;i -= (i ^ (i-1)) & i){

        sol += aib[i];

    }

    return sol;

}

int bs(int val){

    int pas = 1 << 14;

    int r = 0;

    while(pas){

        if(r+pas <= n && aib[r+pas] < val){

            val-=aib[r+pas];

            r+=pas;

        }

        pas/=2;

    }

    return r+1;

}

int main()

{

    cin >> n;

    for(i = 1;i <= n;i++){

        cin >> v[i];

    }

    for(i = 1;i <= n;i++){

        Update(i,1);

    }

    for(i = n;i >= 1;i--){

        int x = bs(v[i]);

        Update(x,-1);

        solutie[x] = i;

    }

    for(i = 1;i <= n;i++){

        cout << solutie[i] << "\n";

    }

    return 0;

}
