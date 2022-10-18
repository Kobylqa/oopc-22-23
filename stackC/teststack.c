#include "stack.h"

int main()
{
	int i = 0;
	stack_handle s1;
	stack_handle s2;
	init(&s1);
	init(&s2);
	if (isEmpty(&s1)) {
		printf("Stack is empty\n");
	}
	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);
	push(&s1, 8);
	push(&s1, 9);
	push(&s2, 5);
	push(&s2, 6);
	for (i = 0; i < 2; i++) {
		printf("popped from 1st %d, popped from 2nd %d\n", pop(&s1), pop(&s2));
	}
	for (i = 0; i < 3; i++){
		printf("popped from 2nd %d\n", pop(&s1));	
	}  
	destroy(&s1);
	// printf("popped from 2nd %d", pop(&s2));
	destroy(&s2);
	return 0;
}
