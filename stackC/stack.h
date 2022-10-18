#pragma once 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int top;
	size_t size;
	int* items;
} stack_handle;
bool isEmpty(stack_handle* s);
void push(stack_handle* s, int element);
int pop(stack_handle* s);
void clear(stack_handle* s);
void init(stack_handle* s);
void destroy(stack_handle* s);
