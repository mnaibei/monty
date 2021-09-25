#include "monty.h"
/**
 * pushOp - push function for stack
 * @stack: points to head of stack
 * @line_number: current line number of file
 * Return: void
 */
void pushOp(stack_t **stack, unsigned int line_number)
{
stack_t *node, *new = malloc(sizeof(stack_t));
if (new == NULL)
{
free(new);
curIns[2] = strdup("OPFAIL");
dprintf(STDERR_FILENO, "Error: malloc failed\n");
return;
}

if (stack == NULL)
node = NULL;
else
node = *stack;

if (node == NULL)
{
new->next = NULL;
}
else
{
new->next = *stack;
node->prev = new;
}
new->prev = NULL;
new->n =  atoi(curIns[1]);
*stack = new;
line_number++;
line_number--;
/*return (*head);*/
}

/**
 * pallOp - prints stack
 * @stack: points to head of stack
 * @line_number: current line number of file
 * Return: void
 */
void pallOp(stack_t **stack, unsigned int line_number)
{
int i;
if (stack != NULL && *stack != NULL)
{
stack_t *h = *stack;
for (i = 0; h != NULL; i++, h = h->next)
printf("%i\n", h->n);
line_number++;
line_number--;
}
}

/**
 * pintOp - prints top of stack
 * @stack: points to head of stack
 * @line_number: current line number of file
 * Return: void
 */
void pintOp(stack_t **stack, unsigned int line_number)
{
stack_t *a = *stack;
if (stack == NULL || *stack == NULL)
{
dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
curIns[2] = strdup("OPFAIL");
return;
}
else
printf("%i\n", a->n);
/*return (i);*/
}

/**
 * popOp - removes top of stack
 * @stack: points to head of stack
 * @line_number: current line number of file
 * Return: void
 */
void popOp(stack_t **stack, unsigned int line_number)
{
stack_t *a, *b;
if (stack == NULL || *stack == NULL)
{
dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line_number);
curIns[2] = strdup("OPFAIL");
return;
}
a = *stack;
b = a->next;
if (b != NULL)
b->prev = NULL;
*stack = b;
free(a);
}

/**
 * swapOp - swaps top two numbers on stack
 * @stack: points to head of stack
 * @line_number: current line number of file
 * Return: void
 */
void swapOp(stack_t **stack, unsigned int line_number)
{
stack_t *a, *b;
int i;
if (stack == NULL || *stack == NULL)
{
dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
curIns[2] = strdup("OPFAIL");
return;
}
a = *stack;
b = a->next;
if (b == NULL)
{
dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
curIns[2] = strdup("OPFAIL");
return;
}
i = a->n;
a->n = b->n;
b->n = i;
}
