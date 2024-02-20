#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 16;
    int number_of_bits = floor(log2(n))+1; // getting number of bits in the integer
    int a = pow(2,number_of_bits)-1; // geting an integeer having all ones of the size same as number of bits
    int onesComp = a^n; // XOR for getting 1's complement
    cout<<onesComp;
    return 0;
}