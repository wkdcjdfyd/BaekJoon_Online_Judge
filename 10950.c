/*
	10950��

	����
	�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
	�׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

	���
	�� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(){
    int a,b,N,i;
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
        scanf("%d %d", &a,&b);
        printf("%d\n",a+b);
    }
    
    return 0;
}