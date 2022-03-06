#include<fstream>
#include<cstring>
#include<iostream>






using namespace std;



int i, nr=0, H, H2, has, has2, v[1005];

char m[2000003], n[2000004];

int main()

{

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    cin>>m>>n;

    int l1= strlen(m);

    int l2= strlen(n);

    for(int i=0; i<l1; i++)

    {

        int x= m[i];

        H = (H*73 + x)%100007;

        H2= (H2*73 + x)%100021;

    }



    for(int i= 0; i<l1;i++)

    {

        int y= n[i];

        has = (has*73 + y)%100007;

        has2 = (has2 *73 + y)%100021;

    }

    int pow1=1, pow2=1;

    for(int i=1; i<l1;i++)

    {

        pow1=(pow1* 73)%100007;

        pow2= (pow2 * 73)%100021;

    }

    if(has== H && has2== H2)

    {

        nr++;

    }

    for(int i= l1; i<l2;i++)

    {

        has = (has-pow1*(n[i-l1]))%100007 + 100007;

        has= (has*73 +(n[i]))%100007;



        has2 = (has2-pow2*(n[i-l1]))%100021 +100021;

        has2= (has2*73 +(n[i]))%100021;

        if(has==H && has2== H2)

        {

            nr++;

            if(nr<=1000)

            v[nr]=i-l1+1;

        }

    }

    cout << nr<<endl;

    for(int i=1 ;i<=nr && i<=1000;i++)

        cout<<v[i]<<" ";

}
