/*4.	��дһ������,����n��(����10��)ѧ�����������Ա� �ɼ������������ռ���ѧ������,
����ɼ���80�����ϵ�ѧ�����������Ա𡢳ɼ�����������ѧ����ݡ�*/
/*������ �� 80 1999.4.3 2017.9.2  
���� ��  82 1998.6.3 2017.9.2  
¬��ΰ �� 78 1999.9.3 2017.9.2  
��� �� 81 1999.4.3 2017.9.2  */ 

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
	
	struct STUDENT stu[4],*p=stu;
	int i;
	 
	printf("�밴˳������ѧ���������Ա�,�ɼ�,���������ռ�����ѧ������\n"); 
    for (i = 0; i < 4; i++){
    	printf("��%d��ѧ��:\n", i+1);
 		input(p+i); 
    }   	
	printf("�ɼ�����80�ֵ�ѧ��:\n", i+1);
  	for (i = 0; i < 4; i++){
		if((p+i)->scores > 80){
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
	
 	printf("����:%s  �Ա�:%s  �ɼ�:%d  ", p->name, p->sex, p->scores);
	printf("����:%d.%d.%d  ", p->birthday.year, p->birthday.month, p->birthday.day);
	printf("��ѧʱ��:%d.%d.%d\n", p->start_school.year, p->start_school.month, p->start_school.day);
}
