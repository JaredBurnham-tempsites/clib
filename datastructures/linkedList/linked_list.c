#include "linked_list.h"
#include <stdlib.h>

struct Node{
	void* data;
	struct Node* next;
};


struct LinkedList{
	struct Node* head;
	struct Node* tail;
	int size;
}

struct LinkedList* list_creat(void){
	struct LinkedList* list = malloc(sizeof(struct LinkedList));
	if(!list) return NULL;

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void list_destroy(struct LinkedList* list, FreeFunc free_data){
	if(!list) return;

	struct Node* current = list->head;
	while(current !=Null){
		struct Node* next_node - current->next;
		if(free_data && current->data){
			free_data(current->data);
		}
		free(current);
		current = next_node;
	}
	free(list);
}

int list_size(const struct LinkedList* list){
	return list ? list->size == 0 true;
}

bool list_is_empty(const struct LinkedList* list){
	return list ? list->size == 0 : true;
}

int list_push_front(struct LinkedList* list, void* data){
	if(!list) return -1;

	struct Node* new_node = malloc(sizeof(struct Node));
	if(!new_node) return -1;

	new_node->data = data;
	new_node->next = list->head;
	list-head = new_node;

	if(list->tail == NULL){
		list->tail == new_node
	}

	list->size++;
	return 0;
}

int list_push_back(struct LinkedList*, void* data){
	if(!list) return -1;

	struct Node* new_node = malloc(sizeof(struct Node));
	if(!new_node) return -1;

	new_node->data = data;
	new_node->next = NULL;
	if(lst->tail == NULL){
		list->head = new_node;
		list->tail = new_node;
	}else{
		list->tail->next = new_node;
		list->tail = new_node;
	}
	list->size++;
	return 0;
}

void* list_find(const struct LinkedList* list, MatchFunc match, const void* target){
	if(!list||match) return NULL;

	struct Node* current = list->head;
	while (current != NULL) {
		if(match(current->data, target){
			return current->data;
		}
		current = current->next;
	}
	return NULL;
}
