/*4.	编写一个程序,输入n个(少于10个)学生的姓名、性别、 成绩、出生年月日及入学年月日,
输出成绩在80分以上的18岁以下的女生的姓名、成绩、出生和入学的年份。*/
/*孙亚荣 男 80 1999.4.3 2017.9.2  
松鼠 男  82 1998.6.3 2017.9.2  
卢本伟 男 78 1999.9.3 2017.9.2  
马飞 男 81 1999.4.3 2017.9.2  
晴子 女 90 2004.4.2 2017.9.2	*/ 

#include <stdio.h>

struct date{ 
	int year;
	int month;
	int day; 
};

struct STUDENT{ 
	char name[20]; 
	char sex[3];
	int scores;
	struct date birthday; 
	struct date start_school;
}; 
void input(struct STUDENT *p);
void output(struct STUDENT *p);
int main(void){
	
	int n=5; 
	struct STUDENT stu[n],*p=stu;
	int i;
	int age;
	 
	printf("请按顺序输入学生的姓名性别,成绩,出生年月日及及入学年月日\n"); 
    for (i = 0; i < n; i++){
    	printf("第%d个学生:\n", i+1);
 		input(p+i); 
    }   	
	printf("成绩大于80分且小于18岁的女生:\n", i+1);
  	for (i = 0; i < n; i++){
  		age = 2020 - ((p+i)->birthday.year); 
		if((p+i)->scores > 80 && age < 18){
			output(p+i);	
		}
    }   
 
	return 0;
} 
void input(struct STUDENT *p){
 
    scanf("%s %s %d", p->name, p->sex, &p->scores);
    scanf("%d.%d.%d ", &p->birthday.year, &p->birthday.month, &p->birthday.day);
    scanf("%d.%d.%d", &p->start_school.year, &p->start_school.month, &p->start_school.day);
}
void output(struct STUDENT *p){
	
 	printf("姓名:%s  性别:%s  成绩:%d  ", p->name, p->sex, p->scores);
	printf("生日:%d.%d.%d  ", p->birthday.year, p->birthday.month, p->birthday.day);
	printf("入学时间:%d.%d.%d\n", p->start_school.year, p->start_school.month, p->start_school.day);
}
