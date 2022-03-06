#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;







ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char string_array[2000005], pattern[2000005];
void lps(int lps_array[], char pattern[]){

 lps_array[0] = 0;

 int i = 1, n = strlen(pattern), len = 0;

 while(i < n){

  if(pattern[i] == pattern[len]){

   len++;

   lps_array[i] = len;

   i++;

  }

  else{

   if(len != 0){

    len = lps_array[len - 1];

   }

   else{

    lps_array[i] = 0;

    i++;

   }

  }

 }

}



void kmp(char sequence[], char pattern[]){

 int i = 0, j = 0, n = strlen(sequence), m = strlen(pattern);

 int lps_array[m], cnt = 0, matches[1000];



    lps(lps_array, pattern);

 while(i < n){

  if(sequence[i] == pattern[j]){

   i++;

   j++;

   if(j == m){

    if(cnt < 1000){

        matches[cnt] = i - j;

    }

                cnt++;

                j = lps_array[j - 1];

   }

  }

  else if((i < n) && (pattern[j] != sequence[i])){

   if(j > 0){

    j = lps_array[j - 1];

   }

   else{

    i++;

   }



  }

 }

 fout << cnt << "\n";

 for(int i = 0; i < ((cnt)<(1000)?(cnt):(1000)); ++i){

     fout << matches[i] << " ";

 }

}



int main(){

    fin >> pattern;

    fin >> string_array;

    kmp(string_array, pattern);



    return 0;

}
