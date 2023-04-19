#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	int a=0;
	scanf("%d",&a);
//	a = a^1; // method-1
//	cout<<a;
//	a = 1-a; // method-2
//	cout<<a;
//	a = (a+1)%2; // method-3
//	cout<<a;
//	unordered_map<int,int> m; // method-4
//	m[0] = 1;
//	m[1] = 0;
//	cout<<m[a];
	int arr[2] = {1,0}; // method-5
	cout<<arr[a];
	return 0;
}