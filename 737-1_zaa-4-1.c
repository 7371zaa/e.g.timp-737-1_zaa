#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* left;
	struct node* right;
	struct node* parent;
	int value;
} node;

typedef struct tree
{
	int size;
	struct node* root;
} tree;

#define SIZE 128

void print(node* n) {
	printf("%d ", n->value);
	if (n->left != NULL)
		print(n->left);
	else
		printf("_\n");
	if (n->right != NULL)
		print(n->right);
	else
		printf("_\n");
	printf("\n");
}

int rotateLeft(node* n) {
	if (n->right != NULL) {
		node* tmp = n->right;
		n->right = NULL;
		n->parent = tmp;
		tmp->parent = NULL;
		tmp->left = n;
		return 0;
	}
	else
		return 1;
}

int root_rotateLeft(tree* t) {
	node* n = t->root;
	if (rotateLeft(n) == 0) {
		t->root = n->parent;
		return 0;
	}
	else
		return 1;
}

int rotateRight(node* n) {
	if (n->left != NULL) {
		node* tmp = n->left;
		n->left = NULL;
		n->parent = tmp;
		tmp->parent = NULL;
		tmp->right = n;
		return 0;
	}
	else
		return 1;
}

int root_rotateRight(tree* t) {
	node* n = t->root;
	if (rotateRight(n) == 0) {
		t->root = n->parent;
		return 0;
	}
	else
		return 1;
}


void insert(tree* t, int value) {
	if (t->root == NULL) {
		t->root =(node*)malloc(sizeof(node));
		t->root->value = value;
		t->root->left = t->root->right = t->root->parent = NULL;
		t->size = 1;
		return;
	}
	node* tmp = t->root;
	while (1) {
		if (tmp->value == value) {
			return;
		}
		if (value > tmp->value) {
			if (tmp->right == NULL) {
				tmp->right =(node*)malloc(sizeof(node));
				tmp->right->value = value;
				tmp->right->right = tmp->right->left = NULL;
				tmp->right->parent = tmp;
				t->size++;
				return;
			}
			else
				tmp = tmp->right;
		}
		else if (value < tmp->value) {
			if (tmp->left == NULL) {
				tmp->left =(node*) malloc(sizeof(node));
				tmp->left->value = value;
				tmp->left->left = tmp->left->left = NULL;
				tmp->left->parent = tmp;
				t->size++;
				return;
			}
			else
				tmp = tmp->left;
		}
	}
}

int find(tree* t, int value, node* n) {
	if (t->root == NULL) {
		return 1;
	}
	node* tmp = t->root;
	while (1) {
		if (tmp == NULL)
			return 1;
		if (tmp->value == value) {
			n->value = tmp->value;
			n->left = tmp->left;
			n->right = tmp->right;
			n->parent = tmp->parent;
			return 0;
		}
		if (value > tmp->value)
			tmp = tmp->right;
		else if (value < tmp->value)
			tmp = tmp->left;
	}
}

void init(tree* t) {
	t->root = NULL;
	t->size = 0;
}

int _remove(tree* t, int value) {
	if (t->root == NULL) {
		return 1;
	}
	node* tmp = t->root;
	while (1) {
		if (tmp == NULL)
			return 1;
		if (tmp->value == value) {
			if (tmp->left == NULL && tmp->right == NULL) {
				if (tmp->parent->left == tmp)
					tmp->parent->left = NULL;
				else if (tmp->parent->right == tmp)
					tmp->parent->right = NULL;
				t->size--;
				free(tmp);
				return 0;
			}
			else if (tmp->left != NULL && tmp->right == NULL) {
				if (tmp->parent->left == tmp)
					tmp->parent->left = tmp->left;
				else if (tmp->parent->right == tmp)
					tmp->parent->right = tmp->left;
				t->size--;
				free(tmp);
				return 0;
			}
			else if (tmp->left == NULL && tmp->right != NULL) {
				if (tmp->parent->left == tmp)
					tmp->parent->left = tmp->right;
				else if (tmp->parent->right == tmp)
					tmp->parent->right = tmp->right;
				t->size--;
				free(tmp);
				return 0;
			}
			else {
				tmp->value = removeMin(tmp->right);
				t->size--;
				return 0;
			}

		}
		if (value > tmp->value)
			tmp = tmp->right;
		else if (value < tmp->value)
			tmp = tmp->left;
	}
}

int removeMin(node* n) {
	if (n != NULL) {
		if (n->left != NULL)
			return removeMin(n->left);
		else {
			if (n->right != NULL) {
				n->parent->right = n->right;
				n->right = n->parent;
			}
			else
				n->parent->left = NULL;
			int res = n->value;
			free(n);
			n = NULL;
			return res;
		}
	}
}


void printTree(tree* t) {
	if (t->root != NULL) {
		node** nodes_to_print1 = (node**)malloc(sizeof(node)*SIZE);
		node** nodes_to_print2 = (node**)malloc(sizeof(node)*SIZE);
		int next_free_pos[2] = { 0,0 }, values_for_printing[2] = { 0,0 }, is_1 = 1;
		printf("%d\n", t->root->value);
		nodes_to_print1[next_free_pos[0]] = t->root->left;
		next_free_pos[0]++;
		nodes_to_print1[next_free_pos[0]] = t->root->right;
		next_free_pos[0]++;
		values_for_printing[0] = 1;

		while (values_for_printing[0] || values_for_printing[1]) {
			if (is_1) {
				values_for_printing[1] = 0;
				for (int i = 0; i < next_free_pos[0]; i++) {
					if (nodes_to_print1[i] != NULL) {
						printf("%d", nodes_to_print1[i]->value);
						nodes_to_print2[next_free_pos[1]] = nodes_to_print1[i]->left;
						next_free_pos[1]++;
						nodes_to_print2[next_free_pos[1]] = nodes_to_print1[i]->right;
						next_free_pos[1]++;
						if (nodes_to_print1[i]->left != NULL || nodes_to_print1[i]->right != NULL)
							values_for_printing[1] = 1;
					}
					else {
						printf("_");
						nodes_to_print2[next_free_pos[1]] = NULL;
						next_free_pos[1]++;
						nodes_to_print2[next_free_pos[1]] = NULL;
						next_free_pos[1]++;
					}
					if (i + 1 != next_free_pos[0]) {
						printf(" ");
					}
				}
				next_free_pos[0] = 0;
				is_1 = 0;
				values_for_printing[0] = 0;
				free(nodes_to_print1);
				nodes_to_print1 =(node**)malloc(sizeof(node)*SIZE);
			}
			else {
				values_for_printing[0] = 0;
				for (int i = 0; i < next_free_pos[1]; i++) {
					if (nodes_to_print2[i] != NULL) {
						printf("%d", nodes_to_print2[i]->value);
						nodes_to_print1[next_free_pos[0]] = nodes_to_print2[i]->left;
						next_free_pos[0]++;
						nodes_to_print1[next_free_pos[0]] = nodes_to_print2[i]->right;
						next_free_pos[0]++;
						if (nodes_to_print2[i]->left != NULL || nodes_to_print2[i]->right != NULL)
							values_for_printing[0] = 1;
					}
					else {
						printf("_");
						nodes_to_print1[next_free_pos[0]] = NULL;
						next_free_pos[0]++;
						nodes_to_print1[next_free_pos[0]] = NULL;
						next_free_pos[0]++;
					}
					if (i + 1 != next_free_pos[1]) {
						printf(" ");
					}
				}
				next_free_pos[1] = 0;
				is_1 = 1;
				values_for_printing[1] = 0;
				free(nodes_to_print2);
				nodes_to_print2 =(node**) malloc(sizeof(node)*SIZE);
			}
			printf("\n");
		}
	}
	else
		printf("-\n");
}

void clear_rame(node* n) {
	if (n != NULL) {
		if (n->left != NULL)
			clear_rame(n->left);
		if (n->right != NULL)
			clear_rame(n->right);
	}
	free(n);
	n = NULL;
}
void clear(tree* t) {
	clear_rame(t->root);
	t->root = NULL;
}

int main() {
	tree* root =(tree*)malloc(sizeof(tree));
	init(root);
	int t;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &t);
		insert(root, t);
	}
	printTree(root);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &t);
		insert(root, t);
	}
	printTree(root);

	int m;
	scanf("%d", &m);
	node* n =(node*)malloc(sizeof(node));
	if (find(root, m, n) == 0) {
		if (n->parent != NULL)
			printf("%d ", n->parent->value);
		else
			printf("_ ");
		if (n->left != NULL)
			printf("%d ", n->left->value);
		else
			printf("_ ");
		if (n->right != NULL)
			printf("%d\n", n->right->value);
		else
			printf("_\n");
	}
	else {
		printf("-\n");
	}

	scanf("%d", &m);
	if (find(root, m, n) == 0) {
		if (n->parent != NULL)
			printf("%d ", n->parent->value);
		else
			printf("_ ");
		if (n->left != NULL)
			printf("%d ", n->left->value);
		else
			printf("_ ");
		if (n->right != NULL)
			printf("%d\n", n->right->value);
		else
			printf("_\n");
	}
	else {
		printf("-\n");
	}
	int m1;
        scanf("%d", &m1);
	_remove(root, m1);
	printTree(root);
	while (root_rotateLeft(root) != 1);
	printTree(root);
	while (root_rotateRight(root) != 1);
	printTree(root);
	printf("%d\n", root->size);
	clear(root);
	printTree(root);
	return 0;
}
