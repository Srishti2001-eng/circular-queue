#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f;
    int size;
    int r;
    int *p;
};
void enqueue(struct queue *q,int n)
{
    if(q->f==0&&q->r==q->size-1)
    {
        printf("queue is full\n");
        return;
    }
    else if(q->f==-1&&q->r==-1)
    {
        q->f++;
        q->r++;
        q->p[q->r]=n;

    }
    else if(q->r+1%q->size==q->f)
    {
        printf("list is empty\n");
        return ;
    }
    else
    {
        q->r=q->r+1%q->size;
        q->p[q->r]=n;
    }
}
int dequeue(struct queue *q)
{
    if(q->f==-1&&q->r==-1)
    {
        printf("list is empty\n");
        exit(0);
    }
    else if(q->f==q->r)
    {int c=q->p[q->f];

        q->f=q->r=-1;
        return c;

    }
    else
    {
        int b=q->p[q->f];
        q->f=q->f+1%q->size;
        return b;
    }
}
void display(struct queue q)
{
    if(q.r+1%q.size==q.f)
    {
        return;

    }
    else if(q.f==-1&&q.r==-1)
    {
        printf("list is empty\n");
    }
    else
    {
        int d=dequeue(&q);
        printf("%d\n",d);
        display(q);
    }
}
int main()
{
    struct queue q;
    q.r=q.f=-1;
    printf("enter the size of the queue\n");
    scanf("%d",&q.size);
    q.p=(int *)malloc(sizeof(int)*q.size);
    int x,data,b;
    while(1)
    {
        printf("enter the operation \n1)enqueue\n2)dequeue\n3)display\n4)reverse\n5)end\n");
        scanf("%d",&x);
       switch(x)
       {
          case 1:printf("enter the data to be added\n");
                 scanf("%d",&data);
                 enqueue(&q,data);
                 break;
          case 2:b=dequeue(&q);
                 printf("the number removed form queue is %d\n",b);
                 break;
          case 3:printf("the q is \n");
                 display(q);
                 break;

           default:exit(0);
        }
    }

    return 0;
}