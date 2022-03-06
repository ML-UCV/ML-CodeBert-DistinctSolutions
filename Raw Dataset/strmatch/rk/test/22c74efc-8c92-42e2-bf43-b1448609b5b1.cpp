#include <fstream>




using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

long long pro1,pro2,val1,val2,val3,val4,n,n2,i,nrr,nrr2;

char c,a[2000005];

int main()

{

    pro1=pro2=1;

while (true)

{

    in.get(c);

    if (c=='\n') break;

    val1=(67*val1+c)%(85636124);

    val2=(67*val2+c)%(93579235);

 if (n!=0){

    pro1=67*pro1%(85636124);

    pro2=67*pro2%(93579235);}

    n++;

}

while (true)

{

    in.get(a[i++]);

    if (a[i-1]=='\n') break;

    if (i<=n) {val3=(67*val3+a[i-1])%(85636124);

              val4=(67*val4+a[i-1])%(93579235);

    }

    else {if (val1==val3&&val2==val4) nrr++;

    val3=(67*(val3-pro1*a[i-n-1])%(85636124)+(85636124)+a[i-1])%(85636124);

    val4=(67*(val4-pro2*a[i-n-1])%(93579235)+(93579235)+a[i-1])%(93579235);}

}

if (val1==val3&&val2==val4) nrr++;

out<<nrr<<'\n';

n2=i;

val3=val4=0;

for (i=1;i<n2;++i)

{

    if (i<=n) {val3=(67*val3+a[i-1])%(85636124);

              val4=(67*val4+a[i-1])%(93579235);

    }

    else {if (val1==val3&&val2==val4) {nrr2++;

        if (nrr2>1000) return 0;

        out<<i-n-1<<" ";

    }

    val3=(67*(val3-pro1*a[i-n-1])%(85636124)+(85636124)+a[i-1])%(85636124);

    val4=(67*(val4-pro2*a[i-n-1])%(93579235)+(93579235)+a[i-1])%(93579235);}

}

     if (val1==val3&&val2==val4) {nrr2++;

        if (nrr2>1000) return 0;

        out<<i-n-1<<" ";

    }





    return 0;

}
