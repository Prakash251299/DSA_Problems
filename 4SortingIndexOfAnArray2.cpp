/* This index sorting works for all type of data and sorting algorithm has no effect on the index sorting. Index sorting is done
using hashmap before sorting and after sorting. */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v = {32,43,5,23,53,5};
    unordered_map<int,vector<int>>m;
    vector<int> sortedIndex;
  	/* Storing indexes into hashmap */
  	for(int i=0;i<v.size();i++){
  		m[v[i]].push_back(i);
  	}
  	/* Sort is called */
  	sort(v.begin(),v.end());
  	/* Storing sorted indexes into a vector */
  	for(int j=0;j<v.size();j++){
  		if(j==0){
  			for(auto x:m[v[j]]){
  				sortedIndex.push_back(x);
  			}
  		}
  		if(j>0 and v[j]!=v[j-1]){
  			for(auto x:m[v[j]]){
  				sortedIndex.push_back(x);
  			}
  		}
  	}
    for(auto x:sortedIndex){
  		cout<<x<<" ";
  	}
  return 0;
}
