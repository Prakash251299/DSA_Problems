#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a = 0;
/* Binary search using recursion */
void binarySearch(vector<int>v,int data){
	if(v.size()==1){
		if(v[0]==data){
			a = 1;
			return;
		}
		return;
	}
	int mid = (v.size()-1)/2;
	vector<int>left;
	vector<int>right;
	
	if(data<v[mid]){
		for(int i=0;i<=mid;i++){
			left.push_back(v[i]);
		}
		binarySearch(left,data);
		return;
	}else{
		if(v[mid]==data){
			a = 1;
			return;
		}else{
			for(int i=mid+1;i<v.size();i++){
				right.push_back(v[i]);
			}
			binarySearch(right,data);
			return;
		}
	}
	return;
}

int main(){
	vector<int> v = {2,5,6,8,12};
	int in; // For data to search
	while(1){
		for(auto x:v){
			cout<<x<<" ";
		}
		cout<<"\n";
		cout<<"Enter a number to search\n";
		cin>>in;
		binarySearch(v,in);
		if(a==1){
			cout<<"Present\n";
		}else{
			cout<<"Not present\n";
		}
		a = 0;
	}
	return 0;
}
