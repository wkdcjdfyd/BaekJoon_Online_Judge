/*
	2609번

	문제
	두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

	출력
	첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int a, int b) {
	return b ? GCD(b, a%b) : a;
}

int main() {
	int n, m, num;

	scanf("%d %d", &n, &m);

	num = GCD(n, m);

	printf("%d\n", num);
	printf("%d\n", (n*m) / num);

	return 0;
}