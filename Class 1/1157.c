/*
	1157��

	����
	���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
	��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

	�Է�
	ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

	���
	ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int i, index;
	int result = -1;
	int result_index;
	char alp;
	int arr_len = 'z' - 'a' + 1;
	int *arr = (int *)malloc(sizeof(int)*arr_len);
	char temp[1000000];

	for (i = 0; i < arr_len; i++) {
		arr[i] = 0;
	}

	scanf("%s", temp);

	for (i = 0; i < strlen(temp); i++) {
		if (temp[i] >= 'a' && temp[i] <= 'z') {
			index = temp[i] - 'a';
			arr[index]++;
		}
		else if (temp[i] >= 'A' && temp[i] <= 'Z') {
			index = temp[i] - 'A';
			arr[index]++;
		}
	}

	for (i = 0; i < arr_len; i++) {
		if (arr[i] > result && arr[i] != 0) {
			result = arr[i];
			result_index = i;
		}
	}
	for (i = 0; i < arr_len; i++) {
		if (i != result_index && arr[i] == result && arr[i] != 0) {
			printf("?\n");
			return 0;
		}
	}

	alp = 'A' + result_index;

	printf("%c\n", alp);
	free(arr);

	return 0;
}