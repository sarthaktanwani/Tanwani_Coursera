#include "data.h"
#include "memory.h"

/**
 * @brief function to convert integer to ASCII string
 *
 * Given a integer, pointer to store the integer
 * in ASCII and the base, this function converts
 * the integer to ASCII string in the corresponding base
 *
 * @param data integer to convert
 * @param ptr pointer in memory to store the ASCII
 *            string 
 * @param base base of the integer (for example 2,8,16 etc)
 *
 * @return ptr pointer to the ASCII stering
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    int is_neg = 0;
    uint8_t rem;
    uint8_t length = 0;
    
    if(data == 0)
    {
        my_memcopy((uint8_t *)"0", ptr, 2);
        return 2;
    }
    
    if(data < 0)
    {
        is_neg = 1;
        data *= (-1);
    }
    while(data)
    {
        rem = data % base;
        if(rem > 9)
        {
            *(ptr + length) = rem - 10 + 'a';
        }
        else
        *(ptr + length) = rem + '0';
        length++;
        data /= base;
    }
    
    if(is_neg)
    {
        *(ptr + length) = '-';
        length += 1;
    }
    ptr = my_reverse(ptr, length);
    *(ptr + length) = '\0';
    length += 1;
    return length;
}

/**
 * @brief function to convert ASCII string to integer
 *
 * Given a pointer to the ASCII string, the number 
 * of digits and the base, this function converts  
 * the ASCII represented string into an integer type
 *
 * @param ptr that has the ASCII represented string 
 * @param digits the length of the ASCII string (including
 *               the null terminator)
 * @param base base of the integer (for example 2,8,16 etc)
 *
 * @return int32_t variable that stores the integer type
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t num = 0;
    int is_neg = 0, i = 0;
    digits -= 1;
    if(*ptr == '-')
    {
        is_neg = 1;
        ptr += 1;
        digits -= 1;
    }
    for(;i < digits; i++)
    {
        num *= base;
        if(*(ptr + i) > 'a')
        {
            num += *(ptr + i) - 'a' + 10;
        }
        else
        {
            num += *(ptr + i) - '0';
        }
    }
    if(is_neg)
    num *= -1;
    return num;
}