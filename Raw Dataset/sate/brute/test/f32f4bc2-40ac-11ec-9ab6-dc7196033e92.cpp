#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,x,y;
int a[100100] , b[100100] , d[100100];
int drum[100100];

int main()
{
    fin >> n >> m >> x >> y;
    for(int i=1 ; i<=m ; i++)
        fin >> a[i] >> b[i] >> d[i];
    drum[x] = 1;

    while(!drum[y])
        for(int i=1 ; i<=m ; i++)
            if(!drum[a[i]] && drum[b[i]])
                drum[a[i]] = drum[b[i]] - d[i];
            else if(drum[a[i]] && !drum[b[i]])
                drum[b[i]] = drum[a[i]] + d[i];

    fout << drum[y] - 1;
}