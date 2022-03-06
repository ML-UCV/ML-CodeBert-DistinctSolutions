#include <bits/stdc++.h>


using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

const int NMAX = 4000003;

string s,s1,s2;

int Pi[NMAX],afis[1001];

int i,n,now,r,q,j,cnt;

int main() {

    in>>s1>>s2;

    s=" "+s1+"#"+s2;

    n=s.size();

    r=0;

    for(i=2;i<=n;i++) {

        now=Pi[i-1];

        while(now>0&&s[now+1]!=s[i])

            now=Pi[now];

        if(s[now+1]==s[i])

            now++;

        Pi[i]=now;

        if(i>s1.size()+1&&Pi[i]==s1.size()){

            cnt++;

            if(cnt<=1000)

                afis[cnt]=i-2*s1.size()-1;

        }

    }

    out<<cnt<<"\n";

    for(int i=1;i<=min(cnt,1000);i++)

        out<<afis[i]<<" ";

    return 0;

}
