#include<cstdio>
#include<cstring>
#include<vector>


using namespace std;



const char iname[]="swap.in";

const char oname[]="swap.out";

const int maxn=100005;



vector<int> a[300];



char s[maxn],m[maxn];



int n,i,j,k,v,many[300];



int aib[maxn*2];



void update(int nod,int left,int right,int pos,int value)

{

    if(left==right)

    {

        aib[nod]=value;

        return;

    }

    int mid=(left+right)>>1;

    if(pos<=mid)

        update(nod<<1,left,mid,pos,value);

    else

        update((nod<<1)+1,mid+1,right,pos,value);

    aib[nod]=aib[nod<<1]+aib[(nod<<1)+1];

}



int query(int nod,int left,int right,int start,int finish)

{

    if(start<=left&&right<=finish)

        return aib[nod];



    int mid=(left+right)>>1,k=0;

    if(start<=mid)

        k+=query(nod<<1,left,mid,start,finish);

    if(mid<finish)

        k+=query((nod<<1)+1,mid+1,right,start,finish);

    return k;

}



int main()

{

    freopen(iname,"r",stdin);

    freopen(oname,"w",stdout);



    fgets(s,sizeof(s),stdin);

    fgets(m,sizeof(m),stdin);

    n=strlen(s);

    if(s[n-1]=='\n')

        s[--n]=0;

    for(i=n-1;i>=0;--i)

        a[s[i]].push_back(i);



    for(i=0;i<n;++i)

        ++many[m[i]];

    for(i='a';i<='z';++i)

        if(many[i]!=a[i].size())

        {

            printf("-1\n");

            fclose(stdin);

            fclose(stdout);



            return 0;

        }



    for(i=0;i<n;++i)

        update(1,0,n-1,i,1);

    for(i=0;i<n;++i)

    {

        v=a[m[i]].back();

        a[m[i]].pop_back();

        if(v>0)

            k+=query(1,0,n-1,0,v-1);

        update(1,0,n-1,v,0);

    }



    printf("%d\n",k);



    fclose(stdin);

    fclose(stdout);



    return 0;

}
