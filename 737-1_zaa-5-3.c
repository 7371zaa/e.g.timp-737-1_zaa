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

void init(tree* t) {
	t->root = NULL;
	t->size = 0;
}

void insert(tree* t, int value) {
	if (t->root == NULL) {
		t->root = (node*)malloc(sizeof(node));
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
				tmp->right = (node*)malloc(sizeof(node));
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
				tmp->left = (node*)malloc(sizeof(node));
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

int bypass(node* n)
{
	if (n != NULL)
	{
		bypass(n->left);
		bypass(n->right);
		if (n->parent != NULL)
		{
			printf("%d ", n->value);
		}
		else
		{
			printf("%d", n->value);
		}
		return 0;
	}
	else
		return 1;
}

int bypass_all(tree* t)
{
	node* n = t->root;
	if(bypass(n)==0)
	{ 
		t->root = n->parent;
		return 0;
	}
	else
		return 1;
}

int main() {
	tree* root = (tree*)malloc(sizeof(tree));
	init(root);
	int x;
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &x);
		insert(root, x);
	}
	bypass_all(root);
        printf("\n");
	clear(root);
	return 0;
}
