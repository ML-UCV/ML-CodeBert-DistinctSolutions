#include<vector>
#include<cstdio>
#include<cstring>
#include<deque>


using namespace std;

deque <unsigned short int> poz[100];

char unu[50010],doi[50010];

unsigned short int n,a[50010],aib[50010],funu[30],fdoi[30];

void update (unsigned short int pos, unsigned short int val)

{

    for(;pos<=n && pos;pos=pos+(pos&-pos))

        aib[pos]+=val;

}

int query (unsigned short int pos)

{

    int ans=0;

    for(;pos;pos=pos-(pos&-pos))

        ans+=aib[pos];

    return ans;

}



int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    int i,nswap;

    fgets(unu, 50001, stdin); fgets(doi, 50001, stdin);

    n=strlen(doi);

    for(i=0;i<n;i++)

        {

            poz[doi[i]-'a'].push_back(i+1);

            funu[unu[i]-'a']++;

            fdoi[doi[i]-'a']++;

        }

    for(i=0;i<=26;i++)

        if(funu[i]!=fdoi[i])

            {

                printf("-1\n");

                return 0;

            }



    for(i=0;i<n;i++)

        {

            a[i+1]=poz[unu[i]-'a'].front();

            poz[unu[i]-'a'].pop_front();

        }

    nswap=0;

    for(i=1;i<=n;i++)

        {

            nswap+=query(n)-query(a[i]);

            update(a[i],1);

        }

    printf("%d\n",nswap);

    return 0;

}
