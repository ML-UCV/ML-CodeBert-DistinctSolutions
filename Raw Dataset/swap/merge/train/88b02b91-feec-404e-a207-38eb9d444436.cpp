#include <fstream>
#include <cstring>


using namespace std;



int N,v[50005],b[50005],c[50005],sol,L[30][50000];

char s1[50005],s2[50005];



inline void Read()

{

    int i,n;

    ifstream fin("swap.in");

    fin.getline(s1,50005);fin.getline(s2,50005);

    n=strlen(s2);

    for(i=n-1;i>=0;i--)

        L[s2[i]-'a'][++L[s2[i]-'a'][0]]=i;



    n=strlen(s1);

    for(i=0;i<n;i++)

        if(!L[s1[i]-'a'][0])

            sol=-1;

        else

            v[++N]=L[s1[i]-'a'][L[s1[i]-'a'][0]--];

    fin.close();

}



inline void Merge(int a[], int left, int right)

{

    int i,j,n1,n2;

    n1=0;

    for(i=left;i<=(left+right)/2;i++)

        b[++n1]=a[i];

    n2=0;

    for(i=(left+right)/2+1;i<=right;i++)

        c[++n2]=a[i];

    N=left-1;

    i=j=1;

    while(i<= n1 && j<= n2)

        if(b[i]<=c[j])

            a[++N]=b[i++];

        else

        {

            a[++N]=c[j++];

            sol=sol+n1-i+1;

        }

    while(i<= n1)

        a[++N]=b[i++];

    while(j<= n2)

        a[++N]=c[j++];

}



inline void MergeSort(int a[], int left, int right)

{

    if(left==right)

        return ;

    MergeSort(a,left,(left+right)/2);

    MergeSort(a,(left+right)/2+1,right);

    Merge(a,left,right);

}



inline void Write()

{

    ofstream fout("swap.out");

    fout<<sol<<"\n";

    fout.close();

}



int main()

{

    Read();

    if(sol>=0)

        MergeSort(v,1,N);

    Write();

    return 0;

}
