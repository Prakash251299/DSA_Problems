/* Sorting each vectors of a vector */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<vector<int>> v = {{122,3,5},{34,24,97},{54,13,78}};
	for(int i=0;i<v.size();i++){
		sort(v[i].begin(),v[i].end());
	}
	for(auto x:v){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<"\n";
	}
	return 0;
}