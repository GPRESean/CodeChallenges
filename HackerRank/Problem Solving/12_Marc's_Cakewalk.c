#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#if 0 // Hard coding
int find_MaxInt_index(int arr_size, int int_arr[])
{
	int arr_i;
	int maxCal_i;
	int maxVal;

	maxCal_i = 0;
	maxVal = int_arr[maxCal_i];
	for (arr_i = 1; arr_i < arr_size; arr_i++)
	{
		if (maxVal < int_arr[arr_i])
		{
			maxCal_i = arr_i;
			maxVal = int_arr[arr_i];
		}
	}

	return maxCal_i;
}

long int marcsCakewalk(int calorie_size, int calories[])
{
	int nCakes_i;
	int maxCal_i;
	int maxVal;
	long int totalCal;

	totalCal = 0;
	for (nCakes_i = 0; nCakes_i < calorie_size; nCakes_i++)
	{
		maxCal_i = find_MaxInt_index(calorie_size, calories);
		maxVal = calories[maxCal_i];

        // If cast type below, then fails on case 2 and 3.
		totalCal += pow(2, nCakes_i) * maxVal;

		//calories[maxCal_i] = -1;
		calories[maxCal_i] = INT_MIN;
	}

	return totalCal;
}
#endif

#if 1 // With standard sort library
int compDescending(const void *x, const void *y)
{
	return (*(int *)y - *(int*)x);
}

long int marcsCakewalk(int calorie_size, int calories[])
{
	int nCakes_i;
	long int totalCal;

	qsort(calories, calorie_size, sizeof(int), compDescending);

	totalCal = 0;
	for (nCakes_i = 0; nCakes_i < calorie_size; nCakes_i++)
	{
        // If cast type below, then fails on case 2 and 3.
		totalCal += pow(2, nCakes_i) * calories[nCakes_i];
	}

	return totalCal;
}
#endif

int main()
{
	int calorie_i = 0;
	int n = 0;
	int *calorie = NULL;
	long int result = 0;

	scanf("%i", &n);

	calorie = malloc(sizeof(int) * n);

	for (calorie_i = 0; calorie_i < n; calorie_i++)
	{
		scanf("%i", &calorie[calorie_i]);
	}

	result = marcsCakewalk(n, calorie);

	printf("%ld\n", result);

	free(calorie);

	return 0;
}
