#include<fstream>
#include<iostream>
#include<vector>
#include<stack>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n,i,m,a,b,j,nr;



vector<int>v[100001],vt[100001];



bool viz[100001],Viz[100001];



vector<int>compcon[100001];

stack<int>st;



void citire(){



    f >> n>>m;



    for(int i = 1; i <= m; i++){



        f>> a >> b;



        v[a].push_back(b);

        vt[b].push_back(a);

    }



}





void dfs(int vf){



    viz[vf]=true;



    for(int i=0; i<v[vf].size(); i++)



        if(!viz[v[vf][i]])

            dfs(v[vf][i]);







    st.push(vf);



}



void Dfs(int vf){



    Viz[vf]=true;



    for(int i=0; i<vt[vf].size(); i++)



        if(!Viz[vt[vf][i]]){



            Dfs(vt[vf][i]);



            compcon[j].push_back(vt[vf][i]);

        }



}
int main(){



    citire();



    for(j=1; j<=n; j++){



        if(!viz[j])



            dfs(j);



    }



    while(!st.empty()){



        j=st.top();



        st.pop();



        if(!Viz[j]){



            Dfs(j);



            nr++;



            compcon[j].push_back(j);



        }



    }



    g<<nr<<"\n";



    for(i=1; i<=n; i++){



        if(compcon[i].size()){



            for(j=0; j<compcon[i].size(); j++)



                g<<compcon[i][j]<<" ";



            g<<"\n";



        }



    }



}
