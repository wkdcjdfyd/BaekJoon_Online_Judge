#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
	char name;
	node *left;
	node *right;
};

int find(node *tree, char x, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (tree[i].name == x) {
			return i;
		}
	}
	return - 1;
}

void preorder(node *root) {
	if (root == NULL) {
		return;
	}
	printf("%c", root->name);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%c", root->name);
	inorder(root->right);
}

void postorder(node *root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->name);
}

int main() {
	int N, i;
	char temp1, temp2, temp3;
	node tree[26];
	node *root = NULL;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		tree[i].name = 'A' + i;
		tree[i].left = NULL;
		tree[i].right = NULL;
	}

	root = &tree[0];

	for (i = 0; i < N; i++) {
		scanf(" %c %c %c", &temp1, &temp2, &temp3);
		if (temp2 != '.') {
			tree[find(tree, temp1, N)].left = &tree[find(tree, temp2, N)];
		}
		if (temp3 != '.') {
			tree[find(tree, temp1, N)].right = &tree[find(tree, temp3, N)];
		}
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	return 0;
}