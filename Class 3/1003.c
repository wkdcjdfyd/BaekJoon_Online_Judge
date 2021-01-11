/*
	1620번

	문제
	fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

	fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
	fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
	두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
	fibonacci(0)은 0을 출력하고, 0을 리턴한다.
	fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
	첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
	fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
	1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 테스트 케이스의 개수 T가 주어진다.
	각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

	출력
	각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T, N, i;
	int S[41][2];

	S[0][0] = 1;
	S[0][1] = 0;
	S[1][0] = 0;
	S[1][1] = 1;

	scanf("%d", &T);

	for (i = 2; i < 41; i++) {
		S[i][0] = S[i - 1][0] + S[i - 2][0];
		S[i][1] = S[i - 1][1] + S[i - 2][1];
	}

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d %d\n", S[N][0], S[N][1]);
	}

	return 0;
}