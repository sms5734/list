#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}


typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;



ListNode* reverse(ListNode* list) {
	ListNode* p, *q, * r;
	p = list;
q=NULL;

while (p!=NULL) {
	r = q;
	 q=p;
	p=p->link;
	q->link = r;
	
	
}
return q;
}

ListNode* insert(ListNode *list,element value){
	

ListNode*p=(ListNode *)malloc(sizeof(ListNode));

p->data=value;
p->link=list;
list = p;


return list;


}
ListNode* gen_list(int *a, int size) {
	ListNode* head2= NULL;
	
	printf("오름차순으로 정렬 :");
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (a[i] > a[j]) {
				SWAP(a[i],a[j])
			}
		}
		
		printf(" %d", a[i]);
	}
	ListNode* list = NULL;
	
	for(int i=0;i<size;i++){
	list=insert(list,a[i]);
	}
	head2 = reverse(list);
	return head2;
	
}
void print_list(ListNode* list) {
	
	for (ListNode* p = list; p != NULL; p = p->link)
		printf(" %d->", p->data);
	printf("NULL \n");
}
int main() {

	ListNode* head=NULL;
	
	int a[] = { 5,1,3,7,1,4,3,5,2,1,9,6,2,8,3 };
	head=gen_list(a, 15);
	printf("\n");
	print_list(head);

}