/*
	3052��

	����
	�� �ڿ��� A�� B�� ���� ��, A%B�� A�� B�� ���� ������ �̴�. ���� ���, 7, 14, 27, 38�� 3���� ���� �������� 1, 2, 0, 2�̴�. 
	�� 10���� �Է¹��� ��, �̸� 42�� ���� �������� ���Ѵ�. �� ���� ���� �ٸ� ���� �� �� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٺ��� ����° �� ���� ���ڰ� �� �ٿ� �ϳ��� �־�����. �� ���ڴ� 1,000���� �۰ų� ����, ���� �ƴ� �����̴�.

	���
	ù° �ٿ�, 42�� �������� ��, ���� �ٸ� �������� �� �� �ִ��� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;

	if (A > B) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int num[10];
	int i, temp;
	int count = 1;

	for (i = 0; i < 10; i++) {
		scanf("%d", &temp);
		num[i] = temp % 42;
	}

	qsort(num, 10, sizeof(int), compare);

	temp = num[0];

	for (i = 1; i < 10; i++) {
		if (temp != num[i]) {
			count++;
			temp = num[i];
		}
	}

	printf("%d\n", count);

	return 0;
}