/*
	1018번

	문제
	지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다.
	어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서
	8*8 크기의 체스판으로 만들려고 한다. 체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다.
	구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로
	칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다.
	하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다. 보드가 체스판처럼 칠해져 있다는 보장이 없어서,
	지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
	당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를
	구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
	둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

	출력
	첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

	참고 : https://mjeong9316.tistory.com/167
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M;
	int i, j, k, l;
	char arr[50][50];
	int cnt_W, cnt_B;
	int result = (50 * 50) / 2;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (k = 0; k < N - 7; k++) {
		for (l = 0; l < M - 7; l++) {
			cnt_B = 0;
			cnt_W = 0;
			for (i = k; i < k + 8; i++) {
				for (j = l; j < l + 8; j++) {
					if ((i + j) % 2 == 0) {
						if (arr[i][j] == 'W') {
							cnt_B++;
						}
						else {
							cnt_W++;
						}
					}
					else {
						if (arr[i][j] == 'W') {
							cnt_W++;
						}
						else {
							cnt_B++;
						}
					}
				}
			}
			if (result > cnt_W) {
				result = cnt_W;
			}
			if (result > cnt_B) {
				result = cnt_B;
			}
		}
	}
	printf("%d\n", result);

	return 0;
}