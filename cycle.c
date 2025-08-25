#include <stdio.h>
#define N 100
int cqueue[N];
int r = -1;
int f = -1;
void cqinqueue(int y)
{
	if (r ==N)
    {
        r= 0;
    }
    else
    {
        r++;
    }
    if (r==f)
    {
        printf("overflow");
        return;
    }
    else
    {
        cqueue[r]=y;
        if (f==-1)
        {
            f=0;
        }
        return;
    }
    
    
    
    
}

void display()
{
	if (f == -1 || f == r)
	{
		printf("your queue is empty");
		return;
	}
	else
	{
		for (int i = f; i <= r; i++)
		{
			printf("%d \n", cqueue[i]);
		}
	}
}
int dequeue()
{  int y;
    if (f == -1 || f == r)
    {
        printf("underflow");
        return -1;
    }
    else
    {
        y = cqueue[f];
        if (f==r)
        {
            f= -1;
            r= -1;
        }
        else if (f==N)
        {
            f=0;
        }
        else
        {
            f++;
        }
        return y;
        
    }
    
}

int main()
{
	
	int y[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
	{
		cqinqueue(y[i]);
	}	


    display();


	// for (int i = f; i <= r; i++)
	// {
	// 	printf("dequeued element is %d\n", dequeue());
	// }
	
	return 0;
}