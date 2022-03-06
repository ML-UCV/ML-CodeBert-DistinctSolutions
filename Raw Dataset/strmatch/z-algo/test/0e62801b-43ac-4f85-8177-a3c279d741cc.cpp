#include <fstream>


using namespace std;



int z[4000005];

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

int main()

{

    string s1,s2;

    cin>>s1>>s2;

    int n=s1.size(),m=s2.size();

    s1+='#';

    s1+=s2;



    int st=0,dr=0;

    for(int i=1;i<n+m+1;i++){

        if(i>dr){

            dr=i;

            st=i;

            while(s1[dr]==s1[dr-st] and dr<n+m+1){

                dr++;

            }

            z[i]=dr-st;

            dr--;

        }

        else{

            if(z[i-st]+i-1<dr){

                z[i]=z[i-st];

            }

            else{

                st=i;

                while(s1[dr]==s1[dr-st] and dr<n+m+1){

                    dr++;

                }

                z[i]=dr-st;

                dr--;

            }

        }

    }



    int contor=0;

    for(int i=0;i<n+m+1;i++){

        if(z[i]==n){

            contor++;

        }

    }

    cout<<contor<<"\n";

    contor=0;

    for(int i=0;i<n+m+1;i++){

        if(z[i]==n){

            contor++;

            if(contor<=1000)

            cout<<i-n-1<<" ";

        }

    }

    return 0;

}
