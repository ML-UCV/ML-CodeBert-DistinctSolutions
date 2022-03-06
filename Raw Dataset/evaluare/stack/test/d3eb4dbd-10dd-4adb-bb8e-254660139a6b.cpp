#include <iostream>
#include<stdio.h>
char c, semn[100001], st[10001];



int fp[100001];

long long steval[101];



using namespace std;



int main() {

    int nr, gasitnr, n, i, k;

    FILE *fin, *fout;



    fin=fopen("evaluare.in", "r");

    fout=fopen("evaluare.out", "w");

    c=fgetc( fin );

    nr=0;

    n=0;

    k=0;

    gasitnr=0;

    while(c!=EOF) {

        if(c>='0' && c<='9') {

            gasitnr=1;

            nr=nr*10+(c-48);

        }

        else {

            if(gasitnr) {

                n++;

                fp[n]=nr;

                nr=0;

                gasitnr=0;



            }

            if(c=='(' || c=='-' || c=='+' || c=='/' || c=='*' ) {

                k++;

                st[k]=c;

                if(st[k]=='+' || st[k]=='-') {

                    while(st[k-1]=='+' || st[k-1]=='-' || st[k-1]=='*' || st[k-1]=='/') {

                        n++;

                        semn[n]=st[k-1];

                        st[k-1]=st[k];

                        k--;

                    }

                }

                else if(st[k]=='*' || st[k]=='/') {

                    while(st[k-1]=='*' || st[k-1]=='/') {

                        n++;

                        semn[n]=st[k-1];

                        st[k-1]=st[k];

                        k--;

                    }

                }

            }

            else if(c==')') {

                while(st[k]!='(') {

                    n++;

                    semn[n]=st[k];

                    k--;

                }

                k--;

            }

        }

        c=fgetc( fin );

    }



    if(gasitnr) {

        n++;

        fp[n]=nr;

        nr=0;

        gasitnr=0;

    }

    while(k) {

        n++;

        semn[n]=st[k];

        k--;

    }

    k=0;

    for(i=1; i<=n; i++) {

        if(semn[i]!='+' && semn[i]!='-' && semn[i]!='*' && semn[i]!='/') {

            k++;

            steval[k]=fp[i];

        }

        else {

            if(semn[i]=='+') {

                steval[k-1]=steval[k-1]+steval[k];

            }

            if(semn[i]=='-') {

                steval[k-1]=steval[k-1]-steval[k];

            }

            if(semn[i]=='*') {

                steval[k-1]=steval[k-1]*steval[k];

            }

            if(semn[i]=='/') {

                steval[k-1]=steval[k-1]/steval[k];

            }

            k--;

        }

    }

    fprintf( fout, "%d", steval[1]);

    fclose( fin );

    fclose( fout );

    return 0;

}
