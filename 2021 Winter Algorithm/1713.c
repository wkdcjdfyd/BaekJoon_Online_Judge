#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct person {
	int num;
	int rec_num;
	int time;
}person;

int check_pic(person *pic, int num, int capacity) {
	int i;

	for (i = 0; i < capacity; i++) {
		if (pic[i].num == num) {
			return i;
		}
	}

	return -1;
}

int compare1(const void *a, const void *b) {
	person A = *(person *)a;
	person B = *(person *)b;

	if (A.rec_num > B.rec_num) {
		return 1;
	}
	else if(A.rec_num == B.rec_num){
		if (A.time > B.time) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

int compare2(const void *a, const void *b) {
	person A = *(person *)a;
	person B = *(person *)b;

	if (A.num > B.num) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int capacity, num, i, temp, check;
	int size = 0;
	person P[101];
	person pic[20];

	scanf("%d %d", &capacity, &num);

	for (i = 1; i < 101; i++) {
		P[i].num = i;
		P[i].rec_num = 0;
		P[i].time = -1;
	}
	for (i = 0; i < capacity; i++) {
		pic[i].num = 0;
		pic[i].rec_num = 0;
	}

	for (i = 0; i < num; i++) {
		scanf("%d", &temp);
		check = check_pic(pic, temp, capacity);
		if (check == -1) {
			P[temp].time = i;
			P[temp].rec_num++;

			if (size < capacity) {
				pic[size++] = P[temp];
			}
			else {
				qsort(pic, capacity, sizeof(person), compare1);
				P[pic[0].num].rec_num = 0;
				pic[0] = P[temp];
			}

		}
		else {
			pic[check].rec_num++;
		}
	}

	qsort(pic, capacity, sizeof(person), compare2);

	for (i = 0; i < capacity; i++) {
		if (pic[i].num != 0) {
			printf("%d\n", pic[i].num);
		}
	}

	return 0;
}