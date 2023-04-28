#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> a = {2,8,4,6,12,2,5};
	vector<int>v;
	vector<int>v1;
	vector<int>rightSmall;
	int i=0;
	while(1){
		if(i>=a.size()){
			break;
		}
		if(v.size()==0){
			rightSmall.push_back(-1);
			v.push_back(a[i]);
			i++;
		}else{
			if(v[v.size()-1]<a[i]){
				rightSmall.push_back(v[v.size()-1]);
				v.push_back(a[i]);
				i++;
			}else{
				v.pop_back();
			}
		}
	}
	for(i=0;i<rightSmall.size();i++){
		cout<<rightSmall[i]<<" ";
	}
	return 0;
}