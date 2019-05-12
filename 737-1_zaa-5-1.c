#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	const void*  ptr;
	struct node* next;
} node;

typedef struct {
	node* head;
	node* tail;
} queue;

typedef struct tree {
	int  key;
	struct tree* left;
	struct tree* right;
} tree;

tree* tree_insert(tree** t, int key) {
	tree* p = *t;
	while (p != NULL) {
		if (key == p->key)
			return p;
		else if (key < p->key) {
			t = &p->left;
			p = p->left;
		}
		else {
			t = &p->right;
			p = p->right;
		}
	}

	p = (tree*)malloc(sizeof(tree));
	if (p != NULL) {
		p->key = key;
		p->left = p->right = NULL;
		*t = p;
	}
	return p;
}


void clear(tree* t) {
	if (t != NULL) {
		if (t->left != NULL)
			clear(t->left);
		if (t->right != NULL)
			clear(t->right);
		free(t);
	}
}

void  queue_init(queue* q)
{
	q->head = q->tail = NULL;
}

int   queue_empty(queue* q)
{
	return (q->head == NULL);
}

const void* queue_front(queue* q)
{
	return q->head->ptr;
}

int queue_push(queue* q, const void* ptr) {
	node* p = (node*)malloc(sizeof(node));
	if (p != NULL) {
		p->ptr = ptr;
		p->next = NULL;
		if (q->head == NULL)
			q->head = q->tail = p;
		else {
			q->tail->next = p;
			q->tail = p;
		}
	}
	return (p != NULL);
}

void queue_pop(queue* q) {
	node* t;
	if (q->head != NULL) {
		t = q->head;
		q->head = q->head->next;
		free(t);
		if (q->head == NULL)
			q->tail = NULL;
	}
}

void bypass(FILE* _out, const tree* t) {
	const tree* p;
	queue q;
	queue_init(&q);

	queue_push(&q, t);
	while (!queue_empty(&q)) {
		p = (const tree*)queue_front(&q);
		queue_pop(&q);
		fprintf(_out, "%d ", p->key);
		if (p->left != NULL)
			queue_push(&q, p->left);
		if (p->right != NULL)
			queue_push(&q, p->right);
	}
}

int main(void) {
	int i, x;
	tree* t = NULL;
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &x);
		tree_insert(&t, x);
	}
	bypass(stdout, t);
	printf("\n");
	clear(t);
	return 0;
}
