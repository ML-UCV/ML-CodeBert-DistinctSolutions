#include <bits/stdc++.h>



using namespace std;

ifstream in("strmatch.in");
ofstream out("strmatch.out");

int z[4000010];


int main()
{
 string a,b;
 in>>a>>b;
 int n=a.size();
 string rez=a+"#"+b;
 int lung=rez.length();
 lung++;
 int st=0,dr=0;
 for(int i=1;i<lung;i++)
 {
  if(i>dr)
  {
   st=i;
   dr=i;
   while(rez[dr]==rez[dr-st] && dr<=lung)
    dr++;
   z[i]=dr-st;
   dr--;
  }
  else
  {
   if(z[i-st]+i-1<dr)
    z[i]=z[i-st];
   else
   {
    st=i;
    while(rez[dr]==rez[dr-st] && dr<=lung)
     dr++;
    z[i]=dr-st;
    dr--;
   }
  }
 }
 int ct=0;
 for(int i=1;i<lung;i++)
  if(z[i]==n)
   ct++;
 out<<ct<<"\n";
 ct=0;
 for(int i=1;i<lung;i++)
 {
  if(z[i]==n)
  {
   ct++;
   if(ct<=1000)
    out<<i-n-1<<" ";
  }
 }
 return 0;
}
