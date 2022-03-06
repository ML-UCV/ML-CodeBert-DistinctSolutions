#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int main(){

  long long int cn,a,fi,d,nr,n;



  fin>>a>>n;

  cn=n;

  fi=n;

  d=2;

  while(d*d<=n){

    if(n%d==0){

      fi=fi/d*(d-1);

      while(n%d==0)

        n/=d;

    }

    d++;

  }

  if(n>1)

    fi=fi/n*(n-1);

  fi--;

  nr=1;

  while(fi!=0){

    if(fi%2!=0)

      nr=(nr*a)%cn;

    fi/=2;

    a=a*a%cn;

  }

  fout<<nr<<endl;

  return 0;

}
