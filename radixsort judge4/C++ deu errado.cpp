#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct oi{
    string nome;
}A[100000],B[100000];

void CountingSort(int tamA, int pos){
    int k = 27;
    int i,j;
    int C[k];
    for (i=0;i<k;i++){
        C[i] = 0;
    }
    for (j = 0; j < tamA; j++){
        if (A[j].nome[pos] == 32){
            C[0]++;
        }
        else {
            C[A[j].nome[pos] - 96]++;
        }
    }
    for (i = 1;i < k; i++){
        C[i] += C[i-1];
    }
    for (i = 0;i < k; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    for (i = tamA - 1; i >= 0; i--) {
        if (A[i].nome[pos] == 32) {
            B[C[0] - 1] = A[i];
            C[0]--;
        } else {
            B[C[A[i].nome[pos] - 96] - 1] = A[i];
            C[A[i].nome[pos] - 96]--;
        }
    }
    for (i = 0; i < tamA; i++)
        A[i] = B[i];

}

void RadixSort(int tmax,int tamA){
    int i;
    for (i = tmax-1; i >= 0; i--) {
        CountingSort(tamA, i);
    }
}


int main() {
    int num, P, M,i,j,tmax=0;
    cin >> num;
    for (i=0; i<num;i++){
        cin >> A[i].nome;
    }
    cin >> P >> M;
    for (i = 0;i<num;i++){
        if (A[i].nome.length() > tmax){
            tmax = A[i].nome.length();
        }
    }
    for (i=0;i<num;i++){
        for(j=0;j<A[i].nome.length();j++){
            A[i].nome[j] = tolower(A[i].nome[j]);
        }
    }

    RadixSort(tmax,num);

    for(i=P-1;i<num;i++){
        cout << B[i].nome << endl;
    }

    return 0;
}
