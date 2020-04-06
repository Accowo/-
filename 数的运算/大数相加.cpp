#include <stdio.h>        
#include <string.h>                 			             	//0的ASCLL码 48  
char single_add(char a,char b,char c,char sum[],int i);
void big_number_add(char str1[],char str2[],char sum[]);	
void reverse(char sum[]);		
int main(void){
	
	char str1[40];
	char str2[40];
	char sum[41]={'\0'};
	printf("请输入number1:"); 
	scanf("%s",str1);
	printf("请输入number2:"); 
	scanf("%s",str2); 
	
 	big_number_add(str1,str2,sum);
 	
 	reverse(sum);	
 	
	printf("相加所得:%s",sum);

	
	return 0;
} 
char single_add(char a,char b,char c,char sum[],int i){
	unsigned char t=a+b+c;
	if(t>=154){
		sum[i]=t-106;
		return '1';
	}
	else{
		sum[i]=t-96;
		return '0';
	}
}	
void big_number_add(char str1[],char str2[],char sum[]){
	int len1=strlen(str1);
	int len2=strlen(str2);
	int i=0;
	char c='0';
	if(len1<len2){
		for(i=0;i<len2;i++){
			if(i<len1){
				c=single_add(str1[len1-1-i],str2[len2-1-i],c,sum,i);
			}
			else{
				c=single_add('0',str2[len2-1-i],c,sum,i);
			}
		}
	}
	else{
		for(i=0;i<len1;i++){
			if(i<len2){
				c=single_add(str1[len1-1-i],str2[len2-1-i],c,sum,i);
			}
			else{
				c=single_add(str1[len1-1-i],'0',c,sum,i);
			}
		}
	}
	if(c == '1'){
		sum[i]=c;
	}

}
void reverse(char sum[]){
	int len=strlen(sum); 
	int i;
	char temp;
	for(i=0;i<len/2;i++){
		temp=sum[i];
		sum[i]=sum[len-i-1];
		sum[len-i-1]=temp;
	} 
}		
