#include<fstream>


using namespace std;

ifstream f ("stramosi.in");

ofstream g ("stramosi.out");



int t[28][250049],i,j,n,m,v[29],q,query,p,afisat=-1,val,corespondent;

int cauta(int q)

{

    int st=0,dr=18,mij=(st+dr)/2;

    while(st<=dr)

    {

        if(v[mij]<=q && v[mij+1]>q)

        {

            return mij;

        }

        else

        {

            if(v[mij]<=q)

                st=mij+1;

            else

                dr=mij-1;

        }

       mij=(st+dr)/2;

    }

   return -1;

}

int main()

{

 f>>n>>query;

 for(i=1;i<=n;i++)

      f>>t[0][i];

 v[0]=1;

 for(i=1;i<=18;i++)

 {

     for(j=1;j<=n;j++)

        t[i][j]=t[i-1][t[i-1][j]];

  v[i]=v[i-1]*2;

 }

 while(query)

 {

     f>>q>>p;

     query--;

     afisat=0;

     while(p!=0)

     {

         val=cauta(p);

         if(val==-1)

             g<<0<<'\n',p=1,afisat=1;

         else

         {

             p=p-v[val];

             q=t[val][q];

         }

     }

      g<<q<<'\n';

 }

}
