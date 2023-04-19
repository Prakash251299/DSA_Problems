#include<stdio.h>
#include<string.h>
int main(){
char a[50]={'a','a','a'};
int b[3]={0,0,0},i=0,n=0,len=0;
scanf("%d",&n);
while (i<n){
b[0]=0;
b[1]=0;
b[2]=0;
a[0]='a';
a[1]='a';
a[2]='a';
scanf("%s",&a);
len = strlen(a);
if(len==3){
if(a[0]=='P'){
  b[0]=1;
}
if(a[0]=='C'){
  b[1]=1;
}
if(a[0]=='M'){
  b[2]=1;
}
if(a[1]=='P'){
  b[0]=1;
}
if(a[1]=='C'){
  b[1]=1;
}
if(a[1]=='M'){
  b[2]=1;
}
if(a[2]=='P'){
  b[0]=1;
}
if(a[2]=='C'){
  b[1]=1;
}
if(a[2]=='M'){
  b[2]=1;
}}
if(b[0]!=0&&b[1]!=0&&b[2]!=0){
  printf("YES\n");
}
else{
printf("NO\n");
}
i++;
}
  return 0;
}