#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define MAX_SIZE 100000
int isPalindrome(int n);
int isPalinInBase2(int n);

int main() {

	int i;
	int n = 0, sum = 0, n1 = 0;
	int *list = malloc(MAX_SIZE);

	for (i = 1; i < 1000000; i+=2) {
		if (isPalindrome(i)) {
			list[n++] = i;
		}
	}

	printf("Number of odd palindromes less than one million in base 10: %d\n",n);
	printf("Palindromes in both base 2 and base 10:\n");
	for (i = 0; i < n; i++) {
		if (isPalinInBase2(list[i])) {
			printf("%d\n",list[i]);
			n1++;
			sum += list[i];
		}		
	}
	printf("Number: %d, Sum: %d\n",n1,sum);

	return 0;
}

int isPalinInBase2(int n) {
	
	int i, j;
	int number = n;
	int *digits = malloc(MAX);
	int numDigits = 0;

	while (number > 0) {
		digits[numDigits++] = number%2;
		number /= 2;
	}

	for (i = 0, j = numDigits-1; i <= j; i++,j--) {
		if (digits[i] != digits[j]) return 0;
	}

	return 1;
}

int isPalindrome(int n) {
	
	int i,j;
	int number = n;
	int *digits = malloc(MAX);
	int numDigits = 0;

	while (number > 0) {
		
		digits[numDigits++] = number%10;
		number /= 10;
	}

	for (i = 0, j = numDigits-1; i <= j; i++,j--) {
		if (digits[i] != digits[j]) return 0;
	}

	return 1;
}
