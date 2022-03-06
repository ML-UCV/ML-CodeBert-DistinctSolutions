#include <bits/stdc++.h>


using namespace std;



int poz,l;

char sir[100010];



int number()

{

    int s=0;

    for(;sir[poz]>='0' && sir[poz]<='9';poz++) s=s*10+sir[poz]-'0';

    return s;

}



int solve()

{

    int ans=0,p=1;

    if(sir[poz]=='-') {p=-1;poz++;}

    while(poz<l && sir[poz]!=')')

    {

        if(sir[poz]=='+') {ans+=p;p=1;poz++;}

        else if(sir[poz]=='-') {ans+=p;p=-1;poz++;}

        else

        {

            int x,t=0;

            if(sir[poz]=='*') {poz++;t=0;}

            else if(sir[poz]=='/') {poz++;t=1;}

            if(sir[poz]=='(') {poz++;x=solve();}

            else x=number();

            if(t) p/=x;

            else p*=x;

        }

    }

    ans+=p;

    poz++;

    return ans;

}



int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    scanf("%s",sir);

    l=strlen(sir);

    printf("%d",solve());

    return 0;

}
