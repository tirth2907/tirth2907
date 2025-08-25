#include <stdio.h>
#define N 100
int queue[N];
int r = -1;
int f = -1;
void inqueue(int y)
{
	if (r >= N)
	{
		printf("queue overflow");
		return;
	}
	else
	{
		r++;
		queue[r] = y;
		if (f == -1)
		{
			f = 0;
			return;
		}
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
		for (int i = 0; i <= r; i++)
		{
			printf("%d \n", queue[i]);
		}
	}
}
int dequeue()
{
	int y =0;
	if (f == -1 || f > r)
	{
		printf("your queue is empty");
		return -1;
	}
	else
	{
		y = queue[f];
		if (f == r)
		{
			f = -1;
			r = -1;
			
		}
		else
		{
			f++;
		}
	}
	return y;
}

int main()
{
	
	int y[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
	{
		inqueue(y[i]);
	}	
	for (int i = -1; i < r; i++)
	{
		printf("dequeued element is %d\n", dequeue());
	}
	
	return 0;
}