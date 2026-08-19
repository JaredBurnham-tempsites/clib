#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool>

struct Node;
struct LinkedList;

//function pointer type for comparing data returns true if a match
typedef boof(*matchFunc)(const void* data, const void* target);

//function pointer type for freeing data automatically
typdef void (*FreeFunc)(void* data);

//public api
struct LinkedList* list_create(void);
void list_destroy(struct LinkedList* list, FreeFunc free_data);

int list_size(const struct LinkedList* list);
bool list_is_empty(const struct LinkedList* list);

int list_push_front(struct LinkedList* list, void* data);
int list_push_back(struct  LinkedList* list, void* data);

void* list_find(const struct LinkedList* list, MatchFunc match, const void* target);

#endif
