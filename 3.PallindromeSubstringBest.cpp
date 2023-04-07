#include<iostream>
#include<string>
#include<set>
using namespace std;
//int m=0,n=0;
//int *longestPalindromeEvenStringSize(string s) {
////		int arr[2] = {0,0};
//		int st=0,end=0;
//        int i=0,j=0,k=0,max=1,siz=1,m=0,n=0;
//        for(;i<s.size()-1;i++){
//            if(s[i] == s[i+1]){
//                st = i;
//                end = i+1;
//                k=i+2;
//                j = i-1;
//                while(true){
//                    if(j<0 || k>=s.size()){
//                        break;
//                    }else{
//                        if(s[j]==s[k]){
//                            st = j;end = k;
//                            j--;k++;
//                        }else{
//                            break;
//                        }
//                    }
//                }
//            }else{
//            	if(s[i]==s[i+2]){
//            		st = i;
//            		end = i+2;
//            		for(j=i-1,k=i+3;;){
//						if(j<0 || k>=s.size()){
//							break;
//						}else{
//							if(s[j]==s[k]){
//								st = j;
//								end = k;
//								j--;k++;
//							}else{
//								break;
//							}
//						}
//					}
//				}
//			}
//            siz = end-st+1;
//                if(siz>max){
//                	m = st;
//                	n = end;
//                	max = siz;
//				}
//        }
//        return arr;
//}
//
//int* longestPalindromeOddStringSize(string s) {
//	int arr[2] = {0,0};
//	int i=0,j=0,k=0,max=1,siz=1,m=0,n=0;
//	int st = 0, end = 0;
//	for(int i=0;i<s.size();i++){
//		if(s[i]==s[i+2]){
//			st = i;
//			end = i+2;
//			for(j=i-1,k=i+3;;){
//				if(j<0 || k>=s.size()){
//					break;
//				}else{
//					if(s[j]==s[k]){
//						st = j;
//						end = k;
//						j--;k++;
//					}else{
//						break;
//					}
//				}
//			}
//		}else{
//			if(s[i]==s[i+1]){
//				st = i;
//				end = i+1;
//				k=i+2;
//                j = i-1;
//                while(true){
//                    if(j<0 || k>=s.size()){
//                        break;
//                    }else{
//                        if(s[j]==s[k]){
//                            st = j;
//                            end = k;
//                            j--;k++;
//                        }else{
//                            break;
//                        }
//                    }
//                }
//			}
//		}
//		siz = end-st+1;
//            if(siz>max){
//            	m = st;
//            	n = end;
//               	max = siz;
//			}
//	}
//	return arr;
//}

int main(){
	int st=0,end=0;
	int i=0,j=0,k=0,max=1,siz=1,m=0,n=0;
//	string s = "cbbd";
//	string s = "aabba";
	string s = "baaa"; // Error
//	string s = "xaabacxcabaaxcabaax";
//	string s = "xaabacxcabaax";
	string res="";
//	int arr[2] = {0,0};
	if(s.size()==1){
		res = s[0];
	}else{
		if(s.size()%2==0){
//			st=0;end=0;
//	        i=0;j=0;k=0;max=1;siz=1;m=0;n=0;
	        for(;i<s.size()-1;i++){
	            if(s[i] == s[i+1]){
	                st = i;
	                end = i+1;
	                k=i+2;
	                j = i-1;
	                while(true){
	                    if(j<0 || k>=s.size()){
	                        break;
	                    }else{
	                        if(s[j]==s[k]){
	                            st = j;end = k;
	                            j--;k++;
	                        }else{
	                            break;
	                        }
	                    }
	                }
	            }else{
	            	if(s[i]==s[i+2]){
	            		st = i;
	            		end = i+2;
	            		for(j=i-1,k=i+3;;){
							if(j<0 || k>=s.size()){
								break;
							}else{
								if(s[j]==s[k]){
									st = j;
									end = k;
									j--;k++;
								}else{
									break;
								}
							}
						}
					}
				}
	            siz = end-st+1;
	                if(siz>max){
	                	m = st;
	                	n = end;
	                	max = siz;
					}
	        }
//			arr = longestPalindromeEvenStringSize(s);
		}else{
//			int arr[2] = {0,0};
//			int i=0,j=0,k=0,max=1,siz=1,m=0,n=0;
//			int st = 0, end = 0;
//			st=0;end=0;
//	        i=0;j=0;k=0;max=1;siz=1;m=0;n=0;
			for(i=0;i<s.size();i++){
				if(s[i]==s[i+2]){
					st = i;
					end = i+2;
					for(j=i-1,k=i+3;;){
						if(j<0 || k>=s.size()){
							break;
						}else{
							if(s[j]==s[k]){
								st = j;
								end = k;
								j--;k++;
							}else{
								break;
							}
						}
					}
				}else{
					if(s[i]==s[i+1]){
						st = i;
						end = i+1;
						k=i+2;
		                j = i-1;
		                while(true){
		                    if(j<0 || k>=s.size()){
		                        break;
		                    }else{
		                        if(s[j]==s[k]){
		                            st = j;
		                            end = k;
		                            j--;k++;
		                        }else{
		                            break;
		                        }
		                    }
		                }
					}
				}
				siz = end-st+1;
		        if(siz>max){
		        	m = st;
		           	n = end;
		           	max = siz;
				}
			}
//			arr = longestPalindromeOddStringSize(s);
		}
	}
//	cout<<res;
	cout<<m<<" "<<n;
	return 0;
}