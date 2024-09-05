#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100
int main(){
	int number[100];
	int temp;
	int most;
	srand(time(NULL));

	for(int i = 0;i < size;i++) {
		number[i] = (rand() % 10000) + 1;
	}
	for (int i = 0;i < size - 1;i++) {
		most = i;
		for (int j = i + 1;j < size;j++) {
			if (number[most] < number[j]) most = j;
		}
		temp = number[i];
		number[i] = number[most];
		number[most] = temp;
	}
	for (int i = 0;i < size;i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	return 0;
}