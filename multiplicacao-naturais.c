#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * multiplicar(char *n1, char *n2, int indice1, int indice2, int t) {
	int imult, mult, vai_um;
	char *result;
	int a = indice1, ordem = 0, aux = 0;
  
	imult = ++t;
	int b = imult;
	t++;
	result = (char*) malloc(sizeof(char) * (t + 1));
	result[t] = '\0';
	vai_um = 0;
	mult = 0;
	
    while (indice2 >= 0) {
        mult = (n1[indice1] - '0') * (n2[indice2] - '0') + vai_um;
        //printf("%d x %d + %d = %d\n", (n2[indice2] - '0'), (n1[indice1] - '0'), vai_um, mult);
        //printf("n1[indice1] == %d\n", n1[indice1] - '0');
        //printf("n2[indice2] == %d\n", n2[indice2] - '0');
        //printf("imult == %d\n", imult);
        //printf("indice1 == %d\n", indice1);
        //printf("indice2 == %d\n", indice2);
        if(ordem > 0) aux = result[imult] - '0'; else aux = 0;
        result[imult] = '0' + (mult + aux) % 10;
      //  for(int i = 0; i < sizeof(result); i++) printf("%c", result[i]);
      //  printf("\n\n");
        vai_um = (mult + aux) / 10;


        if (indice1 > 0) {
          indice1--;
        } 
        
        else if (indice2 >= 0) {
          indice1 = a;
          indice2--;
          result[--imult] = '0' + vai_um;
          vai_um = 0;
          imult = b--;
          ordem=1;
        }
        
        imult--;
    }
	
return result;
}

char * dados(char *n1, char *n2) {
	int t, indice1, indice2;
	indice1 = strlen(n1) - 1; 
	indice2 = strlen(n2) - 1;
	t = indice1 + indice2; 
	multiplicar(n1, n2, indice1, indice2, t);
}


int main() {
	printf("%s\n", dados("16", "1822"));
	return 0;
} 
