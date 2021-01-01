/*
	1181��

	����
	���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	1. ���̰� ª�� �ͺ���
	2. ���̰� ������ ���� ������

	�Է�
	ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����.
	�־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

	���
	���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
	char str[51];
	int len;
}word;

int compare(const void *a, const void *b) {
	word tmp1 = *(word *)a;
	word tmp2 = *(word *)b;

	if (tmp1.len != tmp2.len) {
		return (tmp1.len - tmp2.len);
	}
	return strcmp(tmp1.str, tmp2.str);
}

int main() {
	int N, i;
	word *w;

	scanf("%d", &N);

	w = (word *)malloc(sizeof(word) * N);

	for (i = 0; i < N; i++) {
		scanf("%s", &w[i].str);
		w[i].len = strlen(w[i].str);
	}


	qsort(w, N, sizeof(word), compare);

	for (i = 0; i < N; i++) {
		if (strcmp(w[i].str, w[i + 1].str) != 0) {
			printf("%s\n", w[i].str);
		}
	}

	free(w);

	return 0;
}