#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> a = {2,8,4,6,12,2,5};
	vector<int>v;
	vector<int>v1;
	vector<int>leftSmall;
	int i=0;
	while(1){
		if(i>=a.size()){
			break;
		}
		if(v.size()==0){
			leftSmall.push_back(0);
			v.push_back(i);
			i++;
		}else{
			if(a[v[v.size()-1]]<a[i]){
				leftSmall.push_back(v[v.size()-1]);
				v.push_back(i);
				i++;
			}else{
				v.pop_back();
			}
		}
	}
	for(i=0;i<leftSmall.size();i++){
		cout<<leftSmall[i]<<" ";
	}
	return 0;
}