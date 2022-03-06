#include <cstdio>
#include <cstring>


using namespace std;



int stNum[100000 +3],vfOp=0,vfNum=0;

char v[100000 +3],op[100000 +3];



FILE *fin,*fout;



int calc(int a,int b,char oper)

{

    if(oper=='+')

    {

        return a+b;

    }

    else if(oper=='-')

    {

        return a-b;

    }

    else if(oper=='*')

    {

        return a*b;

    }

    else if(oper=='/')

    {

        return a/b;

    }

}



int oper(char x)

{

    if(x=='+')

    {

        return 1;

    }

    else if(x=='-')

    {

        return 1;

    }

    else if(x=='*')

    {

        return 2;

    }

    else if(x=='/')

    {

        return 2;

    }

    return 0;

}



void afis()

{

    for(int i=1; i<=vfOp; i++)

    {

        fprintf(fout,"%c",op[i]);

    }

    fprintf(fout,"\n");

    for(int i=1; i<=vfNum; i++)

    {

        fprintf(fout,"%d ",stNum[i]);

    }

    fprintf(fout,"\n\n");

}



int main()

{

    fin=fopen("evaluare.in","r");

    fout=fopen("evaluare.out","w");



    fgets(v,100000 +3,fin);

    int n=strlen(v);

    n--;



    for(int i=0; i<n; i++)

    {

        char ch=v[i];

        if(ch=='(')

        {



            vfOp++;

            op[vfOp]=ch;

        }

        else if(ch==')')

        {





            while(op[vfOp]!='(')

            {

                int rez=calc(stNum[vfNum-1],stNum[vfNum],op[vfOp]);

                vfOp--;

                vfNum--;

                stNum[vfNum]=rez;

            }

            vfOp--;

        }

        else

        {

            if(ch>='0' && ch<='9')

            {



                int num=0;

                while(i<n && v[i]>='0' && v[i]<='9')

                {

                    num=num*10+v[i]-'0';

                    i++;

                }

                i--;

                vfNum++;

                stNum[vfNum]=num;

            }

            else

            {





                while(vfOp>0 && oper(ch)<=oper(op[vfOp]))

                {

                    int rez=calc(stNum[vfNum-1],stNum[vfNum],op[vfOp]);

                    vfOp--;

                    vfNum--;

                    stNum[vfNum]=rez;

                }

                vfOp++;

                op[vfOp]=ch;

            }

        }



    }



    while(vfOp>0)

    {

        int rez=calc(stNum[vfNum-1],stNum[vfNum],op[vfOp]);

        vfOp--;

        vfNum--;

        stNum[vfNum]=rez;

    }

    fprintf(fout,"%d",stNum[1]);

    return 0;

}
