#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
int main() {
	int n;
	char pwd[51], res[6] = "true";
	bool check[5];

	scanf("%s", pwd);
	n = strlen(pwd);

	if (n >= 8) check[0] = true;
	for (int i = 0; i < n; i++) {
		if (islower(pwd[i]))check[1] = true;
		if (isupper(pwd[i]))check[2] = true;
		if (isdigit(pwd[i]))check[3] = true;
		if (ispunct(pwd[i]))check[4] = true;
	}

	for (int i = 0; i < 5; i++) {
		if (!check[i]) strncpy(res, "false", 5);
	}
	printf("%s", res);

	return 0;
}