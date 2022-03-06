#include <iostream>
#include <stdio.h>
#include <string.h>






using namespace std;



int k,n;



int eval();

int termen();

int factor();

int ok();



char v[100003];



int eval(){

    int s=termen();



    while((v[k]=='+' || v[k]=='-') && k<n){

        if(v[k]=='+'){

            k++;

            s=s+termen();

        }else{

            k++;

            s=s-termen();

        }





    }



    return s;

}



int termen(){

    int s=factor();



    while((v[k]=='*' || v[k]=='/') && k<n){

        if(v[k]=='*'){

            k++;

            s=s*factor();

        }else{

            k++;

            s=s/factor();

        }





    }



    return s;





}



int ok(){



   return (v[k]>='0' && v[k]<='9');



}



int factor(){

    int s=0;



    if(v[k]=='('){

        k++;

        s=eval();

        k++;

    }else{

        while(ok() && k<=n){

            s=s*10+(v[k]-'0');

            k++;

        }

    }





    return s;

}





int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);



    scanf("%s",&v);





    n=strlen(v);



    printf("%d",eval());



    return 0;

}
