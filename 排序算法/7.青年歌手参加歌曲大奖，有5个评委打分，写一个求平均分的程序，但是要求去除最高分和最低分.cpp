#include <stdio.h>
void Judges_scoring(int a[],int n);
int highest_score(int a[],int n);
int lowest_score(int a[],int n);
int sum_score(int a[],int n);
float average(int sum,int high,int low,int n);
int main(){
	
	int a[5];
	int n=5;
	int high,low,sum;	
	float ave;
	
	Judges_scoring(a,n);
	
	high=highest_score(a,n);
	low=lowest_score(a,n);
	sum=sum_score(a,n);
	ave=average(sum,high,low,n);
	printf("去掉最高分和最低分的平均分:%f",ave);
	return 0;
} 
void Judges_scoring(int a[],int n){
	
	int i;
	for(i=0;i<n;i++){
		printf("请%d号评委打分:",i+1);
		scanf("%d",&a[i]);	
	}
}
int highest_score(int a[],int n){
	int i;
	int high=a[0];
	for(i=0;i<n;i++){
		if(a[i]>high){
			high=a[i]; 
		}
	}
	return high;
}
int lowest_score(int a[],int n){
	int i;
	int low=a[0];
	for(i=0;i<n;i++){
		if(a[i]<low){
			low=a[i]; 
		}
	}
	return low;
} 
int sum_score(int a[],int n){
	int i;
	int sum=0;
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	return sum;
} 

float average(int sum,int high,int low,int n){
	return (sum-high-low)/((n-2)*1.0);
} 
