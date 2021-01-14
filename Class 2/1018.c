/*
	1018��

	����
	�����̴� �ڽ��� ���ÿ��� MN���� ���� ���簢������ �������� �ִ� M*N ũ���� ���带 ã�Ҵ�.
	� ���簢���� ���������� ĥ���� �ְ�, �������� ������� ĥ���� �ִ�. �����̴� �� ���带 �߶�
	8*8 ũ���� ü�������� ������� �Ѵ�. ü������ �������� ����� �����Ƽ� ĥ���� �־�� �Ѵ�.
	��ü������, �� ĭ�� �������� ��� �� �ϳ��� ��ĥ�Ǿ� �ְ�, ���� �����ϴ� �� ���� �簢���� �ٸ� ������
	ĥ���� �־�� �Ѵ�. ���� �� ���Ǹ� ������ ü������ ��ĥ�ϴ� ���� �� �������̴�.
	�ϳ��� �� ���� �� ĭ�� ����� ���, �ϳ��� �������� ����̴�. ���尡 ü����ó�� ĥ���� �ִٴ� ������ ���,
	�����̴� 8*8 ũ���� ü�������� �߶� �Ŀ� �� ���� ���簢���� �ٽ� ĥ�ؾ߰ڴٰ� �����ߴ�.
	�翬�� 8*8 ũ��� �ƹ������� ��� �ȴ�. �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢���� �ּ� ������
	���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� N�� M�� �־�����. N�� M�� 8���� ũ�ų� ����, 50���� �۰ų� ���� �ڿ����̴�.
	��° �ٺ��� N���� �ٿ��� ������ �� ���� ���°� �־�����. B�� �������̸�, W�� ����̴�.

	���
	ù° �ٿ� �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢�� ������ �ּڰ��� ����Ѵ�.

	���� : https://mjeong9316.tistory.com/167
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