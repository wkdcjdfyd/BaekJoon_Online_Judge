/*
	10951��

	����
	�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.

	�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

	���
	�� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(){
    int a,b;
    
    while(scanf("%d %d", &a, &b) != EOF){
	printf("%d\n", a+b);
    }
    
    return 0;
}