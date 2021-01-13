#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
	int TOS;
	int value[31];
}stack;

void Push(stack *S, int x) {
	S->value[++S->TOS] = x;
}

int Pop(stack *S) {
	return S->value[S->TOS--];
}

int main() {
	int i, temp_int, temp;
	int result = 0;
	char arr1[31];
	int arr2[31];

	stack S;
	S.TOS = -1;

	scanf("%s", arr1);

	for (i = 0; i < strlen(arr1); i++) {
		if (arr1[i] == '(') {
			arr2[i] = -1;
		}
		else if (arr1[i] == ')') {
			arr2[i] = -2;
		}
		else if (arr1[i] == '[') {
			arr2[i] = -3;
		}
		else if (arr1[i] == ']') {
			arr2[i] = -4;
		}
		else {
			arr2[i] = atoi(&arr1[i]);
		}
	}
	
	for (i = 0; i < strlen(arr1); i++) {
		temp_int = 0;

		if (arr2[i] == -2) {
			while (1) {
				temp = Pop(&S);
				if (S.TOS < -1) {
					printf("0\n");
					return 0;
				}
				if (temp == -1) {
					break;
				}
				temp_int += temp;
			}
			if (temp_int == 0) {
				temp_int = 1;
			}
			temp_int = temp_int * 2;
			Push(&S, temp_int);
		}
		else if (arr2[i] == -4) {
			while (1) {
				temp = Pop(&S);
				if (S.TOS < -1) {
					printf("0\n");
					return 0;
				}
				if (temp == -3) {
					break;
				}
				temp_int += temp;
			}
			if (temp_int == 0) {
				temp_int = 1;
			}
			temp_int = temp_int * 3;
			Push(&S, temp_int);
		}
		else {
			Push(&S, arr2[i]);
		}
	}

	if (S.TOS > -1) {
		for (i = 0; i <= S.TOS; i++) {
			if (S.value[i] < 0) {
				printf("0\n");
				return 0;
			}
			result += S.value[i];
		}
		printf("%d\n", result);
	}
	else {
		printf("0\n");
	}

	return 0;
}