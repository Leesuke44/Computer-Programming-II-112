#include <stdio.h>
#include <string.h>

#define SIZE 101

int main() {
	int column[SIZE], top = 0, n=0, ans=0;
	char S[SIZE];

	scanf("%s", S);
	n = strlen(S);

	for (int i = 0; i < n; i++) {
		if (top >= 2 && column[top - 1] == S[i] && column[top - 2] == S[i]) {
			top-=2;
			ans++;
		}
		else column[top++] = S[i];
	}
	printf("%d", ans);
	printf("\n");
	for (int i = 0; i < top; i++) {
		printf("%c", column[i]);
	}
}