#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, i, nrc, h[100005], low[100005], x, inaltime;

bitset<100005> viz, eInStiva;

vector<int>L[100005];

vector<int>c[100005];

stack<int>st;



void citireGraf(){

 int i, x, y;

 fin >> n >> m;

 for(i = 1; i <= m; i++){

  fin >> x >> y;

         L[x].push_back(y);

 }

}



void dfs(int x) {

 int z;

 inaltime++;

 viz[x] = 1;

 low[x] = h[x] = inaltime;



 st.push(x);

 eInStiva[x] = 1;



 for(auto y : L[x]) {

         if(viz[y] == 0){

   dfs(y);

   low[x] = min(low[x], low[y]);

         }

         else if(eInStiva[y])

   low[x] = min(low[x], h[y]);

     }





     if (low[x] == h[x]){

   nrc++;

         do{

   z = st.top();

   st.pop();

   eInStiva[z] = 0;

              c[nrc].push_back(z);

           }while(z!=x);

      }

}





int main() {



    citireGraf();

    for(i = 1; i <= n; i++)

        if(viz[i] == 0)

            dfs(i);





    fout<< nrc << '\n';

    for(i = 1; i <= nrc; i++){

 for (auto x : c[i])

  fout << x <<' ';

                fout <<'\n';

    }



    fin.close(); fout.close();

    return 0;

}
