#include <stdio.h>
int is_Triangle(int a,int b,int c);
int is_Isosceles(int a,int b,int c);
int is_equal_sides(int a,int b,int c);
int judge(int a,int b,int c); 
int main(void){
	
	int a,b,c;
	printf("请输入三角型的三条边长:"); scanf("%d %d %d",&a,&b,&c); 
	judge(a,b,c);
	
	return 0;
} 
int judge(int a,int b,int c){
	
	if(is_Triangle(a,b,c) == 1){
		if(is_equal_sides(a,b,c) == 1){
			printf("等边三角型");
		}
		else if(is_Isosceles(a,b,c) == 1){
			printf("等腰三角型");
		}	
		else {
			printf("普通三角型");
		} 
	}
	if(is_Triangle(a,b,c) == 0){
		printf("不能构成三角型!");
	} 
}
int is_Triangle(int a,int b,int c){
	
	if (a + b > c && a + c > b && b + c > a){
		return 1;
	}
	else{
		return 0;
	}
} 
int is_Isosceles(int a,int b,int c){
	
	if(a == b || a == c || b == c){
		return 1;
	}
	else{
		return 0;
	}
}
int is_equal_sides(int a,int b,int c){
	
	if (a == b && a == c){
		return 1;
	}
	else {
		return 0;
	}
}

