#include <cstdio>






FILE *fin = freopen("schi.in","r",stdin); FILE *fout = freopen("schi.out","w",stdout);



const int NMAX = 30000 + 5;





int n, v[NMAX], aib[NMAX], sol[NMAX];





void Add(int position, int value)

{

    for(int i = position; i<= n; i+=(i & (-i)))

        aib[i]+=value;

}



int Query(int position)

{

    int res = 0;

    for(int i = position; i>0 ; i-=(i & (-i)))

        res+=aib[i];

    return res;

}



void Read()

{

    scanf("%d",&n);

    for(int i =1 ; i<= n; ++i){

        scanf("%d",&v[i]);

        Add(i,1);

    }

}



void Rezolva()

{

    int pas = 1, k = 0,aux;

    for(;pas<=n;pas<<=1);



    for(int i = n; i>= 1; i--)

    {

        aux = pas; k = 0;

        for(;aux;aux>>=1)

            if(k + aux <= n && Query(k+aux) < v[i])

                k+=aux;

        sol[k+1]=i;

        Add(k+1,-1);

    }

    for(int i = 1; i<= n; ++i)

        printf("%d\n",sol[i]);

}



int main()

{

    Read();

    Rezolva();



}
