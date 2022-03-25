#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" // 请不要删除，否则检查不通过

Stack S;

void getnum(int* x, int* i, char* str) {
	int ret = 0;
	while (str[*i] >= '0' && str[*i] <= '9') {
		ret = ret * 10 + (str[*i] - '0');
		++(*i);
	}
	*x = ret;
}

int compute_reverse_polish_notation(char* str) {
	int n = strlen(str), i, x = 0;
	init_stack(&S);
	for (i = 0; i < n; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			getnum(&x, &i, str);
			push(&S, x);
		}
		else {
			pop(&S, &x);
			int y = 0, z = 0;
			pop(&S, &y);
			if (str[i] == '+') z = y + x;
			if (str[i] == '-') z = y - x;
			if (str[i] == '*') z = y * x;
			if (str[i] == '/') z = y / x;
			if (str[i] == '%') z = y % x;
			push(&S, z);
			++i;
		}
	}
	pop(&S, &x);
	return x;
}