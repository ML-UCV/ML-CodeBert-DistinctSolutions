#include <iostream>
#include <fstream>


using namespace std;

int aib[30001],index[30001],v[30001],N,poz;
void update(int poz,int val)

{

    int i;

 for(i=poz;i<=N;i+=(i&(-i)))

 {

  aib[i]+=val;

 }

}

int sum(int poz)

{

 int s=0,i;

 for(i=poz;i>=1;i-=(i&(-i)))

    {

  s+=aib[i];

    }

 return s;

}

int cautare(int st,int dr,int k)

{
    int val,poz,mij;

    while(st<=dr)

    {

        mij=(st+dr)/2;

        val=sum(mij);



        if(val>=v[k])

        {

            poz=mij;

            dr=mij-1;

        }

        else

        {

            st=mij+1;

        }

    }

    return poz;

}

int main()

{

    ifstream fin("schi.in");

    ofstream fout("schi.out");

    int i;

 fin>>N;

 for(i=1;i<=N;i++)

 {

  fin>>v[i];

  update(i,1);

 }

 for(i=N;i>=1;i--)

 {

  poz=cautare(1,N,i);

  index[poz]=i;

  update(poz,-1);

 }

 for(i=1;i<=N;i++)

    {

  fout<<index[i]<<'\n';

    }

    fin.close();

    fout.close();

    return 0;

}
