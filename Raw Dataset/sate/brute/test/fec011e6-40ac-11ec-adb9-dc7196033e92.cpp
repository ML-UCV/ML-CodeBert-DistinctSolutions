#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
struct muchie{
  int x,c;
};
vector <muchie> v[30001];
int a,b,n,m,x,y,k1,k2,q[90000001],viz[30001],j,S,i,d,ns;
char s[1001];
void coada(int x){
    int p,u,i,l;
    p=u=1;
    q[p]=x;
    viz[x]=1;
    while(p<=u){
        l=q[p];
        p++;
        for(i=0;i<v[l].size();i++)
            if(viz[v[l][i].x]==0)
                if(v[l][i].x!=y){
                u++;
                q[u]=v[l][i].x;
                if(v[l][i].x<l)
                    viz[v[l][i].x]=viz[l]-v[l][i].c;
                else
                    viz[v[l][i].x]=viz[l]+v[l][i].c;

            }
            else{
                if(v[l][i].x==y)
                    if(v[l][i].x<l)
                    viz[v[l][i].x]=viz[l]-v[l][i].c;
                else
                    viz[v[l][i].x]=viz[l]+v[l][i].c;
                 p=u+1;
                 break;
            }}}
int main()
{
    fin.getline(s,999);
	ns=strlen(s);
	n=s[0]-'0';
	i=1;
	while(s[i]>='0'&&s[i]<='9'){
		n=n*10+(s[i]-'0');
		i++;}
	i++;
	m=s[i]-'0';
	i++;
	while(s[i]>='0'&&s[i]<='9'){
		m=m*10+(s[i]-'0');
		i++;}
	i++;
	x=s[i]-'0';
	i++;
	while(s[i]>='0'&&s[i]<='9'){
		x=x*10+(s[i]-'0');
		i++;}
	i++;
	y=s[i]-'0';
	i++;
	while(s[i]>='0'&&s[i]<='9'&&i<ns){
		y=y*10+(s[i]-'0');
		i++;}
	for(i=1;i<=m;i++){
		fin.getline(s,999);
		ns=strlen(s);
		a=s[0]-'0';
		j=1;
		while(s[j]>='0'&&s[j]<='9'){
			a=a*10+(s[j]-'0');
			j++;
		}
		j++;
		b=s[j]-'0';
		j++;
		while(s[j]>='0'&&s[j]<='9'){
			b=b*10+(s[j]-'0');
			j++;
		}
		j++;
		d=s[j]-'0';
		j++;
		while(s[j]>='0' && s[j]<='9' && j<ns)
		{
			d=d*10+(s[j]-'0');
			j++;
		}
       v[a].push_back({b,d});
       v[b].push_back({a,d});
    }
    S=0;
 coada(x);
 viz[y]--;
    fout<<viz[y];
    return 0;
}
