
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

typedef struct {
	int data;
	char str[MAX];
} Test;


int main() {
	Test* a = (Test*)malloc(sizeof(Test));

	if (a) {
		a->data = 100;
		strcpy_s(a->str, "just testing");

		printf("����ü ������ �ּ� : %p\n", &a);
		printf("Data �ּ� : %p, �� : %d\n", &a->data, a->data);
		printf("String �ּ� : %p, �� : %s\n", a->str, a->str);

		free(a);
	}
}
