/*���ѧ����Ϣ*/
/*
81 89 79

80 88 79

82 79 89

87 89 79

80 83 79

79 73 90

83 73 92

67 88 83

90 93 93

88 74 74


17211164110 ��ϣ 15088298140



17211164100 �������� 15088298140
1
17211164101 ����˿ 15088298141
1
17211164102 �׿��� 15088298142
1
17211164103 ���� 15088298143
1
17211164104 ���� 15088298144
1
17211164105 ������ 15088298145
1
17211164106 ��ľľ 15088298146
1
17211164107 �¶� 15088298147
1
17211164108 ���� 15088298148
1
17211164109 ��ɭ 15088298149
q







*/
#include <stdio.h>
#include <string.h>

void input(struct STUDENT *p);
void output(struct STUDENT *p);
char *Max(struct STUDENT *p, int n);
int main(void){

	int n=100;
	struct STUDENT stu[n],*p=stu;
	int i;
	char *number;

    while(){
    	
	}
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
