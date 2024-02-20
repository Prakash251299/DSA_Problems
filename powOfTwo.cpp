#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = -2;
    int number_of_bits = floor(log2(n))+1; // getting number of bits in the integer
    int a = pow(2,number_of_bits)-1; // geting an integeer having all ones of the size same as number of bits
    int onesComp = a^n; // XOR for getting 1's complement
    int twosComp = onesComp + 1;
    cout<<twosComp<<"\n";
    int powerOfTwo = (twosComp-n) == 0;
    cout<<powerOfTwo;
    

    return 0;
}