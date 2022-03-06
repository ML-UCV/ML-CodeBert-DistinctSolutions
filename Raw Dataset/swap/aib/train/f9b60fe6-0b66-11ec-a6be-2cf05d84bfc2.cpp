#include <fstream>
#include <queue>

using namespace std;
queue <int> q[30];
int f1[30],f2[30];
int aib[50005],n;
void upd(int a){
    for(;a<=n;a+=(a&(-a))){
        aib[a]++;
    }
}
int que(int a){
    int sol=0;
    for(;a>=1;a-=(a&(-a))){
        sol+=aib[a];
    }
    return sol;
}
ifstream cin("swap.in");
ofstream cout("swap.out");
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    n=s2.size();
    if(n!=s2.size()){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++){
        f1[s1[i]-'a']++;
        f2[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    if(f1[i]!=f2[i]){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++){
        q[s2[i]-'a'].push(i+1);
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        int a=q[s1[i]-'a'].front();
        q[s1[i]-'a'].pop();
        sum+=i-que(a-1);
        upd(a);
    }
    cout<<sum;
    return 0;
}
