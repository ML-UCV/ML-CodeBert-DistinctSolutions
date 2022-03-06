#include <fstream>
using namespace std;

ifstream cin("cmmdc.in");

ofstream cout("cmmdc.out");

int main(int argc, char *argv[]) {

 long long int a,b,d;

 cin>>a;

 cin>>b;

 if(a==1 || b==1){

        d=1;

 }else{

     for(long long int i=1;i<=min(a,b);i++){

            if(a%i==0 && b%i==0){

                d=i;

            }

     }

 }

 if(d==1){

        d=0;

 }

 cout<<d;

}
