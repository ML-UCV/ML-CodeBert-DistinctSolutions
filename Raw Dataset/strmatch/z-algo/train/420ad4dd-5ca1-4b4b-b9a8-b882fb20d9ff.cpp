#include <fstream>


using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

string s1,s2;

int z[4000008];

int main()

{

    cin>>s1>>s2;

    int n=s1.size();

    int m=s2.size();

    s1+='$';

    s1+=s2;

    int st=0,dr=0;

    for(int i=1;i<n+m+1;i++){

        if(i>dr){

            st=i;

            dr=i;

            while(s1[dr]==s1[dr-st] and dr<=n+m+1){

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

                while(s1[dr]==s1[dr-st] and dr<=n+m+1){

                    dr++;

                }

                z[i]=dr-st;

                dr--;

            }

        }

    }

    int c=0;

    for(int i=1;i<n+m+1;i++)

        if(z[i]==n)

            c++;

    cout<<c<<"\n";

    c=0;

    for(int i=1;i<n+m+1;i++){



        if(z[i]==n){

            c++;

            if(c>1000)

                continue;

            cout<<i-n-1<<" ";

         }

    }

    return 0;

}
