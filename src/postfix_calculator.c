#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define Debug 0
#define InputSize 100
typedef struct Stack {
	int top;
	int element[InputSize];
}Stack;

void push(Stack *s, int n) {
	s->element[s->top++] = n;
}

int pop(Stack *s) {
	return s->element[--s->top];
}

int main() {
	int res=0, size = 0;
	char arr[InputSize];
	Stack s ;
	FILE* fp = fopen("testdata_postorder-calculator/0004.in", "r");

	fscanf(fp, "%d\n", &size);
	for (int i = 0; i < size; i++) {
		fscanf(fp, "%c", &arr[i]);
	}
	fclose(fp);

	#if Debug
		for (int i = 0; i < size; i++) {
			printf("%c", arr[i]);
		}
		printf("\n");
	#endif // Debug

	s.top = 0;

	for (int i = 0; i < size; i++) {
		#if Debug
				printf("%d:", i);
				for (int j = 0; j < s.top; j++) {
					printf("%d", s.element[j]);
				}
				printf("\n");
		#endif // Debug

		if (isdigit(arr[i]))push(&s, arr[i]-'0');
		else {
			int b = pop(&s), a = pop(&s);
			#if Debug
						printf("%d %c %d\n", a, arr[i], b);
			#endif // Debug
			switch (arr[i]) {
				case '+':
					push(&s, a + b);
					break;
				case '-':
					push(&s, a - b);
					break;
				case '*':
					push(&s, a * b);
					break;
				case '/':
					push(&s, a / b);
					break;
			}
		}
	}
	
	printf("%d\n", pop(&s));
}