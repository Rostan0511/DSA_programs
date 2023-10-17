#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int Front;
    int Rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->Front=q->Rear=-1;
    q->Q=(int *)malloc(sizeof(int)*q->size);
}
void enqueue(struct Queue *q,int x)
{
    if(q->Rear==q->size-1)
    printf("Queue is Full\n");
    else
    {
        q->Rear++;
        q->Q[q->Rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->Rear==q->Front)
    printf("Queue is Empty\n");
    else
    {
        q->Front++;
        x=q->Q[q->Front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i;
    printf("Queue Element\n");
    for(i=q.Front+1;i<=q.Rear;i++)
    {
        printf("%d\t",q.Q[i]);
    }
    printf("\n");
}
int isEmpty(struct Queue q)
{
     if(q.Rear==q.Front)
     return 1;
     else
     return 0;
}
int isFull(struct Queue q)
{
    if(q.Rear==q.size-1)
     return 1;
     else
     return 0;
}
int First(struct Queue q)
{   
    int x=-1;
    if(!isEmpty(q))
    {
        return q.Q[q.Front+1];
    }
    return x;
}
int Last(struct Queue q)
{
    
    int x=-1;
    if(!isEmpty(q))
    {
        return q.Q[q.Rear];
    }
    return x;
}
int main()
{
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    Display(q);
    printf("Element dequeued:%d\n",dequeue(&q));
    Display(q);
    printf("Eement at First?:%d\n",First(q));
    printf("Eement at Last?:%d\n",Last(q));
    printf("Queue is Empty?:%d\n",isEmpty(q));
    printf("Queue is Full?:%d\n",isFull(q));
    return 0;
}
