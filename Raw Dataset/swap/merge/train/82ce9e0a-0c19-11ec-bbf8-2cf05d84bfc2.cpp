#include<fstream>
#include<cstring>


using namespace std;

int lit[50001], poz[30][50001],l,nr2[30],nr1[30],v[50001],x,u,ok;

char s1[50001],s2[50001];

long long s;

ifstream fin("swap.in");

ofstream fout("swap.out");



void citire()

{

    fin>>s1>>s2;

}



void permutare()

{

    l=strlen(s2);

    for(int i=0;i<l;i++)

    {

        poz[s2[i]-'a'][++nr2[s2[i]-'a']]=i+1;

    }

    for(int i=0;i<l;i++)

    {

        lit[i+1]=poz[s1[i]-'a'][++nr1[s1[i]-'a']];

        if(lit[i+1]==0)

        {

            fout<<-1;

            ok=1;

            return;

        }

    }

}



void interclasare(int st,int m,int dr)

{

    int k=0;

    int i=st;

    int j=m+1;

    while(i<=m && j<=dr)

    {

        if(lit[i]<lit[j])

        {

            k++;

            v[k]=lit[i];

            i++;

        }

        else

        {

            k++;

            v[k]=lit[j];

            j++;

            s+=m-i+1;

        }

    }

    while(i<=m)

    {

        v[++k]=lit[i++];

    }

    while(j<=dr)

    {

        v[++k]=lit[j++];

    }

    memcpy(lit+st,v+1,sizeof(int)*(dr-st+1));

}



void mergeSort(int st,int dr)

{

    int m=(st+dr)/2;

    if(dr==st)

        return;

    if(dr-st==1 && lit[dr]<lit[st])

    {

        swap(lit[dr],lit[st]);

        s++;

        return;

    }

    mergeSort(st,m);

    mergeSort(m+1,dr);

    interclasare(st,m,dr);

}



int main()

{

    citire();

    if(strlen(s1)!=strlen(s2))

    {

        fout<<"-1";

        return 0;

    }

    permutare();

    if(ok==1)

        return 0;

    mergeSort(1,l);

    fout<<s;

   return 0;

}
