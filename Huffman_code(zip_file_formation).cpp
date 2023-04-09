#include<stdio.h>
#include<string.h>
int main(){
	int i=0,j=0,visited[26],ele[26];
	char a[] = "yrtjgjh";
	printf("%s %d",a,sizeof(a));
	for(i=0;i<123;i++){
		visited[i] = 0;
	}
	for(i=0;i<strlen(a);i++){
		if(visited[int(a[i])]){
			visited[int(a[i])] = 1;
		}
	}
	for(i=97,j=0;i<123;i++){
		if(visited[i]==1){
			ele[j] = i;
			j++;
		}
	}
	return 0;
}