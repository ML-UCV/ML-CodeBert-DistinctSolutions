#include <bits/stdc++.h>




using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

int perm[50000], a[4*50000];

char s[50000], pattern[50000];

int freq[27], evan[50000];

vector< int > pos[27];

pair<long long, int> v[50000];



void update(int nod){

    while(nod!=1){

        nod/=2;

        a[nod]=a[2*nod]+a[2*nod+1];

    }

}

long long query(int lo, int hi){

    long long left=0, right=0;

    if(lo==hi){

        return a[lo];

    }

    else if(lo<hi){

      if(lo%2==1){

        left=a[lo];

        lo++;

      }

      if(hi%2==0){

        right=a[hi];

        hi--;

      }

      lo/=2, hi/=2;

      return left+right+query(lo, hi);

    }

    return 0;

}

bool compare(pair<long long, int> a, pair<long long, int> b){

    return a.second<b.second;

}

bool isAnagram(char a[], char b[], int n){

    int letter1[27], letter2[27];

    memset(letter1, 0, sizeof(letter1));

    memset(letter2, 0, sizeof(letter2));

    for(int i=0; i<n; i++){

        letter1[a[i]-'a']++;

        letter2[b[i]-'a']++;

    }

    for(int i=0; i<27; i++){

        if(letter1[i]!=letter2[i])

           return false;

    }

    return true;

}

int main()

{

    int n;

    long long sum=0, start=1;

    fin>>s>>pattern;

    n=strlen(s);

    while(start<n)

        start<<=1;

   if(!isAnagram(s, pattern, n)){

       fout<<"-1";

   }

   else{



    for(int i=0; i<n; i++){

       freq[s[i]-'a']++;

       evan[i]=freq[s[i]-'a'];

    }

    for(int i=0; i<n; i++){

        pos[pattern[i]-'a'].push_back(i+1);

    }



    for(int i=0; i<n; i++){

        perm[i]=pos[s[i]-'a'][evan[i]-1];



    }



    for(int i=0; i<n; i++){

        v[i].first=perm[i];

        v[i].second=i+1;

    }

    sort(v, v+n);

    long long currentID=1, extra ,lastValue=v[0].first;

    for(int i=0; i<n; i++){

       extra=v[i].first;

       if(v[i].first==lastValue)

         v[i].first=currentID;

       else

         v[i].first=++currentID;

       lastValue=extra;

    }

    sort(v, v+n, compare);

    for(int i=start; i<start+n; i++){

        int temp=v[i-start].first;

        sum=sum+query(start+temp, start+n-1);

        a[start+temp-1]+=1;

        update(start+temp-1);

    }

    fout<<sum;

    return 0;

  }

}
