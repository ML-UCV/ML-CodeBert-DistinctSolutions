#include<fstream>
#include<cstring>


using namespace std;



int pi[4000009];

char s[4000009],a[2000009];



ifstream cin("strmatch.in");

ofstream cout("strmatch.out");



void fpi(int n){

    int now=0;

    for(int i=2;i<=n;i++){

        while(s[now+1]!=s[i]&&now>0)

            now=pi[now];

        if(s[now+1]==s[i])

            now++;

        pi[i]=now;

    }

}



int main () {

int l1,l2,n,nrap=0;

cin.getline(s+1,2000010);



cin.getline(a,2000009);

l1=strlen(s+1);

l2=strlen(a);

strcat(s+1,"#");

strcat(s+1,a);

n=l1+l2+1;



fpi(n);



for(int i=1;i<=n;i++)

    if(pi[i]==l1)

        nrap++;

cout<<nrap<<endl;

int minap=0;

for(int i=1;i<=n;i++)

    if(pi[i]==l1&&minap<1000)

        minap++,cout<<i-2*l1-1<<" ";





return 0;

}
