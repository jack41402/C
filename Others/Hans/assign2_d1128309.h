typedef int ElemType;

typedef struct node {
	ElemType elem;
	struct node* next;
} Node;
typedef Node* Link;

typedef Link List;

void initial(List *);

int getSize(List);

ElemType setElem(List L, ElemType, int);

ElemType getElem(List L, int index);

int search(List, ElemType);

int insertElem(List *, ElemType);

int deleteElem(List *, ElemType);

void printList(List);

List append(List L1, List L2);

List join(List L1, List L2);

void sort(List *L);
