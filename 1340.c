#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int x) {
    s->data[++s->top] = x;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

bool empty(Stack *s) {
    return s->top == -1;
}

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

bool q_empty(Queue *q) {
    return q->front == q->rear;
}

int main() {
    int n, op, x;
    while (scanf("%d", &n) != EOF) {
        Stack s = {.top = -1};
        Queue q = {.front = 0, .rear = 0};
        Queue pq = {.front = 0, .rear = 0};
        
        bool isStack = true, isQueue = true, isPQ = true;
        
        while (n--) {
            scanf("%d %d", &op, &x);
            if (op == 1) {
                push(&s, x);
                enqueue(&q, x);
                enqueue(&pq, x);
            } else {
                if (empty(&s)) isStack = false;
                if (q_empty(&q)) isQueue = false;
                if (q_empty(&pq)) isPQ = false;
                
                if (isStack && pop(&s) != x) isStack = false;
                if (isQueue && dequeue(&q) != x) isQueue = false;
                
                int max_val = -1, max_idx = pq.front;
                for (int i = pq.front; i < pq.rear; i++) {
                    if (pq.data[i] > max_val) {
                        max_val = pq.data[i];
                        max_idx = i;
                    }
                }
                if (isPQ && max_val != x) isPQ = false;
                for (int i = max_idx; i < pq.rear - 1; i++) {
                    pq.data[i] = pq.data[i + 1];
                }
                pq.rear--;
            }
        }
        
        if (isStack + isQueue + isPQ > 1) printf("not sure\n");
        else if (isStack) printf("stack\n");
        else if (isQueue) printf("queue\n");
        else if (isPQ) printf("priority queue\n");
        else printf("impossible\n");
    }
    return 0;
}
