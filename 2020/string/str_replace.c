#include "dsstring.h"
#include <stdio.h>
#include <stdlib.h>

int Len(const char* s) {
	int ret = 0, i = 0;
	while (s[i++] != '\0') ++ret;
	return ret;
}

//返回成功替换的字串个数
int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr) {
	int n = Len(in), old_len = Len(oldstr), new_len = Len(newstr), ret = 0, i, j, k;
	for (i = 0, k = -1; i < n && k + 1 < outlen - 1;) {
		int ok = 0;
		if (i + old_len - 1 < n && k + (n - i - old_len) + new_len < outlen - 1) {
			int flag = 1;
			for (j = 0; j < old_len; ++j) {
				if (in[i + j] != oldstr[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				for (j = 0; j < new_len; ++j) out[++k] = newstr[j];
				ok = 1;
			}
		}
		if (ok) {
			i += old_len;
			++ret;
		}
		else {
			out[++k] = in[i++];
		}
	}
	out[++k] = '\0';
	return ret;
}