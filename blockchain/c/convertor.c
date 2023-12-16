#include "../h/convertor.h"

int my_atoi(char* str)
{
    int result = 0;
    int i = 0;
    int flag = 0;
    if (str[0] == '-')
    {
        i = 1;
        flag = 1;
    }
    while (str[i])
    {
        if (!(str[i] >= 48 && str[i] <= 57))
        {
            break;
        }
        result *= 10;
        result += str[i++] - 48;
    }
    if (flag == 1)
    {
        result *= -1;
    }
    return result;
}

char* my_rev(char* p1)
{
    int len = my_strlen(p1);
    char c;
    for (int i = 0; i < len / 2; i++)
    {
        c = p1[i];
        p1[i] = p1[len - i - 1];
        p1[len - i - 1] = c;
    }
    return p1;
}

char* my_itoa(int num, char* str)
{
    int flag = 0;
    int i = 0;
    if (num < 0)
    {
        num *= -1;
        flag = 1;
    }
    while (num > 0)
    {
        str[i++] = (num % 10) + 48;
        num /= 10;
    }
    if (flag == 1)
    {
        str[i] = '-';
    }
    return my_rev(str);
}

int my_isdigit(char c)
{
    if (c >= 48 && c <= 57)
    {
        return 1;
    }
    return 0;
}

int number_check(char* str)
{
    int i = 0;
    if (str[0] == '-')
    {
        i = 1;
    }
    while (str[i])
    {
        if (my_isdigit(str[i]) == 0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}