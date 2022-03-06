#include<cstdio>
#include<cstring>


int min(int a, int b){

    if(a <= b)

        return a;

    return b;

}



long long hash[2], base;

char word[2000001], text[2000001];

int sol[1001];

int main(){

    freopen("strmatch.in","r",stdin);

    freopen("strmatch.out","w",stdout);



    int wLen, tLen, nr = 0;

    long long whash[2], rhash[2], basePow[2];



    scanf("%s%s",&word, &text);

    wLen = strlen(word);

    tLen = strlen(text);



    hash[0] = 666013;

    hash[1] = 1000000007;

    base = 97;



    for(int j = 0; j < 2; j++){

        rhash[j] = 0;

        whash[j] = 0;

        basePow[j] = 1;

    }



    for(int i = 0; i < wLen; i++){

        for(int j = 0; j < 2; j++){

            whash[j] = ( (whash[j] * base) % hash[j] + word[i] ) % hash[j];

            basePow[j] = (basePow[j] * base) % hash[j];

        }

    }



    for(int i = 0; i < tLen; i++){

        for(int j = 0; j < 2; j++)

            rhash[j] = ( (rhash[j] * base) % hash[j] + text[i] ) % hash[j];

        if(i >= wLen){

            for(int j = 0; j < 2; j++){

                rhash[j] = ((rhash[j] - basePow[j] * text[i - wLen]) % hash[j] + hash[j]) % hash[j];

            }

        }

        if(i >= wLen - 1 && whash[0] == rhash[0] && whash[1] == rhash[1]){

            nr++;

            if(nr <= 1000)

                sol[nr - 1] = i - wLen + 1;

        }

    }

    printf("%d\n",nr);

    for(int i = 0; i < min(nr, 1000); i++)

        printf("%d ",sol[i]);

    return 0;

}
