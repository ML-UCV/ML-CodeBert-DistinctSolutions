#include <cstdio>
#include <vector>
using namespace std;



int vf1[26],vf2[26];
char v1[50000 +1],v2[50000 +1];
int aib[50000 +1];
int last[26];
vector <int> P[26];
inline void update(int poz){
   int i;
   for(i=poz;i<=50000;i+=(i&(-i)))
     aib[i]++;
}
inline int query(int poz){
   int i,sum;
   sum=0;
   for(i=poz;i>0;i-=(i&(-i)))
     sum+=aib[i];
   return sum;
}
int main(){
   FILE*fi,*fout;
   int n1,n2,poz,i,ans;
   char a;
   fi=fopen("swap.in" ,"r");
   fout=fopen("swap.out" ,"w");
   a=fgetc(fi);
   n1=0;
   while(a!='\n'){
      a-='a';
      vf1[a]++;
      v1[++n1]=a;
      a=fgetc(fi);
   }
   a=fgetc(fi);
   n2=0;
   while(a!='\n'){
      a-='a';
      vf2[a]++;
      v2[++n2]=a;
      P[a].push_back(n2);
      a=fgetc(fi);
   }
   i=0;
   while(i<26&&vf1[i]==vf2[i])
     i++;
   if(i<26)
      fprintf(fout,"-1");
   else{
      ans=0;
      for(i=1;i<=n1;i++){
         poz=P[v1[i]][last[v1[i]]];
         ans+=(poz+i-1-query(poz-1))-i;
         last[v1[i]]++;
         update(poz);
      }
      fprintf(fout,"%d" ,ans);
   }
   fclose(fi);
   fclose(fout);
   return 0;
}
