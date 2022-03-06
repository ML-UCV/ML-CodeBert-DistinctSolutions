#include <stdio.h>
int AnswerMyQuery(int node, int index);



void calculateMyD(int N);



FILE *fin, *fout;





int tata[250000 + 1];



int d[18 + 1][250000 + 1];



int main() {

    fin = fopen("stramosi.in", "r");

    fout = fopen("stramosi.out", "w");





    int N, Q;



    fscanf(fin, "%d%d", &N, &Q);



    for(int i = 0; i < N; i++) {

            fscanf(fin , "%d", &tata[i + 1]);

    }



    calculateMyD(N);



    for(int i = 0; i < Q; i++) {

        int node, index;

        fscanf(fin, "%d%d", &node, &index);

        fprintf(fout, "%d\n", AnswerMyQuery(node, index));

    }

    fclose(fin);

    fclose(fout);

    return 0;

}



int AnswerMyQuery(int node, int index) {



    int currnode = node;

    int level = 0;

    while(index > 0) {

        if(index % 2 == 1) {

            currnode = d[level][currnode];

        }

        level++;

        index /= 2;

    }

    return currnode;

}



void calculateMyD(int N) {



    for(int j = 1; j <= N; j++) {

        d[0][j] = tata[j];

    }

    for(int i = 1; i <= 18; i++) {

        for(int j = 1; j <= N; j++) {

            d[i][j] = d[i - 1][d[i - 1][j]];

        }

    }

}
