/*
	10869��

	����
	�� �ڿ��� A�� B�� �־�����. �̶�, A+B, A-B, A*B, A/B(��), A%B(������)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

	�Է�
	�� �ڿ��� A�� B�� �־�����. (1 �� A, B �� 10,000)

	���
	ù° �ٿ� A+B, ��° �ٿ� A-B, ��° �ٿ� A*B, ��° �ٿ� A/B, �ټ�° �ٿ� A%B�� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(){
    int a,b;

    scanf("%d %d", &a,&b);
    printf("%d\n%d\n%d\n%d\n%d\n",a+b,a-b,a*b,a/b,a%b);

    return 0;
}