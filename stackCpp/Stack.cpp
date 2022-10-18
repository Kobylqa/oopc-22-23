#include "Stack.h"
#define NEW_SIZE_GROWTH 2
using namespace std;

Stack::Stack()
{
    this->top = 0;
    this->size = 1;
    this->items = 0;
}

Stack::~Stack()
{
	cout << "Stack::~Stack() called" << endl;
    free(this->items);
}

bool Stack::isEmpty()
{
    return (this->top == 0);
}

void Stack::push(int element)
{
    if (this->top == 0 || (size_t)this->top >= this->size)
    {
        size_t newSize = this->size * NEW_SIZE_GROWTH;
        int *newItems = (int *)realloc(this->items, newSize * sizeof(int));
        if (newItems)
        {
            this->items = newItems;
            this->size = newSize;
        }
        else
        {
            cout << "Error during realloc. Aborting" << endl;
            abort();
        }
    }
    this->items[this->top++] = element;
}

int Stack::pop()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty. Aborting" << endl;
        abort();
    }
    return this->items[--this->top];
}
