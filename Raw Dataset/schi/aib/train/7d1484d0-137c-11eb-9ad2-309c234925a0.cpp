#include<fstream>
using namespace std;

ifstream cin("schi.in");

ofstream cout("schi.out");

int Poz[30005],Arb[30005],Sol[30005],n;



void Update(int p,int val){



    while(p<=n){



        Arb[p]+=val;

        p+=p&-p;



    }



}



int Query(int p){



    int s=0;

    while(p>0){



        s+=Arb[p];

        p-=p&-p;



    }



    return s;



}



int SearchPosition(int val) {



    int left=1,right=n,middle;



    while(right-left>1){



        middle=(left+right)/2;



        if(Query(middle)<val)



            left=middle;



        else



            right=middle;



    }



    if(Query(left)==val) return left;

    if(Query(right)==val) return right;



}



int main(){



    cin>>n;



    for(int i=1;i<=n;i++)

        cin>>Poz[i];



    for(int i=1;i<=n;i++)

        Update(i,1);



    for(int i=n;i>=1;i--){



        int index=SearchPosition(Poz[i]);

        Update(index,-1);

        Sol[index]=i;



    }



    for(int i=1;i<=n;i++)

        cout<<Sol[i]<<'\n';



}
