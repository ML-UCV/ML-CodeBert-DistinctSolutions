#include<bits/stdc++.h>
using namespace std;



const int NMAX=2000005;

int T[NMAX];



queue<int> sol;

string a,b;



void preComp(){

    int i=1,j=0;

    while(i<(int)b.size()){

        if(b[i]==b[j]){

            T[i]=j+1;

            i++,j++;

        }

        else if(j!=0){

            while(j!=0 && b[i]!=b[j])

                j=T[j-1];

        }

        else i++;

    }

}



int main(){

    freopen("strmatch.in","r",stdin);

    freopen("strmatch.out","w",stdout);

    int i=0,j=0,cnt=0;

    cin>>b>>a;

    a.push_back('.');

    preComp();

    while(i<=(int)a.size()){

        if(j>=(int)b.size()){

            if((int)sol.size()<1000)

                sol.push(i-(int)b.size());

            cnt++;

            j=T[j-1];

        }

        if(a[i]==b[j])

            i++,j++;

        else if(j!=0)

            j=T[j-1];

        else i++;

    }

    printf("%d\n", cnt);

    while(!sol.empty()){

        printf("%d ", sol.front());

        sol.pop();

    }

    return 0;

}
