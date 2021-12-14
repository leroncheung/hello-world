/**
 * @file my_string_h.cpp
 * @author leroncheung
 * @brief functions of file<string.h>: strcmp, memcpy, memmove, strlen, strcpy, strncpy
 * @version 0.1
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

// reference by linux core @Linus Torvalds
int MyStrCmp(const char *str1, const char* str2) {
    unsigned char c1, c2;
    while (true) {
        c1 = *str1++;
        c2 = *str2++;
        if (c1 != c2) {
            return (c1 < c2 )? -1 : 1;
        }
        if (!c1) {
            break;
        }
    }
    return 0;
}

// 未考虑内存重叠场景
void *MyMemcpy(void *dest, const void *src, size_t n)
{
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    char *pDest = static_cast<char *>(dest);
    char *pSrc = static_cast<char *>(const_cast<void *>(src));
    while (n--) {
        *pDest++ = *pSrc++;
    }
    return dest;
}

// 考虑内存重叠场景
void *MyMemmove(void *dest, const void *src, size_t n)
{
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    char *pDest = static_cast<char *>(dest);
    char *pSrc = static_cast<char *>(const_cast<void *>(src));
    if (pSrc < pDest && pSrc + n > pDest) {
        pDest = pDest + n - 1;
        pSrc = pSrc + n - 1;
        while (n--) {
            *pDest-- = *pSrc--;     // copy from right to left
        }
    } else {
        while (n--) {
            *pDest++ = *pSrc++;     // copy from left to right
        }
    }
    return dest;
}

// 未考虑内存重叠
char *MyStrcpy(char *dest, const char *src) {
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    char *ret = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ret;
}

// 把src指向的字符串复制到dest，最多复制n个字符
// 当src的长度小于n时，dest的剩余部分将用空字节填充
char *MyStrncpy(char *dest, const char* src, size_t n) {
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    char *ret = dest;
    while (n-- && (*dest++ = *src) != '\0') {
    }
    return ret;
}

// 返回字符串数组中字符串的长度
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
    char str1[] = "abs";
    char str2[] = "abc";
    std::cout << MyStrCmp(str1, str2) << std::endl;
    std::cout << MyStrlen(str1) << std::endl;

    char str3[100];
    MyMemcpy(str3, str1, 2);
    std::cout << str3 << std::endl;

    MyMemmove(str3, str2, 2);
    std::cout << str3 << std::endl;

    MyStrcpy(str3, str1);
    std::cout << str3 << std::endl;

    MyStrncpy(str3, str1, 3);
    std::cout << str3 << std::endl;

    // char src[] = {'a', 'b', 's'};
    // void *dest = (void *)malloc(sizeof(char) * 5);

    return 0;
}