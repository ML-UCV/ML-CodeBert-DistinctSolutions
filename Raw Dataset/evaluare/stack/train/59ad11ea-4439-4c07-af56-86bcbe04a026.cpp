#include <stdio.h>
char ch[100005];

int v[100005],st[100005];

int main()

{

    FILE *fin,*fout;

    fin=fopen("evaluare.in","r");

    fout=fopen("evaluare.out","w");

    int n,i,q=0,nr,k=0;

    n=1;

    while(fscanf(fin,"%c",&ch[n])!=EOF)

        n++;

    i=1;

    while(i<=n){

        if(ch[i]>='0' && ch[i]<='9'){

            nr=0;

            while(ch[i]>='0' && ch[i]<='9'){

                nr=nr*10+ch[i]-'0';

                i++;

            }

            q++;

            v[q]=nr;

            i--;

        }

        else{

            if(ch[i]=='('){

                k++;

                st[k]=-1;

            }

            if(ch[i]==')'){

                while(st[k]!=-1){

                    q++;

                    v[q]=st[k];

                    k--;

                }

                k--;

            }

            if(ch[i]=='*'){

                while (st[k]==-5 || st[k]==-6){

                    q++;

                    v[q]=st[k];

                    k--;

                }

                k++;

                st[k]=-5;

            }

            if(ch[i]=='/'){

                while (st[k]==-5||st[k]==-6){

                    q++;

                    v[q]=st[k];

                    k--;

                }

                k++;

                st[k]=-6;

            }

            if(ch[i]=='+'){

                while(st[k]!=-1 && k!=0){

                    q++;

                    v[q]=st[k];

                    k--;

                }

                k++;

                st[k]=-3;

            }

            if(ch[i]=='-'){

                while(st[k]!=-1 && k!=0){

                    q++;

                    v[q]=st[k];

                    k--;

                }

                k++;

                st[k]=-4;

            }

        }

        i++;

    }

    while(k!=0){

        q++;

        v[q]=st[k];

        k--;

    }

    for(i=1;i<=q;i++){

        if(v[i]>=0){

            k++;

            st[k]=v[i];

        }

        else{

            if(v[i]==-5){

                if(k<=1)

                    st[k]=0;

                else{

                    k--;

                    st[k]=st[k]*st[k+1];

                }

            }

            else

                if(v[i]==-6){

                    k--;

                    st[k]=st[k]/st[k+1];

                }

                else

                    if(v[i]==-3){

                        k--;

                        st[k]=st[k]+st[k+1];

                    }

                    else{

                        k--;

                        st[k]=st[k]-st[k+1];

                    }

        }

    }

    fprintf(fout,"%d ",st[1]);

    fclose(fin);

    fclose(fout);

    return 0;

}
