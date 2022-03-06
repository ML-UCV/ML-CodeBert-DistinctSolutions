#include <bits/stdc++.h>


int v[30000];



int loc[30000];



int an[65536];



void update(int st,int dr,int nod,int p)

{

    if(st==dr)

    {

        an[p]+=1;

    }

    else

    {

        int mij=st+dr;

        mij/=2;

        if(nod<=mij)

            update(st,mij,nod,p*2);

        else update(mij+1,dr,nod,p*2+1);

        an[p]=an[p*2]+an[p*2+1];

    }

}



int get(int st,int dr,int p,int s)

{

    if(st==dr)

        return st;

    else

    {

        int mij=st+dr;

        mij/=2;

        int opens=(mij-st+1)-an[p*2];

        int opend=(dr-mij)-an[p*2+1];

        if(opens<s)

        {

            get(mij+1,dr,p*2+1,s-opens);

        }

        else get(st,mij,p*2,s);

    }

}



int main()

{

    int n,i,s,q;

    FILE*fi,*fo;

    fi=fopen("schi.in","r");

    fo=fopen("schi.out","w");

    fscanf(fi,"%d",&n);

    for(i=0; i<n; i++)

    {

        fscanf(fi,"%d",&v[n-i-1]);

    }

    for(i=0; i<n; i++)

    {

        q=get(1,n,1,v[i]);

        update(1,n,q,1);

        loc[q]=n-i;



    }

    for(i=1; i<=n; i++)

    {

        fprintf(fo,"%d\n",loc[i]);

    }

    fclose(fi);

    fclose(fo);

    return 0;

}
