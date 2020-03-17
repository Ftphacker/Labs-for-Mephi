#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int prt(char *str){
	printf("%s", str);
	return 0;
}


int work(char *str){
	int n = 0, k = 0, i = 0;
	char *str2;// Без повторяющихся элементов
	char *str3;// Повторяющиеся элементы
	str2 = (char *) malloc (strlen(str) * sizeof(char));
	str3 = (char *) malloc (strlen(str) * sizeof(char));
	while (i < (strlen(str) - 1)){
		if (str[i] == str[i+1]){
			if (str[i] != ' '){
				while ((str[i] == str[i+1]) && (i < (strlen(str) - 1)) && (str[i] != ' ')) {
					str3[n] = str[i];
					n++;
					i++;
				}
				str3[n] = str[i];
				if (i < strlen(str) - 1){
					str3[n+1] = ' ';
					n += 2;
				}
			}
			i++;
		}
		else{
			if (str[i] != ' '){
				while ((str[i] != str[i+1]) && (i < (strlen(str) - 1)) && (str[i] != ' ')){
					str2[k] = str[i];
					k++;
					i++;
				}
				if ((i == (strlen(str) - 1)) && (str[i] != str[i-1])){
					str2[k] = str[i];
				}
				if ((i < strlen(str) - 1)){				
					str2[k] = ' ';
					k += 1;
				}				
			}
			else{i++;}
		}
	}
	printf("Без повторов - ");
	printf("%s", str2);
	printf("\n");
	printf("Повторы - ");
	printf("%s", str3);
	return 0;
}


	
int input(){
	int k = 1, n = 1;
	char str[101];
	char *str2;
	str2 = (char *) malloc (n*sizeof(char));
	while (k != -1){
		do {
			k = scanf("%100[^\n]", &str);
			//printf("k - %d\n", k);
			//printf("strlen - %d\n", strlen(str));
			if (k == 1) {				
				n += strlen(str);		
				str2 = (char *) realloc (str2, (n+1)*sizeof(char));
				strcat(str2,str);
			}
		}
		while (k > 0);
		if (strlen(str2) < 2){
			printf("%s", str2);
		}
		else{
			work(str2);
			
		}
		free (str2);	
		printf("\n");
		scanf("%*\n");
		str2 = (char *) malloc (1*sizeof(char));
		printf("%s", str2);
	}
}

int main() {
	input(); 
	return 0;
}
