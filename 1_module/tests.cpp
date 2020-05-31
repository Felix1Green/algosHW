#include <iostream>

using std::cin;

int* input(int n){
    int *A = new int[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    return A;
}

int main(){
    int n = 0;
    cin >> n;
    int* A = input(n);
    int* B = input(n);
    int max = A[0];int maxsum = A[0] + B[0];
    for(int i =1 ; i < n; i++){
        if(max > A[i])
            A[i] = max;
        else
            max = A[i];
    }
    int a= 0,b = 0;
    for(int i = 0; i < n; i++){
        if(A[i] + B[i] > maxsum){
            maxsum = A[i] + B[i];b = i;a = A[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(A[i] == a){
            a = i;
            break;
        }
    }
    std::cout << a << " " << b << std::endl;
    return 0;
}