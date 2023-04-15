#include<stdio.h>
int main(){
	int i=0,j=0,k=0,l=0,n=0,m=0,count=0;
	printf("Enter size of square matrix\n");
	scanf("%d",&n);
	int A[n][n],store[n];
	for(i=0;i<n;i++){
		store[i] = n;
		printf("%d\n",store[i]);
		for(j=0;j<n;j++){
			A[i][j] = 0;
			printf("%d ",A[i][j]);
		}
	}
	printf("\n\n");
	int flag = 0;
	int h=0;
	for(m=0;m<n;m++){
//		count=0;
		for(i=0;i<n;i++){
			store[i] = n;
			for(j=0;j<n;j++){
				A[i][j] = 0;
			}
		}
		for(i=0;i<n;i++){
			if(flag==1){ 
				j=h;
				flag=0;
			}else{
				j=0;	// needed after every i(row) completion
			}
			for(;j<n;j++){
				if(store[i]==n){
					if(A[i][j]!=1){
						store[i] = j;
//						count++;
//						printf("j = %d\n",j);
					}
					else{
						continue;
					}
					k=0;l=0;
					for( ; ;k++){
						if(k==n or l==n){
							break;
						}
						A[i][l] = 1;
	//					printf("%d ",A[i][l]);
						A[k][j] = 1;
						l++;
					}
					k = i; l = j;
					for( ; ;k--){
						if(k<0 or l<0){
							break;
						}
						A[k][l] = 1;
						l--;
					}
					k = i; l = j;
					for( ; ;k++){
						if(k==n or l==n){
							break;
						}
						A[k][l] = 1;
						l++;
					}
					k = i; l = j;
					for( ; ;k++){
						if(k==n or l<0){
							break;
						}
						A[k][l] = 1;
						l--;
					}
					k=i;l=j;
					for( ; ;k--){
						if(k<0 or l==n){
							break;
						}
						A[k][l] = 1;
						l++;
					}
				}
				else break;
			}
			if(store[i]==n){
//				printf("Not possible for n queen\n");
				flag = 1;
				h++;break;
			}
		}
//		if(count==n-1){
//			for(int a=0;a<n;a++){
//				printf("%d ",store[a]);
//			}
//		}
		if(store[i]==n){
			count++;
			printf("count: %d\n",count);
			continue;
		}
		else{
			for(int a=0;a<n;a++){
				printf("%d ",store[a]);
			}
		}
		if(store[n-1]!=n){
//			for(int a=0;a<n;a++){
//				printf("%d ",store[a]);
//			}
			flag = 1;
			h++;
//			return 0;   // If uncommented then gives only one answer
		}
		
//		if(store[i]==n){
//			continue;
//		}else{
//			flag = 1;
//			h++;
//		}
//		if(store[n-1]!=n)

//		for(int a=0;a<n;a++){
//			printf("%d ",store[a]);
//		}
//		return 0;

//		printf("%d %d %d %d %d %d",store[0],store[1],store[2],store[3],store[4],store[5]);
		printf("\n");
	}
	
	return 0;
}