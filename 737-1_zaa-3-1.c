#include <stdio.h>
#include <stdlib.h>

 typedef struct node
{
	int value;
	struct node *next;
} node;

 typedef struct list 
 {
	 struct node* head;
	 struct node* tail;
 } list;

 typedef list* l;

 void init(list* l)
 {
	 l->head = NULL;
	 l->tail = NULL;
 } 

 int push_front(list* l, int value)
 {
	 node *tmp =(node*)malloc(sizeof(node));
	 tmp->value = value;
	 tmp->next = l->head;
	 l->head = tmp;
	 if (l->tail == NULL)
		 l->tail = l->head;
	 return 0;
 }
 int push_back(list* l, int value)
 {
	 if (l->head == NULL)
	 {
		 push_front(l, value);
	 }
	 else
	 {
		 node * tmp = (node*) malloc(sizeof(struct node));
		 tmp->value = value;
		 tmp->next = NULL;
		 l->tail->next = tmp;
		 l->tail = tmp;
	 }

	 return 0;
 }

 int insertAfter (list* l,int num,int value)
 {
	  node * tmp =l->head;
	  for (int i =1; i < num; ++i)
	  {
		  tmp= tmp->next;
		  if (tmp == NULL)
			  return 1;
	  }
	  node * tmp1 = (node*)malloc(sizeof(struct node));
	  tmp1->value = value;
	  tmp1->next = tmp->next;
	  tmp->next = tmp1;
	 return 0;
 }

  node* find(list* l, int value)
 {
	  for (struct node *i = l->head; i != NULL; i = i->next)
	  {
		  if (i->value == value)
			  return i;
	  }
	  return NULL;
 }

 int delet(list*l, int value) {
	 node*tmp;
	 node*p;
	 tmp = l->head;
	 while (tmp->value != value)
	 {
		 p = tmp;
		 tmp = tmp->next;
	 }
	 if (tmp == NULL)
		 return 1;
	 p->next = tmp->next;
	 free(tmp);
	 return 0;
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

void print(list* l)
{
	for (struct node *i = l->head; i != NULL; i = i->next)
		printf("%d ", i->value);
	printf("\n");
}

int main()
{
	list*l = (list*)malloc(sizeof(list));
	int i, n, p;
	init(l);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p);
		push_back(l, p);
	}
	print(l);
	int k;
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
	int m;
	scanf("%d", &m);
	push_back(l, m);
	print(l);
	int t;
	scanf("%d", &t);
	push_front(l, t);
	print(l);
	int j, x;
	scanf("%d%d", &j, &x);
	insertAfter(l,j, x);
	print(l);
	int z;
	scanf("%d", &z);
	delet(l, z);
	print(l);
	clear(l);
}
