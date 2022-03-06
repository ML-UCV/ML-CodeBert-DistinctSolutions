#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


int pi[2000001];
void prefix(char *A, int *pi){
    int k = 0, size = strlen(A);

    for(int i = 2; i <= size; i++){
        while(k && A[k + 1] != A[i])
            k = pi[k];

        if(A[k + 1] == A[i]) k++;

        pi[i] = k;
    }

}

void print(vector<int> ans, FILE *fout){
    fprintf(fout, "%ld\n", ans.size());

    for(int i = 0; i < ans.size() && i < 1000; i++)
        fprintf(fout, "%d ", ans[i]);

}

void solve(char *A, char *B, int *pi, FILE *fout){
    int k = 0, size = strlen(B), sizeA = strlen(A);
    vector<int> ans;

    for(int i = 0; i < size; i++){
        while(k > 0 && A[k + 1] != B[i])
           k = pi[k];

        if(A[k + 1] == B[i])
           k++;

        if(k == sizeA - 1){
           ans.push_back(i - sizeA + 2);
           k = pi[k];
        }

    }

    print(ans, fout);
}

int main(){
    FILE *fin = fopen("strmatch.in", "r");
    FILE *fout = fopen("strmatch.out", "w");
    char A[2000001], B[2000001];

    fscanf(fin, "%s%s", A, B);

    for(int i = strlen(A); i > 0; i--)
     A[i] = A[i - 1];

    prefix(A, pi);
    solve(A, B, pi, fout);

    fclose(fin);
    fclose(fout);

}
