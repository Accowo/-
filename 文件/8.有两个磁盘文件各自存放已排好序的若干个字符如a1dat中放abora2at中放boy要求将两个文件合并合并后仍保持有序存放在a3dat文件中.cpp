/*
8.	�����������ļ������Դ�����ź�������ɸ��ַ�
����a1. dat �з�"abort"��a2.dat�з� "boy"��
Ҫ�������ļ��ϲ����ϲ����Ա�������
�����a3.dat�ļ��С�
*/
#include <stdio.h>

int main(void){
/*
	FILE *fp1 = fopen("a1.dat", "w");
	FILE *fp2 = fopen("a2.dat","w");
	if (fp1 == NULL || fp2 == NULL){
		perror("���ļ���������");
		return -1;
	}
	fputs("abort", fp1);
	fputs("boy", fp2);
	fclose(fp1);
	fclose(fp2);
*/

	FILE *fp3 = fopen("a1.dat", "r");
	FILE *fp4 = fopen("a2.dat","r");
	FILE *fp5 = fopen("a4.dat","w");
	
	if (fp3 == NULL || fp4 == NULL || fp5 == NULL ){
		perror("���ļ���������");
		return -1;
	}
	char ch1 = fgetc(fp3);
	char ch2 = fgetc(fp4);
	while(ch1 != EOF && ch2 != EOF){
		if (ch1 <= ch2){
			fputc(ch1,fp5);
			ch1 = fgetc(fp3);
		}
		else {
			fputc(ch2,fp5);
			ch2 = fgetc(fp4);
		}
	}
    while (ch1 != EOF){
    	fputc(ch1,fp5);
		ch1 = fgetc(fp3);
    }
    while (ch2 != EOF){
		fputc(ch2,fp5);
		ch2 = fgetc(fp4);
    }

	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	return 0;
}
