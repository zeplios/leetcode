typedef struct {
    int * instack;
    int instacktop;
    int * outstack;
    int outstacktop;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->instack = malloc(maxSize * sizeof(int));
    queue->outstack = malloc(maxSize * sizeof(int));
    queue->instacktop = 0;
    queue->outstacktop = 0;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    queue->instack[queue->instacktop++] = element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if (queue->outstacktop == 0) {
        while (queue->instacktop > 0) {
            queue->outstack[queue->outstacktop++] = queue->instack[--queue->instacktop];
        }
    }
    if (queue->outstacktop > 0) {
        --queue->outstacktop;
    }
}

/* Get the front element */
int queuePeek(Queue *queue) {
    if (queue->outstacktop == 0) {
        while (queue->instacktop > 0) {
            queue->outstack[queue->outstacktop++] = queue->instack[--queue->instacktop];
        }
    }
    if (queue->outstacktop == 0) {
        return -1;
    } else {
        return queue->outstack[queue->outstacktop-1];
    }
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return queue->instacktop == 0 && queue->outstacktop == 0;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    free(queue->instack);
    free(queue->outstack);
}