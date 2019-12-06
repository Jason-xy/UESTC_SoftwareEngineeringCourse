#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

void destory_list(GoodsList** L)
{
    for (; *L; *L = (*L)->next)
        free(*L);
}
