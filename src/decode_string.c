#include <stdio.h>
#include <string.h>
char* decoder(char str[]) {
	char a[5] = { 'a', 'b', 'c', 'd', '\0' };
	return a;
}

int main() {
	char str[30];
	scanf("%s", str);
	char* a = decode(str);
	return 0;
}