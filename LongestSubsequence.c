#include<stdio.h>
#include<string.h>

//i've added parts in the function that allow us to trace the algorithm
//HOWEVER the trace takes place for every single character in the string
//since ive accomodated it within the function itself
void longest_subsequence(char X[], char Y[], int m, int n) {
    int L[m+1][n+1];

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0) {
                L[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else {
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
            }
            printf("i=%d, j=%d, X[i-1]=%c, Y[j-1]=%c, L[i][j]=%d\n", i, j, X[i-1], Y[j-1], L[i][j]);
        }
    }

    int index = L[m][n];
    char longest_subsequence[index+1];
    longest_subsequence[index] = '\0';

    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(X[i-1] == Y[j-1]) {
            longest_subsequence[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", longest_subsequence);
    printf("Length of Longest Common Subsequence: %d\n", strlen(longest_subsequence));
}

int main() {
    char X[] = "ABCD";
    char Y[] = "ACDF";
    int m = strlen(X);
    int n = strlen(Y);
    longest_subsequence(X, Y, m, n);

    char X1[] = "GBWKBGKWRBJKWBWREBEBGKJR";
    char Y1[] = "VHKWBGHWRVBLADVJSBVISEVW";
    int m1 = strlen(X1);
    int n1 = strlen(Y1);
    longest_subsequence(X1, Y1, m1, n1);
    
    char X2[] = "ABCDEF";
    char Y2[] = "FOOXYZ";
    int m2 = strlen(X2);
    int n2 = strlen(Y2);
    longest_subsequence(X2, Y2, m2, n2);

    return 0;
}











