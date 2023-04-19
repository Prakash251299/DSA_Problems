/* Sorting an array and printing its index in the sorted order using hashmap {Due to use of map, this method is not applicable
for duplicate elements of the array} */

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	int n = 5;
	int a[n] = {5,3,7,6,9}; // Array element should be distinct
	map<int,int>m;
	for(int i=0;i<n;i++){
		m[a[i]] = i;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<m[a[i]]<<" ";
	}
	return 0;
}