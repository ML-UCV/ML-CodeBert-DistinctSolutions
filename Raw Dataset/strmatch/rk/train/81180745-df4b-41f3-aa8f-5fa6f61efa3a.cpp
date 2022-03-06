#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstring>


using namespace std;



ifstream cin("strmatch.in");

ofstream cout("strmatch.out");







char pat[2000001],sir[2000001];

int poz[2000001];

int main()

{

    int m1=666013;

    int m2=800057;

    int p=72,p1,p2,h1,h2,la,lb,i,s,H1,H2;

    cin>>pat;

    cin>>sir;

    la=strlen(pat);

    lb=strlen(sir);

    p1=p2=1;

    h1=h2=0;

    for(i=0;i<la;i++){

        h1=(h1*p+pat[i])%m1;

        h2=(h2*p+pat[i])%m2;

        if(i>=1){

            p1=(p1*p)%m1;

            p2=(p2*p)%m2;

        }

    }

    if(la>lb){

        cout<<0<<'\n';

        return 0;

    }

    H1=H2=0;

    for(i=0;i<la;i++){

        H1=(H1*p+sir[i])%m1;

        H2=(H2*p+sir[i])%m2;

    }

    s=0;

    if(h1==H1 && h2==H2){

        s++;

        poz[s]=0;

    }

    for(i=la;i<lb;i++){

        H1=((H1-(sir[i-la]*p1)%m1+m1)*p+sir[i])%m1;

        H2=((H2-(sir[i-la]*p2)%m2+m2)*p+sir[i])%m2;

        if(h1==H1 && h2==H2){

            s++;

            poz[s]=i-la+1;

        }

    }

    cout<<s<<'\n';

    s=min(s,1000);

    for(i=1;i<=s;i++)

        cout<<poz[i]<<" ";

    return 0;

}
