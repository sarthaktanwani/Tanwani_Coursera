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


#include "platform.h"
#include "stats.h"

void print_array(unsigned char* arr, unsigned int len)
{
	#ifdef VERBOSE
	int i;
	for(i = 0; i < len; i++)
	{
		PRINTF("%d\t", i);
		PRINTF("%d\n", arr[i]);
	}
	PRINTF("\n");
	#endif
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
	PRINTF("Important information about the dataset is as follows: \n");
	PRINTF("\nMinimum value in the dataset: %d\n", min);
	PRINTF("Maximum value in the dataset: %d\n", max);
	PRINTF("Mean of the dataset: %d\n", mean);
	PRINTF("Median of the dataset: %d\n", median);
}
