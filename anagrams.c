#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main() {
	char A[51], B[51];
	int letter[26] = { 0 }, word[26] = { 0 }, len;
	bool res = true;

	scanf("%s", A);
	scanf("%s", B);

	len = strlen(A);

	for (int i = 0; i < len; i++) {
		word[A[i] - 97]++;
		letter[A[i] - 97]++;
		letter[B[i] - 97]--;
	}

	for (int i = 0; i < 26; i++) {
		if (letter[i])res = false;
	}

	if (res) {
		char output[51];
		int index = 0;
		for (int i = 0; i < 26; i++) {
			while (word[i]--) output[index++] = i + 97;
		}
		output[index] = '\0';
		printf("%s", output);
	}
	else printf("Not anagrams!");

	return 0;
}