#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *prev;
} node;

typedef struct list
{
	struct node* head;
	struct node* tail;
} list;

typedef list* l;

int init(list* l)
{
	l->head = NULL;
	l->tail = NULL;
}
int isEmpty(list* l) {
	if (l->head = NULL)
		return 1;
	else return 0;
}

void DeleteAllNodes(struct node * l)
{
	if (l == NULL)
		return;
	if (l->next != NULL)
		DeleteAllNodes(l->next);
	free(l);
}

void clear(struct list* l)
{
	DeleteAllNodes(l->head);
}

node* find(list* l, int value) {
	for (node* tmp = l->head; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->value == value)
			return tmp;
	}
	return NULL;
}

int removeFirst(list *l, int value) {
	if (l->head->value == value)
	{
		node* tmp = l->head->next;
		free(l->head);
		tmp->prev = NULL;
		l->head = tmp;
		return 0;
	}
	node*cr = l->head;
	while (cr->value != value && cr != NULL)
	{
		cr = cr->next;
	}
	if (cr == NULL)
		return -1;
	if (l->tail == cr)
	{
		l->tail = l->tail->prev;
		l->tail->next = NULL;
		free(cr);
		return 0;
	}
	cr->next->prev = cr->prev;
	cr->prev->next = cr->next;
	free(cr);
	return 0;
}
int removeLast(list *l, int value) {
	if (l->tail->value == value)
	{
		node* tmp = l->tail->prev;
		free(l->tail);
		tmp->next = NULL;
		l->tail = tmp;
		return 0;
	}
	node *cr = l->tail;
	while (cr->value != value && cr != NULL)
	{
		cr = cr->prev;
	}
	if (cr == NULL)
		return -1;
	if (l->head == cr)
	{
		l->head= l->head->next;
		l->head->prev = NULL;
		free(cr);
		return 0;
	}
	cr->prev->next = cr->next;
	cr->next->prev = cr->prev;
	free(cr);
	return 0;
}
node* get_index(list*l, int index)
{
	node* tmp = l->head;
	for (int i =1; i < index && tmp != NULL;i++, tmp = tmp->next);
		return tmp;
}
int insertAfter(node*n, int value) {
	node*tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	tmp->prev = n;
	tmp->next = n->next;
	if(n->next !=NULL)
	{
		n->next->prev = tmp;
	}
	n->next = tmp;
	return 0;
}
int insertBefore(node*n, int value) {
	node*tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	tmp->next = n;
	tmp->prev = n->prev;
	if (n->prev != NULL)
	{
		n->prev->next = tmp;
	}
	n->prev = tmp;
	return 0;
}

int push_front(list *l, int value) {
	node*tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	if (l->head == NULL)
	{
		l->head = tmp;
		l->tail = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
		return 0;
	}
	tmp->next = l->head;
	l->head->prev = tmp;
	tmp->prev = NULL;
	l->head = tmp;
	return 0;
}
int push_back(list *l, int value) {

		if (l->head == NULL)
	{
		push_front(l, value);
		return 0;
	}
	node*tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	tmp->prev = l->tail;
	tmp->next = NULL;
	l->tail->next = tmp;
	l->tail = tmp;
	return 0;
}

void print(list *l)
{
	for (node* tmp = l->head; tmp != NULL; tmp = tmp->next)
		printf("%d ", tmp->value);
	printf("\n");
}
void print_invers(list *l) {
	for (node* tmp = l->tail; tmp != NULL; tmp = tmp->prev)
		printf("%d ", tmp->value);
	printf("\n");
	
}

int main() {
	list*l = (list*)malloc(sizeof(list));
	init(l);
	int i, n, p,k,m,t, j, x,u,y,z,r;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p);
		push_back(l, p);
	}
	print(l);
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &k);
		if (find(l, k) != 0)
		{
			printf("1");
		}
		else
			printf("0");
	}
	printf("\n");
	scanf("%d", &m);
	push_back(l, m);
	print_invers(l);
	scanf("%d", &t);
	push_front(l, t);
	print(l);
	scanf("%d%d", &j, &x);
	insertAfter(get_index(l,j), x);
	print_invers(l);
	scanf("%d%d", &u, &y);
	insertBefore(get_index(l,u),y);
	print(l);
	scanf("%d", &z);
	removeFirst(l, z);
	print_invers(l);
	scanf("%d", &r);
	removeLast(l, r);
	print(l);
	clear(l);
}
