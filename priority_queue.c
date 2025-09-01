#include <stdio.h>
#define N 100
int pqueue[N];
int r = -1;
int f = -1;
void pinqueue(int y)
{
	if (r >= N)
	{
		printf("queue overflow");
		return;
	}
	else
	{
		r++;
		pqueue[r] = y;
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
			printf("%d \n", pqueue[i]);
		}
	}
}
int pdequeueMin()
{
    if (f == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int minIndex = f;
    for (int i = f; i <= r; i++) {
        if (pqueue[i] < pqueue[minIndex]) {
            minIndex = i;
        }
    }
    int y = pqueue[minIndex];
    for (int i = minIndex; i < r; i++) {
        pqueue[i] = pqueue[i + 1];
    }
    r--;
    if (r < f) {
        f = -1;
        r = -1;
    }
    return y;
}
int pdequeueMax(){
    if (f == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int maxIndex = f;
    for (int i = f; i <= r ; i ++ ){
        if(pqueue[i]>pqueue[maxIndex]){
            maxIndex = i;
        }
    }
    int y = pqueue[maxIndex];
    for (int i = maxIndex; i < r; i++) {
        pqueue[i] = pqueue[i + 1];      
    }
    r--;
    if (r < f) {
        f = -1;
        r = -1; 
    }
    return y;
}


int main()
{
	
	int y[] = {5,95,58,26,18,4};
	for (int i = 0; i < 5; i++)
	{
		pinqueue(y[i]);
	}	
	for (int i = -1; i < r; i++)
	{
		printf("dequeued element is %d\n", pdequeueMax());
	}
	
	return 0;
}