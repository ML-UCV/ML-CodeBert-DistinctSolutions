#include <bits/stdc++.h>


using namespace std;

ifstream in("evaluare.in");

ofstream out("evaluare.out");



const int NMAX=100000;

char c,semn[NMAX],st[NMAX];

int i,n,k,nr,gasitnr,fp[NMAX];

long long steval[100];



int main()

{

    while(in>>c){

        if(c>='0'&&c<='9'){

            gasitnr=1;

            nr=nr*10+(c-48);

        }

        else{

            if(gasitnr){

                n++;

                fp[n]=nr;

                nr=0;

                gasitnr=0;

            }

            if(c=='('||c=='+'||c=='-'||c=='*'||c=='/')

            {

                k++;

                st[k]=c;

                if(st[k]=='+'||st[k]=='-'){

                    while(st[k-1]=='+'||st[k-1]=='-'||st[k-1]=='*'||st[k-1]=='/'){

                        n++;

                        semn[n]=st[k-1];

                        st[k-1]=st[k];

                        k--;

                    }

                }

                else

                    if(st[k]=='*'||st[k]=='/'){

                        while(st[k-1]=='*'||st[k-1]=='/'){

                            n++;

                            semn[n]=st[k-1];

                            st[k-1]=st[k];

                            k--;

                    }

                }

            }

            else

                if(c==')'){

                    while(st[k]!='('){

                        n++;

                        semn[n]=st[k];

                        k--;

                    }

                    k--;

            }

        }

    }

    if(gasitnr){

        n++;

        fp[n]=nr;

        nr=0;

        gasitnr=0;

    }

    while(k){

        n++;

        semn[n]=st[k];

        k--;

    }

    k=0;

    for(i=1;i<=n;i++){

        if(semn[i]!='+'&&semn[i]!='-'&&semn[i]!='*'&&semn[i]!='/'){

            k++;

            steval[k]=fp[i];

        }

        else

        {

            if(semn[i]=='+'){

                steval[k-1]=steval[k-1]+steval[k];

            }

            if(semn[i]=='-'){

                steval[k-1]=steval[k-1]-steval[k];

            }

            if(semn[i]=='*'){

                steval[k-1]=steval[k-1]*steval[k];

            }

            if(semn[i]=='/'){

                steval[k-1]=steval[k-1]/steval[k];

            }

            k--;

        }

    }

    out<<steval[1];

    return 0;

}
