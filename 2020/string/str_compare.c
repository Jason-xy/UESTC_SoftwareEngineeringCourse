#include <stdio.h>
#include <stdlib.h>
#include "dsstring.h" //请不要删除，否则检查不通过

int Len(const char* s) {
	int ret = 0, i = 0;
	while (s[i++] != '\0') ++ret;
	return ret;
}

int str_compare(const char* ptr1, const char* ptr2) {
	int n1 = Len(ptr1), n2 = Len(ptr2), dx = 'a' - 'A';
	for (int i = 0; i < n1 && i < n2; ++i) {
		int x = ptr1[i], y = ptr2[i];
		if (x != y && x >= 'A' && x <= 'Z' && x + dx == y) x += dx;
		if (x != y && y >= 'A' && y <= 'Z' && y + dx == x) y += dx;
		if (x != y) {
			if (x < y) return -1;
			else return 1;
		}
	}
	if (n1 < n2) return -1;
	else if (n1 > n2) return 1;
	else return 0;
}

//int main() {
//	char s1[] = "15ESJnyk0Px4GlW8p23KMqFJX7aQ7shBdUJiGM4O368G7FWhqA6CJJ8q6Koy4";
//	char s2[] = "15ESJnyk0Px4Glw8P23kmRlk2seH8EuH7BOXiOMT4qtmbtiJlY14O185e63";
//	printf("%d\n", str_compare(s1, s2));
//	return 0;
//}
