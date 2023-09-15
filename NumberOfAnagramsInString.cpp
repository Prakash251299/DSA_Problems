#include<iostream>
#include<string>
#include<vector>
using namespace std;
int anagram(string str,string ptr,int start){
//	cout<<start<<" ";
	int len = ptr.size();
	int i=0,j=0,flag=0;
	for(i=start;i<start+len;i++){
		flag=0;
		for(j=0;j<ptr.size();j++){
			if(str[i]==ptr[j]){
				ptr.erase(j,1);
				flag=1;
				break;
			}
		}
		if(flag==0){
			return 0;
		}
	}
//	cout<<ptr.size();
	if(ptr.size()==0){
		return 1;
	}
//	cout<<i-1<<"\n";
	return 0;
}
int main(){
	string str = "abccbdacba";
//	string str = "acbn";
	string ptr = "abc";
	vector<int>v;
	if(ptr.size()>str.size()){
		return 0;
	}
	int c=0;
	for(int i=0;i<str.size()-ptr.size()+1;i++){
		if(anagram(str,ptr,i)){
			v.push_back(i);
			c+=1;
		}
	}
	for(auto x:v){
		cout<<x<<" ";
	}
//	cout<<c;
	return 0;
}