#include<stdio.h>
int n,m,i,j,k,a,b,cod,ad[201][201],nr,t[201],mt,cont,step;

int cauta();

int main()

{

 FILE *f,*g;

 f=fopen("party.in","r");

 g=fopen("party.out","w");

 fscanf(f,"%d%d",&n,&m);

 for(i=1;i<=m;i++)

 { fscanf(f,"%d%d%d",&a,&b,&cod);

   if(cod==0){ ad[a+n][b]=1;ad[b+n][a]=1;}

   if(cod==1){ ad[a+n][b+n]=1;ad[b][a]=1;}

   if(cod==2){ ad[a][b]=1;ad[b+n][a+n]=1;}

   if(cod==3){ ad[a][b+n]=1;ad[b][a+n]=1;}

 }

 for(i=1;i<=2*n;i++)

 { cont=1;step=1;

   while(cont)

    { cont=0;

       for(j=1;j<=2*n;j++)

        if(ad[i][j]==step)

  for(k=1;k<=2*n;k++)

   if(ad[j][k])

    if(!ad[i][k])

     {ad[i][k]=step+1;cont++;}

     step++;

    }

 }

 mt=0;

 while(mt<n)

 { for(i=1;i<=n;i++)

     if(!t[i])

      if(!ad[i][n+i])

       { t[i]=1;t[n+i]=-1;mt++;

   for(j=1;j<=n;j++)

    if(ad[i][j]&&!t[j])

     {t[j]=1;t[j+n]=-1;mt++;}

   for(j=n+1;j<=2*n;j++)

    if(ad[i][j]&&!t[j])

     {t[j]=1;t[j-n]=-1;mt++;}

   break;

       }

        }

 nr=n;

 for(i=1;i<=n;i++)

 nr+=t[i];

 nr/=2;

 fprintf(g,"%d\n",nr);

 for(i=1;i<=n;i++)

  if(t[i]==1)

   fprintf(g,"%d\n",i);

 fcloseall();

 return 0;

}
