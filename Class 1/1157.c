/*
	1157번

	문제
	알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
	단, 대문자와 소문자를 구분하지 않는다.

	입력
	첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

	출력
	첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

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