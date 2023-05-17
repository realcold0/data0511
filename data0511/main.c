#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 	// 리스트의 최대크기

typedef int element;			// 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE];	  // 배열 정의
	int size;		  // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	int count = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
		{
			count++;
			L->array[i + 1] = L->array[i];
		}
			
		L->array[pos] = item;
		L->size++;
		printf("Move : %d \n", count);
	}
	else {
		printf("please enter again number position\n");
	}
	
}
element delete(ArrayListType* L, int pos)
{
	element item;
	int count= 0;
	if (pos < 0 || pos >= L->size)
	{
		printf("list is empty\n");
		return;
	}
		
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
	{
		count++;
		L->array[i] = L->array[i + 1];
	}
	printf("Move : %d\n", count);
	printf("delete : %d\n", item);
	L->size--;
	return item;
}
int main(void)
{
	ArrayListType list;
	init(&list);
	int menu;
	while (1)
	{
		printf("Menu\n");
		printf("(1) Insert\n(2) Delete\n(3) Print\n(0) Exit\nEnter the Menu : ");
		scanf_s("%d", &menu);
		if (menu == 1)
		{
			int num;
			int pos;
			printf("ENter the number and position : ");
			scanf_s("%d %d", &num, &pos);
			insert(&list, pos, num);

		}
		else if (menu == 2)
		{
			if (is_empty(&list))
			{
				printf("list is empty\n");
				printf("\n========================================\n");
				continue;
			}
			int pos;
			printf("Enter the position : ");
			scanf_s(" %d", &pos);
			delete(&list, pos);
		}
		else if (menu == 3)
		{
			print_list(&list);
		}
		else if (menu == 0)
		{
			printf("exit the program\n");
			break;
		}
		else {
			printf("Please select again\n");
		}
		printf("\n========================================\n");
	}

	
	return 0;
}