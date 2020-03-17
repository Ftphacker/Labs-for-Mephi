#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int minstr(char *str2) {
	int word = 0, n = 0, ch = 0, space = 0,i = 0,ost_spase = 0,miss = 0;
	char str3[81] = {'\0'};
	printf(str3);
	for (int n = 0; n < strlen(str2); n++){
		if (str2[n] != ' '){
			ch++;	
		}
		if ((str2[n] != ' ') && (str2[n-1] == ' ')){
			word++;
		}
	}
	while (n < strlen(str2)){
		if (str2[n] == ' '){
			while (str2[n] == ' '){n++;}
			miss++;
		}
		n++;
	}
	word++;
	//printf("%d\n", ch);
	//printf("%d\n", word);
	ost_spase = (80 - ch) % miss;
	space = (80 - ch)/miss;
	//printf("%d\n", space);
	//printf("%d\n", ost_spase);
	n = 0;
	while (strlen(str3) <= 80){
		while (str2[n] != ' '){
			str3[i] = str2[n];
			i++;n++;
		}	
		//printf("%d\n", i+space);
		if (i + space <= 80){
			for (int y = i; y < i + space; y++){
				str3[y] = ' ';
				//printf("%d\n", y);
			}
		}
		else{ break; }
		if (i + space <= 80){		
			i = i + space;
		}
		//printf("d1\n");
		if (ost_spase > 0){ str3[i] = ' '; ost_spase--; i++;}
		//printf("%d\n", strlen(str2));
		
		if ((i < 80) && (n < strlen(str2))){		
			while (str2[n] == ' '){
				n++;printf("%d\n", n);	
			}
		}
	}
	printf(str3);
	return 0;
}


int maxstr(char *str2){
	int n = 0,k = 80, d1,d2,i=0;
	char *str3;
	char str4[80];
	while (n < strlen(str2)){
		 if (strlen(str2) - n > 80){
			str3 = (char *) malloc (81 * sizeof(char));
			for (int i = 0; i < 81; i++){
				str3[i] = str2[n];
				n++;
			}
			printf("79 - %c\n", str3[79]);
			printf("80 - %c\n", str3[80]);
			if ((str3[79] != ' ') && (str3[80] != ' ')){
				while (str3[k] != ' '){
					k--;
				}
				d1 = k;
				str3 = (char *) malloc ((d1+1) * sizeof(char));
				n = n - 81;
				for (int i = 0; i <= d1; i++){
					str3[i] = str2[n];
					n++;
				}
				printf("%s\n", str3);
				minstr(str3);//printf("%d\n", n);
			}
			if (((str3[79] != ' ') && (str3[80] == ' ')) || ((str3[79] == ' ') && (str3[80] != ' ')) || ((str3[79] == ' ') && (str3[80] == ' '))){
				str3 = (char *) malloc (81 * sizeof(char));
				for (int i = 0; i < 80; i++){
					str3[i] = str2[n];
					n++;
				}
				printf("%s\n", str3);
				minstr(str3);
			}
		}
		else{
			d2 = n;
			str3 = (char *) malloc ((strlen(str2) - n + 2)* sizeof(char));
			//printf("d1");
			//printf("%d\n", strlen(str2));
			//printf("%s\n", str2);
			//printf("n - %d\n", n);
			for (int i = 0; i < (strlen(str2) - d2); i++){
				str3[i] = str2[n];
				n++;
			}
			//printf("%s\n", str3);
			minstr(str3);	
		}
	}
	return 0;
}


int evenness(char *str2){
	int pobg;
	char str[80];
	if (strlen(str2) <= 80) {
		for (int pobg = 0; pobg < strlen(str2); pobg++){
			str[pobg] = str2[pobg];
		}
		minstr(str2);
	}
	else{
		maxstr(str2);
	}		
}

int prt(char *str){
	printf("%s", str);
	return 0;
}

	
int input(){
	int k = 1, n = 1;
	char str[81];
	char *str2;
	str2 = (char *) malloc (n*sizeof(char));
	//while (k != -1){
		do {
			k = scanf("%80[^\n]", &str);
			if (k == 1) {				
				n += strlen(str);		
				str2 = (char *) realloc (str2, (n+1)*sizeof(char));
				strcat(str2,str);
				//prt(str2);
				//printf("%d\n", strlen(str2));
			}
			else{
				evenness(str2);
				free(str2);
			}
		}
		while (k > 0);
	//}
}

int main() {
	input(); 
	return 0;
}
