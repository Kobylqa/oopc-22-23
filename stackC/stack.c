#include "stack.h"
#define NEW_SIZE_GROWTH 2

void init(stack_handle* s)
{
	s->top = 0;
	s->size = 1;
	s->items = 0;
}

bool isEmpty(stack_handle* s)
{
	if (s->top == 0) {
		return true;
	}
	else {
		return false;
	}
}

void destroy(stack_handle* s)
{
	free(s->items);
}

void push(stack_handle* s, int element)
{
	if (s->top >= s->size || s->top == 0) {
		size_t newSize = s->size * NEW_SIZE_GROWTH;
		int* newItems = realloc(s->items, newSize * sizeof(int));
		if (newItems) {
			s->items = newItems;
		}
		else {
			printf("Error during realloc. Abort called\n");
			abort();
		}
		s->size = newSize;
	}
	s->items[s->top++] = element;
}

int pop(stack_handle* s)
{
	if (isEmpty(s)) {
		printf("Stack is empty. Abort called\n");
		abort();
	}
	return s->items[--s->top];
}
