/*6.	��10��ѧ��,ÿ��ѧ�������ݰ���ѧ�š����������ſεĳɼ�,
�Ӽ�������10��ѧ������,Ҫ���ӡ�����ſ���ƽ���ɼ�,
�Լ���߷ֵ�ѧ��������(����ѧ�š� ���������ſγɼ���ƽ������)��*/ 
/*17211164120 ��� 81 89 79 
17211164121 ¬��ΰ 80 88 79 
17211164122 ¬ΰ�� 82 79 89
17211164123 ������ 87 89 79 
17211164124 ������ 80 83 79 
17211164125 ������ 79 73 90 
17211164126 ��ľľ 83 73 92 
17211164127 �¶� 67 88 83 
17211164128 ���� 90 93 93 
17211164129 ��ɭ 88 74 74 */ 
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
	 
	printf("�밴˳������ѧ����ѧ�š����������ſεĳɼ�\n"); 
    for (i = 0; i < n; i++){
    	printf("��%d��ѧ��:\n", i+1);
 		input(p+i); 
    }   	

  	for (i = 0; i < n; i++){
  		printf("��%d��ѧ��:", i+1);
		output(p+i);	
    }   
 	
	number = Max(p,n); 
	printf("�ɼ���ߵ�ѧ��:\n"); 
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
	
 	printf("ѧ��:%s  ����:%s ", p->number, p->name);
	printf("����:%d  ��ѧ:%d  Ӣ��:%d  ", p->scores.Chinese, p->scores.Math, p->scores.English);
	printf("ƽ���ɼ�:%d\n", p->scores.ave);
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
