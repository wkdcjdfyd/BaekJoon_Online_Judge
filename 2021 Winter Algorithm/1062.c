#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int check_alph[26];
char word[51][16];
int select_cnt;
int max, N, K;

void compare() {
	int temp[26];
	int i, j, compare;
	int result = 0;

	for (i = 0; i < 26; i++) {
		temp[i] = 0;
	}

	for (j = 0; j < N; j++) {
		compare = 1;
		for (i = 0; i < strlen(word[j]); i++) {
			if (check_alph[word[j][i] - 'a'] != 1) {
				compare = 0;
				break;
			}
		}
		if (compare == 1) {
			result++;
		}
	}
	if (max < result) {
		max = result;
	}
}

 void dfs(int index) {
	int i;
	check_alph[index] = 1;
	select_cnt++;

	if (select_cnt == K) {
		compare();
	}
	else{
		for (i = index + 1; i < 26; i++) {
			if (check_alph[i] == 0) {
				dfs(i);
			}
		}
	}
	check_alph[index] = 0;
	select_cnt--;
}

int main() {
	int i;

	select_cnt = 5;
	max = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < 26; i++) {
		check_alph[i] = 0;
	}

	check_alph['a' - 'a'] = 1;
	check_alph['n' - 'a'] = 1;
	check_alph['t' - 'a'] = 1;
	check_alph['c' - 'a'] = 1;
	check_alph['i' - 'a'] = 1;

	for (i = 0; i < N; i++) {
		scanf("%s", word[i]);
	}


	for (i = 0; i < 26; i++) {
		if (check_alph[i] == 0) {
			dfs(i);
		}
	}

	if (K < 5) {
		printf("0\n");
	}
	else if (K == 5) {
		compare();
		printf("%d\n", max);
	}
	else {
		for (i = 0; i < 26; i++) {
			if (check_alph[i] == 0) {
				dfs(i);
			}
		}

		printf("%d\n", max);
	}

	return 0;
}