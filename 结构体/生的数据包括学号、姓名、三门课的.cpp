/*6.	有10个学生,每个学生的数据包括学号、姓名、三门课的成绩,
从键盘输入10个学生数据,要求打印出三门课总平均成绩,
以及最高分的学生的数据(包括学号、 姓名、三门课成绩、平均分数)。*/ 
/*17211164120 马飞 81 89 79 
17211164121 卢本伟 80 88 79 
17211164122 卢伟冰 82 79 89
17211164123 塞尔达 87 89 79 
17211164124 蔡徐坤 80 83 79 
17211164125 阿卡丽 79 73 90 
17211164126 阿木木 83 73 92 
17211164127 奥恩 67 88 83 
17211164128 艾克 90 93 93 
17211164129 潘森 88 74 74 */ 
#include <stdio.h>
#include <string.h>
struct SCORES{
	int Chinese;
	int Math;
	int English;
	int sum;
	int ave; 
}; 

struct STUDENT{ 
	char number[20]; 
	char name[20]; 
	struct SCORES scores;
}; 

void input(struct STUDENT *p);
void output(struct STUDENT *p);
char *Max(struct STUDENT *p, int n);
int main(void){
	
	int n=10; 
	struct STUDENT stu[n],*p=stu;
	int i;
	char *number;
	 
	printf("请按顺序输入学生的学号、姓名、三门课的成绩\n"); 
    for (i = 0; i < n; i++){
    	printf("第%d个学生:\n", i+1);
 		input(p+i); 
    }   	

  	for (i = 0; i < n; i++){
  		printf("第%d个学生:", i+1);
		output(p+i);	
    }   
 	
	number = Max(p,n); 
	printf("成绩最高的学生:\n"); 
    for (i = 0; i < n; i++){
    	if (strcmp(number,(p+i)->number) == 0){
    		output(p+i);
    		break;
		}
	}
 
	return 0;
} 
void input(struct STUDENT *p){
 
    scanf("%s %s", p->number, p->name);
    scanf("%d %d %d", &p->scores.Chinese, &p->scores.Math, &p->scores.English);
	p->scores.sum = p->scores.Chinese + p->scores.Math + p->scores.English;
	p->scores.ave = p->scores.sum / 3; 
}
void output(struct STUDENT *p){
	
 	printf("学号:%s  姓名:%s ", p->number, p->name);
	printf("语文:%d  数学:%d  英语:%d  ", p->scores.Chinese, p->scores.Math, p->scores.English);
	printf("平均成绩:%d\n", p->scores.ave);
}
char *Max(struct STUDENT *p, int n){
	
	int max = p->scores.ave; 
	char *number= p->number;
	int i;
	 
	for (i = 0; i < n; i++){
		if (max < (p+i)->scores.ave){
			number = (p+i)->number;
		}
	} 
	return number;
} 
