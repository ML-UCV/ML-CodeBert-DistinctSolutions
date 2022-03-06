#include<fstream>
using namespace std;

ifstream cin("stramosi.in");

ofstream cout("stramosi.out");

int str[250005],dp[250005][18];

int N,M,Q,P,p,nr;

int main(){



    cin>>N>>M;



    for(int i=1;i<=N;i++)

        cin>>dp[i][0];



        for(int i=1;i<=N;i++)

            for(int k=1;k<=17;k++)

                if(dp[i][k-1])

                    dp[i][k]=dp[dp[i][k-1]][k-1];

                else break;



    for(int i=1;i<=M;i++){



        cin>>Q>>P;



        for(p=1,nr=0;p<=P;p<<=1,++nr)

            if(P&p)

                Q=dp[Q][nr];



        cout<<Q<<'\n';



    }



}
