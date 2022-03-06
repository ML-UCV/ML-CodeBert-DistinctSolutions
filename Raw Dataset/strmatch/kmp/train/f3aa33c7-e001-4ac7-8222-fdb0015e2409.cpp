#include <bits/stdc++.h>


using namespace std;
char sir[2000005],pat[2000005];

int pref[2000005],sol[2000005];



void calculare_prefix_table(int n){

    int k=0,i;

    pref[1]=0;

    for(i=2;i<=n;i++){

        while(k>0 && (pat[k+1]!=pat[i]))

            k=pref[k];

        if(pat[k+1]==pat[i])

            k++;

        pref[i]=k;

    }

};



int main()

{

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");

    int n,m,i,s,k;

    cin>>pat+1;

    n=strlen(pat+1);

    cin>>sir+1;

    m=strlen(sir+1);

    calculare_prefix_table(n);

    k=0;

    s=0;

    for(i=1;i<=m;i++){

        while(k>0 && (pat[k+1]!=sir[i]))

            k=pref[k];

        if(pat[k+1]==sir[i])

            k++;

        if(k==n){

            k=pref[k];

            s++;

            if(s<=1000)

                sol[s]=i-n;

        }

    }

    cout<<s<<'\n';

    for(i=1;i<=min(s,1000);i++)

        cout<<sol[i]<<" ";

    return 0;

}
