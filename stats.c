/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("Printing the test array\n\n");
  printf("Index\tValue\n");
  print_array(test, SIZE);

  printf("Printng the test array after sorting!\n\n");
  printf("Index\tValue\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);


  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */

void print_array(unsigned char* arr, unsigned int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d\t", i);
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

void sort_array(unsigned char* arr, unsigned int len)
{
	int i,j, temp;
	for(i = 0; i < (len-1); i++)
	{
		for(j = 0; j < (len-i-1); j++)
		{
			if(arr[j] < arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

unsigned int find_mean(unsigned char* arr, unsigned int len)
{
	int sum = 0, mean, i;
	for(i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	mean = sum/len;
	return mean;
}

unsigned int find_median(unsigned char* arr, unsigned int len)
{
	int median;
	sort_array(arr, len);

	if(len%2 == 0)
	{
		median = (arr[(len/2)-1] + arr[len/2])/2;
	}
	else
	{
		median = arr[((len+1)/2)-1];
	}

	return median;
}

unsigned int find_maximum(unsigned char* arr, unsigned int len)
{
	sort_array(arr, len);
	
	return arr[0];
}

unsigned int find_minimum(unsigned char* arr, unsigned int len)
{
	sort_array(arr, len);
	
	return arr[len-1];
}

void print_statistics(unsigned char* arr, unsigned int len)
{
	int min, max, mean, median;
	min = find_minimum(arr, len);
	max = find_maximum(arr, len);
	mean = find_mean(arr, len);
	median = find_median(arr, len);
	printf("Important information about the dataset is as follows: \n");
	printf("\nMinimum value in the dataset: %d\n", min);
	printf("Maximum value in the dataset: %d\n", max);
	printf("Mean of the dataset: %d\n", mean);
	printf("Median of the dataset: %d\n", median);
}
