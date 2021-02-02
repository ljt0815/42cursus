#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int age;
    double height;
} element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    return p;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p != 0; p = p->link)
    {
        printf("Name : %s\n", p->data.name);
        printf("Age : %d\n", p->data.age);
        printf("Height : %.1lf\n", p->data.height);
        puts("------------------------");
    }
    printf("NULL \n");
}

void remove_odd_node(ListNode** head) {
    ListNode *p = NULL, *removed, *tmp;
	
    tmp = *head;
    *head = (*head)->link;
    free(tmp);
	removed = *head;

	while (removed->link != NULL) {
		p = removed;
		removed = removed->link;
        tmp = p->link;
		p->link = removed->link;
		if (removed->link != NULL)
        {
			removed = removed->link;
            free(tmp);
        }
		else
			break;
	}
	return;
}

int main(void)
{
    ListNode* database = 0, *tmp;

    
    database = insert_first(database, (element){"choi", 10, 1.3});
    database = insert_first(database, (element){"choi", 9, 1.3});
    database = insert_first(database, (element){"lee", 8, 1.4});
    database = insert_first(database, (element){"park", 7, 1.2});
    database = insert_first(database, (element){"kim", 6, 1.7});
    database = insert_first(database, (element){"kim", 5, 1.7});
    database = insert_first(database, (element){"kim", 4, 1.7});
    database = insert_first(database, (element){"kim", 3, 1.7});
    database = insert_first(database, (element){"kim", 2, 1.7});
    database = insert_first(database, (element){"kim", 1, 1.7});

    remove_odd_node(&database);
    
    print_list(database);
    while (database != 0)
    {
        tmp = database;
        database = database->link;
        free(tmp);
    }
    database = 0;

    return 0;
}