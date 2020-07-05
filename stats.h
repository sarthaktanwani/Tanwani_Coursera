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
 * @file stats.h 
 * @brief This is the header file for basic statistics functions like mean,
 * median, mode
 *
 * <Add Extended Description Here>
 *
 * @author Sarthak Tanwani
 * @date 5th July 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Function to print the contents of an array
 *
 * This function inputs the array and its size and
 * iterates through a loop to print all the elements
 * of the array
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return nothing to return
 */
void print_array(unsigned char* arr, unsigned int len);

/**
 * @brief Function to sort the contents of an array
 *
 * This function inputs the array and its size and
 * iterates through a loop to sort the elements
 * of the array
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return nothing to return
 */
void sort_array(unsigned char* arr, unsigned int len);

/**
 * @brief Function to find the mean
 *
 * This function takes an array of data points and finds
 * out the mean
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return mean of type unsigned int
 */
unsigned int find_mean(unsigned char* arr, unsigned int len);

/**
 * @brief Function to find the median
 *
 * This function takes an array of data points and finds
 * out the median
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return median of unsigned type
 */
unsigned int find_median(unsigned char* arr, unsigned int len);

/**
 * @brief Function to find the maximum value
 *
 * This function takes an array of data points and finds
 * out the the maximum value
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return maximum value of unsigned type
 */
unsigned int find_maximum(unsigned char* arr, unsigned int len);

/**
 * @brief Function to find the minimum value
 *
 * This function takes an array of data points and finds
 * out the the minimum value
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return minimum value of unsigned type
 */
unsigned int find_minimum(unsigned char* arr, unsigned int len);

/**
 * @brief Function to print statistical data elements for
 * 		an array of data points
 *
 * This function inputs the array and its size and prints
 * out the mean, median, maximum and minimum value of the
 * dataset.
 *
 * @param unsigned char *arr The array variable
 * 				need to be printed
 * @param len length of the array
 *
 * @return nothing to return
 */
void print_statistics(unsigned char* arr, unsigned int len);
#endif /* __STATS_H__ */
