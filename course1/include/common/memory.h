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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

 /**
 * @brief Moves a value from one address to another 
 *
 * Given an source address, destination address and the 
 * length of bytes to move, it moves the data values
 * handling any overlapping issues that may occur
 *
 * @param src source memory address
 * @param dst destination memory address
 * @param length length of bytes to move
 *
 * @return pointer to the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a value from one memory address to another 
 *
 * Given an source address, destination address and the 
 * length of bytes to copy, it copies the data values
 * overlapping of addresses causes data corruption
 *
 * @param src source memory address
 * @param dst destination memory address
 * @param length length of bytes to move
 *
 * @return pointer to the destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a value of a pointer in memory
 *
 * Given a pointer to a char data set, this will set a provided
 * length of indexes into that data set to the value provided.
 *
 * @param src source memory address
 * @param length length of bytes to set
 * @param value value to write the the locaiton
 *
 * @return pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Clears elements in memory
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param src source memory address
 * @param length length of bytes to clear
 *
 * @return pointer to source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in memory
 *
 * Given a pointer to a char data set and the length, this
 * would reverse the order of bytes in that memory address 
 * length
 *
 * @param src Pointer to source
 * @param length the length to be reversed
 *
 * @return pointer to source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);


/**
 * @brief Allocates space for words in dynamic memory
 *
 * Given a length, allocates that number of words in 
 * memory using the malloc function.
 *
 * @param length the number of words to be reserved
 *
 * @return pointer to source
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees space for words in dynamic memory
 *
 * Given a source pointer, frees that in 
 * memory using the free function.
 *
 * @param src pointer to source
 *
 * @return void.
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
