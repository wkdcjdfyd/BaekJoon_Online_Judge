#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000000000
#define MIN -1000000000

int err_check;

typedef struct Stack {
	long long arr[10000];
	int TOS;
	int size;
}stack;

void check(long long n) {
	if (n > MAX || n < MIN) {
		err_check = 1;
		return;
	}
	return;
}

void PUSH(stack *S, long long num) {
	check(num);
	if (err_check == 1) {
		return;
	}
	S->arr[++S->TOS] = num;
	S->size++;
}

void POP(stack *S) {
	if (S->TOS < 0) {
		err_check = 1;
		return;
	}
	S->size--;
	S->TOS--;
}

void INV(stack *S) {
	if (S->TOS < 0) {
		err_check = 1;
		return;
	}
	S->arr[S->TOS] = -S->arr[S->TOS];
}

void DUP(stack *S) {
	if (S->TOS < 0) {
		err_check = 1;
		return;
	}
	PUSH(S, S->arr[S->TOS]);
}

void SWP(stack *S) {
	if (S->TOS < 1) {
		err_check = 1;
		return;
	}
	long long temp = S->arr[S->TOS];
	S->arr[S->TOS] = S->arr[S->TOS - 1];
	S->arr[S->TOS - 1] = temp;
}

void ADD(stack *S) {
	long long temp;
	
	if (S->TOS < 1) {
		err_check = 1;
		return;
	}
	temp = S->arr[S->TOS] + S->arr[S->TOS - 1];
	check(temp);
	
	if (err_check == 1) {
		return;
	}
	
	S->arr[S->TOS - 1] = temp;
	S->TOS--;
}

void SUB(stack *S) {
	long long temp;

	if (S->TOS < 1) {
		err_check = 1;
		return;
	}
	temp = S->arr[S->TOS - 1] - S->arr[S->TOS];
	check(temp);

	if (err_check == 1) {
		return;
	}

	S->arr[S->TOS - 1] = temp;
	S->TOS--;
}

void MUL(stack *S) {
	long long temp;

	if (S->TOS < 1) {
		err_check = 1;
		return;
	}
	temp = S->arr[S->TOS] * S->arr[S->TOS - 1];
	check(temp);

	if (err_check == 1) {
		return;
	}

	S->arr[S->TOS - 1] = temp;
	S->TOS--;
}

void DIV(stack *S) {
	if (S->TOS < 1) {
		err_check = 1;
		return;
	}
	if (S->arr[S->TOS] == 0) {
		err_check = 1;
		return;
	}
	long long temp1, temp2;

	if (S->arr[S->TOS - 1] < 0) {
		temp1 = -S->arr[S->TOS - 1];
		if (S->arr[S->TOS] < 0) {
			temp2 = -S->arr[S->TOS];
			S->arr[S->TOS - 1] = temp1 / temp2;
		}
		else {
			temp2 = S->arr[S->TOS];
			S->arr[S->TOS - 1] = -(temp1 / temp2);
		}
	}
	else {
		temp1 = S->arr[S->TOS - 1];
		if (S->arr[S->TOS] < 0) {
			temp2 = -S->arr[S->TOS];
			S->arr[S->TOS - 1] = -(temp1 / temp2);
		}
		else {
			temp2 = S->arr[S->TOS];
			S->arr[S->TOS - 1] = temp1 / temp2;
		}
	}
	S->TOS--;
}

void MOD(stack *S) {
	if (S->TOS < 1) {
		err_check = 1;
		return;
	}
	if (S->arr[S->TOS] == 0) {
		err_check = 1;
		return;
	}
	long long temp1, temp2;

	if (S->arr[S->TOS - 1] < 0) {
		temp1 = -S->arr[S->TOS - 1];
		if (S->arr[S->TOS] < 0) {
			temp2 = -S->arr[S->TOS];
		}
		else {
			temp2 = S->arr[S->TOS];
		}
		S->arr[S->TOS - 1] = -(temp1 % temp2);
	}
	else {
		temp1 = S->arr[S->TOS - 1];
		if (S->arr[S->TOS] < 0) {
			temp2 = -S->arr[S->TOS];
		}
		else {
			temp2 = S->arr[S->TOS];
		}
		S->arr[S->TOS - 1] = temp1 % temp2;
	}
	S->TOS--;
}


int main() {
	int N, i, j;
	long long temp;
	char order[5];
	int NUM_cnt;
	int cur_num;
	int NUM[10000];
	int cmd[100000];
	int cmd_cnt;
	stack S;

	while (1) {
		NUM_cnt = 0;
		cmd_cnt = 0;
		while (1) {
			scanf("%s", order);

			if (order[0] == 'Q') {
				return 0;
			}
			else if (order[0] == 'E') {
				break;
			}
			else if (order[0] == 'N') {
				scanf("%lld", &temp);
				NUM[NUM_cnt++] = temp;
				cmd[cmd_cnt++] = 0;
			}
			else if (order[0] == 'P') {
				cmd[cmd_cnt++] = 1;
			}
			else if (order[0] == 'I') {
				cmd[cmd_cnt++] = 2;
			}
			else if (order[0] == 'D') {
				if (order[1] == 'U') {
					cmd[cmd_cnt++] = 3;
				}
				else if (order[1] == 'I') {
					cmd[cmd_cnt++] = 8;
				}
			}
			else if (order[0] == 'S') {
				if (order[1] == 'W') {
					cmd[cmd_cnt++] = 4;
				}
				else if (order[1] == 'U') {
					cmd[cmd_cnt++] = 6;
				}
			}
			else if (order[0] == 'A') {
				cmd[cmd_cnt++] = 5;
			}
			else if (order[0] == 'M') {
				if (order[1] == 'U') {
					cmd[cmd_cnt++] = 7;
				}
				else if (order[1] == 'O') {
					cmd[cmd_cnt++] = 9;
				}
			}
		}

		scanf("%d", &N);

		for (i = 0; i < N; i++) {
			err_check = 0;
			cur_num = 0;
			S.size = 0;
			S.TOS = -1;

			scanf("%lld", &temp);
			PUSH(&S, temp);

			for (j = 0; j < cmd_cnt; j++) {
				if (cmd[j] == 0) {
					PUSH(&S, NUM[cur_num++]);
				}
				else if (cmd[j] == 1) {
					POP(&S);
				}
				else if (cmd[j] == 2) {
					INV(&S);
				}
				else if (cmd[j] == 3) {
					DUP(&S);
				}
				else if (cmd[j] == 4) {
					SWP(&S);
				}
				else if (cmd[j] == 5) {
					ADD(&S);
				}
				else if (cmd[j] == 6) {
					SUB(&S);
				}
				else if (cmd[j] == 7) {
					MUL(&S);
				}
				else if (cmd[j] == 8) {
					DIV(&S);
				}
				else if (cmd[j] == 9) {
					MOD(&S);
				}
				if (err_check == 1) {
					break;
				}
			}
			if (err_check != 1 && S.TOS == 0) {
				check(S.arr[S.TOS]);
				if (err_check == 1) {
					printf("ERROR\n");
				}
				else {
					printf("%Ild\n", S.arr[S.TOS]);
				}
			}
			else {
				printf("ERROR\n");
			}
		}
		printf("\n");
	}
}