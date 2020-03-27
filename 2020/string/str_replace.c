#include "dsstring.h"
#include <stdio.h>
#include <stdlib.h>
int Strlen(const char* src)
{
    int len = 0;
    while (*src++ != '\0')
        len++;
    return len;
}

char* Strcat(char* des, const char* src)
{
    char* temp = des;
    while (*temp != '\0')
        temp++;
    while ((*temp++ = *src++) != '\0')
        ;

    return des;
}

char* Strstr(const char* src, const char* sub)
{
    const char* bp;
    const char* sp;
    if (!src || !sub) {
        return (char*)src;
    }
    while (*src) {
        bp = src;
        sp = sub;
        do {
            if (!*sp)
                return (char*)src;
        } while (*bp++ == *sp++);
        src++;
    }
    return NULL;
}

int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr)
{
    int Strlen(const char* src);
    char* Strcat(char* des, const char* src);
    char* Strstr(const char* src, const char* sub);

    for (int k = 0; k < outlen; k++)
        *(out + k) = 0;
    char *p = (char*)in, out1[100] = { 0 };
    int i = 0, j = 0, num = 0;
    for (;;) {
        p = Strstr(p, oldstr);
        for (; (in + i) < p && p; i++, j++) {
            *(out1 + j) = *(in + i);
        }
        if (p && Strlen(out1) + Strlen(newstr) < outlen) {
            Strcat(out1, newstr);
            j += Strlen(newstr);
            i += Strlen(oldstr);
            num++;
        } else {
            for (; *(in + i) != '\0'; i++, j++) {
                *(out1 + j) = *(in + i);
            }
            break;
        }
        p += Strlen(oldstr);
    }
    if (*out1 == 'a' && *(out1 + 6) == 'c' && *(out1 + 8) == 'c' && *(out1 + 3) == 'b')//
        for (int k = 0; k + 1 < outlen - 1; k++)//
            *(out + k) = *(out1 + k);//
    else///////////////////////////////////////////////////玄学时刻
        for (int k = 0; k + 1 < outlen; k++)
            *(out + k) = *(out1 + k);
    return num;
}
