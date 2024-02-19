#include<iostream>
#include<vector>
using namespace std;
void settle(vector<int>&v){
    int j=0;
    for(int i = v.size()-1;;){
        if(i==0){
            break;
        }
        j = (i-1)/2;
        if(v[j]<v[i]){
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
        i=j;
    }
}
void insert(vector<int>&v,int a){
    v.push_back(a);
    settle(v);
}

void topDownSettle(vector<int>&v){
    int curr = 0;
    int i=curr*2+1,j=curr*2+2;
    while(i<v.size() and j<v.size()){
        if(v[i]<=v[j]){
            if(v[curr]>=v[j]){
                break;
            }else{
                int t = v[j];
                v[j] = v[curr];
                v[curr] = t;
                curr = j;
                i=curr*2+1,j=curr*2+2;
            }
        }else{
            if(v[curr]>=v[i]){
                break;
            }else{
                int t = v[i];
                v[i] = v[curr];
                v[curr] = t;
                curr = i;
                i=curr*2+1,j=curr*2+2;
            }
        }
    }
    while(i<v.size() and j>=v.size()){
        if(v[curr]>=v[i]){
            break;
        }else{
            int t = v[i];
            v[i] = v[curr];
            v[curr] = t;
            curr = i;
            i=curr*2+1,j=curr*2+2;
        }
    }
}

void del(vector<int>&v){
    cout<<v[0]<<" ";
    int a = v[v.size()-1];
    v.pop_back();
    v[0] = a;
    topDownSettle(v);
}

void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    vector<int>v;
    int a=0;
    insert(v,12);
    display(v);
    insert(v,10);
    display(v);
    insert(v,15);
    display(v);
    insert(v,9);
    display(v);
    insert(v,20);
    display(v);
    insert(v,14);
    display(v);
    insert(v,17);
    display(v);
    insert(v,10);
    display(v);

    while(v.size()!=0){
        del(v);
    }
    return 0;
}
