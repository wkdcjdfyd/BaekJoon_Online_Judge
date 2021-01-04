/*
	9012��

	����
	��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�.
	�� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���.
	�� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. ���� x �� VPS ��� �̰��� �ϳ���
	��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. �׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ�
	xy�� VPS �� �ȴ�. ���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�. 
	�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�.

	�Է�
	�Է� �����ʹ� ǥ�� �Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �־�����. �Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����.
	�� �׽�Ʈ �������� ù° �ٿ��� ��ȣ ���ڿ��� �� �ٿ� �־�����. �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�. 

	���
	����� ǥ�� ����� ����Ѵ�. ���� �Է� ��ȣ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(VPS)�̸� ��YES��, �ƴϸ� ��NO���� �� �ٿ� �ϳ��� ���ʴ�� ����ؾ� �Ѵ�. 

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct STACK {
	char arr[51];
	int index;
}stack;

void Check(char *temp) {
	stack S;
	int i;
	S.index = 0;

	for (i = 0; i < strlen(temp); i++) {
		if (temp[i] == '(') {
			S.arr[S.index++] = '(';
		}
		else if (temp[i] == ')') {
			if (S.index == 0) {
				S.arr[S.index] = ')';
				break;
			}
			else if (S.arr[S.index - 1] == '(') {
				S.index--;
				S.arr[S.index] = '0';
			}
		}
	}
	if (S.index == 0 && S.arr[S.index] == '0') {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main() {
	int N, i;
	char temp[51];
	
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", temp);
		Check(temp);
	}

	return 0;
}