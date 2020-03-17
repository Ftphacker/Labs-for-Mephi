#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int first(int k) {
	while(k > 9) {
		k = k/10;
	}
	return k;
}

int delete(int k, int n) {
	int t = 0, sum = 0;
	while (k > 0) {	
		if ((k%10) != n) {
			sum = sum + (k % 10) * pow(10, t);
			t++;	
		} 
		k = k / 10;
	}
	return sum;
}

int size(int k) {
	int i=1;
	while (k > 0) {
		k = k/10;
		i++;
	}
	return i;
}
	
int main() {
	int n,k,i=0,pobg;
	int *mas;
	int *mas1;
	scanf("%d", &n);
	mas = (int *) malloc(n * sizeof(int));
	mas1 = (int *) malloc(n * sizeof(int));
	//printf("d1\n");
	
	while (i < n) {
		//printf("d2");
		scanf("%d", &k);
		//printf("%d\n", first(k));
		//printf("%d\n", delete(k,first(k)));
		mas[i] = delete(k,first(k));
		mas1[i] = k;
		i++;		
	}
	for (int i = 0; i < n; i++) {
		printf(" %d" , mas1[i]);
	}
	printf("\n");
	i = 0;
	while (i < n) {
		if (mas[i] < mas[i - 1]) {
			pobg = mas[i];
			mas[i] = mas[i - 1];
			mas[i-1] = pobg;
			i--;
		}
		else i++; 
			
	}
	for (int i = 0; i < n; i++) {
		printf(" %d" , mas[i]);
	}
	free(mas);
	free(mas1);
	return 0;
}	
