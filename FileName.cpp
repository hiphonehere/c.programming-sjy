#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100

int main() {
	int number[size];
	int total = 0;
	int max, min;
	double avg=0.0;
	srand(time(NULL));
	for (int i = 0;i < size;i++) {
		number[i] = (rand() % 100) + 1;
	}

	for (int i = 0;i < size;i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	for (int i = 0;i < size;i++) {
		total += number[i];
	}
	avg = (double)total / size;
	max = number[0];
	min = number[0];
	for (int i = 1;i < size;i++) {
		if (max < number[i]) max = number[i];
		if (min > number[i]) min = number[i];
	}
	printf("agv=%lf max=%d min=%d",avg,max,min);
}