#include <fstream>
#include <cstring>


using namespace std;



int l[2000005];

char a[2000005], b[2000005];

int sir[2000005];

int contor=0;

int la, lb;



int main()

{

    ifstream fin ("strmatch.in");

    ofstream fout ("strmatch.out");



    fin >> a >> b;

    la = strlen(a);

    lb = strlen(b);



    l[0] = 0;

    int i=1, j=0;



    while(i<la)

        if(a[i] == a[j])

        {

            j++;

            l[i] = j;

            i++;

        }

        else

            if(j==0)

                l[i++]=0;

            else

                j=l[j-1];





    i=0; j=0;

    while(i<lb)

        if(b[i] == a[j])

        {

            i++;

            j++;

            if(j==la)

            {

                sir[contor++] = i-la;

                j=l[j-1];

            }

        }

        else

            if(j==0)

                i++;

            else

                j = l[j-1];



    fout << contor << "\n";

    contor = min (contor, 1000);

    for(i=0; i<contor; i++)

        fout << sir[i] << " ";



    return 0;

}
