#include<cstdio>
#include<cstring>




using namespace std;

int n;

int aib[50010],v[50010];

int countA[30],countB[30],first[30][50010];

char a[50010],b[50010];

void Update(int x){

    for(x;x<=n;x=x+((x&(x-1))^x))

        aib[x]++;

}

int Query(int x){

    int answer=0;

    for(x;x>0;x=x-((x&(x-1))^x))

        answer+=aib[x];

    return answer;

}

int main(){

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    int i;

    long long answer=0;

    scanf("%s%s",a,b);

    n=strlen(a);

    for(i=0;i<n;i++){

        first[a[i]-'a'][countA[a[i]-'a']]=i;

        countA[a[i]-'a']++;

        countB[b[i]-'a']++;

    }

    for(i=0;i<26&&countA[i]==countB[i];i++)

        countB[i]=0;

    if(i<26){

        printf("-1");

        return 0;

    }

    for(i=0;i<n;i++){

        v[first[b[i]-'a'][countB[b[i]-'a']]]=i+1;

        countB[b[i]-'a']++;

    }

    for(i=n-1;i>=0;i--){

        answer+=Query(v[i]);

        Update(v[i]);

    }

    printf("%lld",answer);

    return 0;

}
