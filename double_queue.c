#include <stdio.h>
#define N 100
int cqueue[N];
int r = -1;
int f = -1;
void dqinqueueFront(int y)
{
	if ( f == 0)
    {
        printf("overflow");
        return;
    }   
    
    else if (f == -1)
    {
        f=0;
        r=0;
        cqueue[f]=y;
    }
    else
    {
        f--;
        cqueue[f]=y;
    }
}

void dqdequeueRare(){
    if ( r == -1)
    {
        printf("underflow");
        return;
    }   
    
    else if (f == r)
    {
        f=-1;
        r=-1;
    }
    else
    {
        r--;
    }
}

void dqinqueueRare(int y){
    if ( r == N-1)
    {
        printf("overflow");
        return;
    }   
    
    else if (f == -1)
    {
        f=0;
        r=0;
        cqueue[r]=y;
    }
    else
    {
        r++;
        cqueue[r]=y;
    }
}

void dqdequeueFront(){
    if ( r == -1)
    {
        printf("underflow");
        return;
    }   
    
    else if (f == r)
    {
        f=-1;
        r=-1;
    }
    else
    {
        f++;
    }
}
void display()
{
    if (r == -1)
    {
        printf("queue is empty");
        return;
    }
    for (int i = f; i <= r; i++)
    {
        printf("%d ", cqueue[i]);
    }
    printf("\n");
}
int main()
{
	
	int y[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
	{
		dqinqueueRare(y[i]);
	}	


    display();


	// for (int i = f; i <= r; i++)
	// {
	// 	printf("dequeued element is %d\n", dequeue());
	// }
	
	return 0;
}