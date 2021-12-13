/**
 * @file my_stdlib_h.cpp
 * @author leroncheung
 * @brief 
 * @version 0.1
 * @date 2021-12-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <string>

class Solution
{
public:
    int myAtoi(string s)
    {
        int res = 0, i = 0, flag = 1;
        for (; s[i] == ' '; i++)
        {
        }
        if (s[i] == '+' || s[i] == '-')
        {
            flag = 44 - s[i]; // '+'为43，'-'为45
            i++;
        }
        for (; i < s.size() && isdigit(s[i]); i++)
        {
            int r = s[i] - '0';
            if (res > INT32_MAX / 10 || ((res == INT32_MAX / 10) && r > 7))
            {
                return flag > 0 ? INT32_MAX : INT32_MIN; // 判断溢出
            }
            res = res * 10 + r;
        }
        return flag * res;
    }
};

int main() {
    string str("  -123bd");
    Solution sol;
    std::cout << sol.myAtoi(str) << std::endl;
    return 0;
}