#include <fstream>
#include <iostream>
#include <stack>
#include <set>
#include <list>


using namespace std;



struct supposition

{

    int v;

    int i;

    list<int> vard;

};



stack<supposition> st;

set<int> unks;
list<int> a[101],

            b[101],

            c[101],

            d[101];



char val[101];

int n,m,i,j,x,y,z,v,mod,t;



int deduce(int);



int asgn(int i,int v)

{

    if(val[i]==v)return 1;

    if(val[i]==2)

    {

        val[i]=v;

        unks.erase(i);

        st.top().vard.push_back(i);

        return deduce(i);

    }

    else return 0;

}



int deduce(int i)

{

    int v=val[i];

    int t;

    list<int>::iterator it;

    if(v==0)

    {

        for(it=a[i].begin();it!=a[i].end();it++)

        {

            t=asgn(*it,1);

            if(t==0)return 0;

        }

        for(it=b[i].begin();it!=b[i].end();it++)

        {

            t=asgn(*it,0);

            if(t==0)return 0;

        }

    }

    else

    {

        for(it=c[i].begin();it!=c[i].end();it++)

        {

            t=asgn(*it,0);

            if(t==0)return 0;

        }

        for(it=d[i].begin();it!=d[i].end();it++)

        {

            t=asgn(*it,1);

            if(t==0)return 0;

        }

    }

    return 1;

}



void print_values()

{

    for(int i=1;i<=n;i++)

    {

        if(val[i]==2)cout<<"UNK";

        else cout<<val[i]+0;

        cout<<' ';

    }

    cout<<'\n';

}



int main()

{

    fstream f("party.in",ios::in),g("party.out",ios::out);

    f>>n>>m;

    for(i=1;i<=n;i++){val[i]=2;unks.insert(i);}

    for(i=0;i<m;i++)

    {

        f>>x>>y>>z;

        if(z==0)

        {

            a[x].push_back(y);

            a[y].push_back(x);

        }

        else if(z==1)

        {

            b[x].push_back(y);

            d[y].push_back(x);

        }

        else if(z==2)

        {

            b[y].push_back(x);

            d[x].push_back(y);

        }

        else if(z==3)

        {

            c[x].push_back(y);

            c[y].push_back(x);

        }

    }

    mod=0;

    while(!unks.empty())

    {



        if(mod==0)

        {

            supposition s;

            s.i=*(unks.begin());

            s.v=1;

            st.push(s);



            unks.erase(s.i);

            val[s.i]=s.v;



            t=deduce(s.i);

            if(t)mod=0;

            else mod=1;

        }

        else if(mod==1)

        {

            for(list<int>::iterator it=st.top().vard.begin();it!=st.top().vard.end();it++)

            {

                val[*it]=2;

                unks.insert(*it);

            }

            supposition s=st.top();

            s.v=0;

            val[s.i]=s.v;



            t=deduce(s.i);

            if(t)mod=0;

            else

            {

                mod=1;



                while(st.top().v==0)

                {

                    for(list<int>::iterator it=st.top().vard.begin();it!=st.top().vard.end();it++)

                    {

                        val[*it]=2;

                        unks.insert(*it);

                    }

                    supposition s=st.top();

                    val[s.i]=2;

                    unks.insert(s.i);

                    st.pop();

                }

            }

        }



    }

    int s=0;

    for(i=1;i<=n;i++)if(val[i]==1)s++;

    g<<s<<'\n';

    for(i=1;i<=n;i++)if(val[i]==1)g<<i<<'\n';

}
