！！！这个题非常坑人，用destroy方法来free指针，就会报RuntimeError！！！

typedef struct {
    int value;
    int curmin;
} Element;

typedef struct {
    Element * es;
    int cap;
    int top;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->es = malloc(maxSize * sizeof(Element));
    stack->cap = maxSize;
    stack->top = 0;
}

void minStackPush(MinStack *stack, int element) {
    if (stack == NULL || stack->es == NULL || stack->top >= stack->cap) {
        return;
    }
    stack->es[stack->top].value = element;
    stack->es[stack->top].curmin = element;
    if (stack->top > 0 && element > stack->es[stack->top-1].curmin) {
        stack->es[stack->top].curmin = stack->es[stack->top-1].curmin;
    }
    (stack->top)++;
}

void minStackPop(MinStack *stack) {
    if (stack->top > 0) {
        (stack->top)--;
    }
}

int minStackTop(MinStack *stack) {
    if (stack == NULL || stack->es == NULL || stack->top <= 0) {
        return 0;
    }
    return stack->es[stack->top-1].value;
}

int minStackGetMin(MinStack *stack) {
    if (stack == NULL || stack->es == NULL || stack->top <= 0) {
        return 0;
    }
    return stack->es[stack->top-1].curmin;
}

void minStackDestroy(MinStack *stack) {
    /*if (stack->es != NULL) {
        free(stack->es);
    }
    free(stack);*/
}