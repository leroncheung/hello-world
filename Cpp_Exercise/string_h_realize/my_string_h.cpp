/**
 * @file my_string_h.cpp
 * @author leroncheung
 * @brief functions of file<string.h>: memcpy, memmove, strlen
 * @version 0.1
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

// 未考虑内存重叠场景 
void *MyMemcpy(void *dest, const void *src, size_t n)
{
    if (dest == nullptr || src == nullptr || n <= 0) {
        return nullptr;
    }
    if (dest == src) {
        return dest;
    }
    char *pDest = (char *)dest;
    char *pSrc = (char *)src;
    while (n--) {
        *pDest++ = *pSrc++;
    }
    return dest;
}

// 考虑内存重叠场景
void *MyMemmove(void *dest, const void *src, size_t n)
{
    if (dest == nullptr || src == nullptr || n <= 0)
    {
        return nullptr;
    }
    if (dest == src) {
        return dest;
    }
    char *pDest = static_cast<char *>(dest);
    char *pSrc = static_cast<char *>(const_cast<void *>(src));
    if (pSrc + n > pDest)
    {
        // copy from right to left
        pDest = pDest + n - 1;
        pSrc = pSrc + n - 1;
        while (n--)
        {
            *pDest-- = *pSrc--;
        }
    }
    else
    {
        // copy from left to right
        while (n--)
        {
            *pDest++ = *pSrc++;
        }
    }
    return dest;
}

// 未考虑内存重叠，建议使用strncpy()函数替代
char *MyStrcpy(char *dest, const char *src) {
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    char *pDest = dest;
    char *pSrc = const_cast<char *>(src);
    while (*pSrc != '\0') {
        *pDest++ = *pSrc++;
    }
    *pDest = '\0';
    return dest;
}


size_t MyStrlen(const char *str)
{
    size_t len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

int main()
{
    // char src[] = {'a', 'b', 's'};
    // void *dest = (void *)malloc(sizeof(char) * 5);

    char src[] = "abas";
    char dest[5];
    // auto dst = (char *)MyMemcpy(dest, src, 2);
    // cout << dst << endl;
    cout << MyStrlen(src);

    return 0;
}