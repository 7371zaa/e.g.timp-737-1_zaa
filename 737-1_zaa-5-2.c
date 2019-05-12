#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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


#define STACK_INIT_SIZE 100

typedef struct Stack {
	size_t size;
	size_t limit;
	node **data;
} Stack;

Stack* createStack() {
	Stack *tmp = (Stack*)malloc(sizeof(Stack));
	tmp->limit = STACK_INIT_SIZE;
	tmp->size = 0;
	tmp->data = (node**)malloc(tmp->limit * sizeof(node*));
	return tmp;
}

void freeStack(Stack **s) {
	free((*s)->data);
	free(*s);
	*s = NULL;
}

void push(Stack *s, node *item) {
	if (s->size >= s->limit) {
		s->limit *= 2;
		s->data = (node**)realloc(s->data, s->limit * sizeof(node*));
	}
	s->data[s->size++] = item;
}

node* pop(Stack *s) {
	if (s->size == 0) {
		exit(7);
	}
	s->size--;
	return s->data[s->size];
}

node* peek(Stack *s) {
	return s->data[s->size - 1];
}

int bypass(node* n)
{
	Stack *ps = createStack();
	while (ps->size != 0 || n != NULL) {
		if (n != NULL) {
			printf("%d ", n->value);
			if (n->right) {
				push(ps, n->right);
			}
			n = n->left;
		}
		else {
			n = pop(ps);
		}
	}
	freeStack(&ps);

}

int bypass_all(tree* t)
{
	node* n = t->root;
	if (bypass(n) == 0)
	{
		t->root = n->parent;
		return 0;
	}
	else
		return 1;
}


int main(void) {
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
