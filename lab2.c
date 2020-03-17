#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int print(int **mas, int *mas1, int n) {
	int i,j;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < mas1[i]; j++) {
			mas[i][j] = rand()%100;
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
int printq(int **mas, int *mas1, int n) {
	int i,j;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < mas1[i]; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}

int delete(int **mas, int *mas1, int n) {
	int i;
	for (int i = 0; i < n; i++) {
		free(mas[i]);	
	}
	free(mas);
	free(mas1);
	return 0;
}

int memory(int n, int *mas1, int **mas) {
	int k,i;
	for (int i = 0; i < n; i++) {
		printf("Введите кол-во чисел в %d строке : ", i+1);
		scanf("%d", &k);//столбики
		mas1[i] = k;
		mas[i] = (int *)malloc(k*sizeof(int));	
	}
	return 0;	
}

int sort(int num, int **mas, int k) {
	int i = 1, d1, j;	
	/*while (i <= k) {
		if (mas[num][i] < mas[num][i-1]) {
			d1 = mas[num][i];
			mas[num][i] = mas[num][i-1];
			mas[num][i-1] = d1;
			i--;
		}
		else i++;
	}*/
	for (int i = 1; i < k; i++) {
		for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--) {
			swap(mas[j - 1],mas[j]);
		}
	}
	return 0;
}

int search(int n, int **mas, int *mas1) {
	int i,max = 0,sum = 0,num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < mas1[i]; j++) {
			sum = sum + mas[i][j];
		}
		if (sum > max) {max = sum; num = i;}
		sum = 0;
	}
	sort(num, mas, mas1[num] - 1);
	return 0;
}

int main() {
	int n,k,max;
	int **mas;
	int *mas1;
	scanf("%d", &n);//строки
	mas = (int **) malloc (n * sizeof(int *));
	mas1 = (int *) malloc (n * sizeof(int));
/*for (int i = 0 ;i < n ;i++){
	printf("Введите кол-во чисел в %d строке : ", i+1);
	scanf("%d", &k);//столбики
	mas1[i] = k;
	mas[i] = (int *)malloc(k*sizeof(int));	
}*/	
	memory(n, mas1, mas);
	print(mas, mas1, n);
	max = search(n, mas, mas1);
	printf("\n");
	printq(mas, mas1, n);
	delete(mas, mas1, n);
	return 0;
}
