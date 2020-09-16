#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100


/*
  Quick    Bubble sort
*/

/*
  Bubble sort
*/
void bubble_sort(int *nums, int n)
{
  /* perform the bubble sort */
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			/* if a > b, swap the values */
			if( nums[i] > nums[j] )
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}


int demo_bubble_sort()
{
	int list[SIZE];
	int a;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* build and display the random values */
	printf("%d random values, unsorted:\n",SIZE);
	for(a=0;a<SIZE;a++)
	{
		list[a] = rand() % 100 + 1;	/* values from 1 to 100 */
		printf("%4d",list[a]);
	}
	putchar('\n');

	bubble_sort(list, SIZE);

	/* display the sorted list */
	printf("%d random values, sorted:\n",SIZE);
	for(a=0;a<SIZE;a++)
		printf("%4d",list[a]);
	putchar('\n');

	return(0);
}

int compare(const void *a, const void *b)
{
	return( *(int *)a - *(int *)b);
}

int demo_quick_sort()
{
	int list[SIZE];
	int a;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* build and display the random values */
	printf("%d random values, unsorted:\n",SIZE);
	for(a=0;a<SIZE;a++)
	{
		list[a] = rand() % 100 + 1;	/* values from 1 to 100 */
		printf("%4d",list[a]);
	}
	putchar('\n');

	/* perform the quick sort */
	qsort(list, SIZE, sizeof(int), compare);

	/* display the sorted list */
	printf("%d random values, sorted:\n",SIZE);
	for(a=0;a<SIZE;a++)
		printf("%4d",list[a]);
	putchar('\n');

	return(0);
}


int main(){
  demo_bubble_sort();
  demo_quick_sort();

  return 0;
}



