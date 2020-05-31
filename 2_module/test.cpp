#include <iostream>



int foo(int& a,int& b){
    a = b;
    return 0;
}

int main(){
    int* a = new int;
    int* b = new int;
    *a = 0;
    *b = 1;
    int c = 0;
    int d = 1;
    foo(c,d);
    return 0;
}