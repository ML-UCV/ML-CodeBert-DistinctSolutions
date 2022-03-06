#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



string a, b;

int c[2000004], j;

queue<int> q;



int main() {

    f>>a>>b;

    a="0"+a;

    b="0"+b;



    for(int i=2;i<a.length();i++) {

        while(j && a[j+1]!=a[i])

            j=c[j];

        if(a[j+1]==a[i])

            j++;

        c[i]=j;

    }
    j=0;

    for(int i=1;i<b.length();i++) {

        while(j && a[j+1]!=b[i])

            j=c[j];

        if(a[j+1]==b[i])

            j++;

        if(j==a.length()-1) {

            j=c[j];

            q.push(i-a.length()+1);

        }

    }

    g<<q.size()<<'\n';

    int s=min((int)q.size(), 1000);

    while(s) {

        g<<q.front()<<' ';

        q.pop();

        s--;

    }



    f.close();

    g.close();

    return 0;

}
