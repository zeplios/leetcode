typedef struct {
    int *queue1;
    int q1first, q1last;
    int *queue2;
    int q2first, q2last;
    int maxSize;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->queue1 = malloc(maxSize * sizeof(int));
    stack->queue2 = malloc(maxSize * sizeof(int));
    stack->q1first = 0;
    stack->q1last = 0;
    stack->q2first = 0;
    stack->q2last = 0;
    stack->maxSize = maxSize;
}

int size(Stack * stack) {
    if (stack->q1last >= stack->q1first) {
        return stack->q1last - stack->q1first;
    } else {
        return stack->q1last + stack->maxSize - stack->q1first;
    }
}

void swap(Stack *stack) {
    int * tmp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = tmp;
    int temp = stack->q1first;
    stack->q1first = stack->q2first;
    stack->q2first = temp;
    temp = stack->q1last;
    stack->q1last = stack->q2last;
    stack->q2last = temp;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    stack->queue1[stack->q1last++] = element;
    stack->q1last == stack->q1last % stack->maxSize;
    if (stack->q1last == stack->q1first) { // account for overflow
        stack->q1first++;
        stack->q1first == stack->q1first % stack->maxSize;
    }
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    if (stack->q1first == stack->q1last) {
        return;
    }
    while (size(stack) > 1) {
        stack->queue2[stack->q2last++] = stack->queue1[stack->q1first++];
        stack->q2last == stack->q2last % stack->maxSize;
        if (stack->q2last == stack->q2first) {
            stack->q2first++;
            stack->q2first == stack->q2first % stack->maxSize;
        }
        stack->q1first == stack->q1first % stack->maxSize;
    }
    stack->q1first++;
    stack->q1first == stack->q1first % stack->maxSize;
    
    swap(stack);
}

/* Get the top element */
int stackTop(Stack *stack) {
    if (stack->q1first == stack->q1last) {
        return -1;
    }
    while (size(stack) > 1) {
        stack->queue2[stack->q2last++] = stack->queue1[stack->q1first++];
        stack->q2last == stack->q2last % stack->maxSize;
        if (stack->q2last == stack->q2first) {
            stack->q2first++;
            stack->q2first == stack->q2first % stack->maxSize;
        }
        stack->q1first == stack->q1first % stack->maxSize;
    }
    int ret = stack->queue1[stack->q1first++];
    stack->q1first == stack->q1first % stack->maxSize;
    
    stack->queue2[stack->q2last++] = ret;
    stack->q2last == stack->q2last % stack->maxSize;
    if (stack->q2last == stack->q2first) {
        stack->q2first++;
        stack->q2first == stack->q2first % stack->maxSize;
    }
    
    swap(stack);
    
    return ret;
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->q1first == stack->q1last;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    free(stack->queue1);
    free(stack->queue2);
}