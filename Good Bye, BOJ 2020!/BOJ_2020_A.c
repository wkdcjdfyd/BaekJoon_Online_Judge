/*
	20528번
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i;
	char c1 = NULL;
	char c2 = NULL;
	char S[100];
	int result = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", &S);

		if (c1 == NULL) {
			c1 = S[0];
		}
		else {
			c2 = S[0];
			if (c1 != c2) {
				result = 0;
				break;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
