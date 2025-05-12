#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double variavel(int x, double b) {
	
	// As variaveis representam respectivamente: x = posição do caractere, b = variavel do agente.
	
    double a0 = 348.11;
    double a1 = -278.007;
    double a2 = 64.9146;
    double a3 = -6.62433;
    double a4 = 0.346464;
    double a5 = -0.0097146;
    double a6 = 0.000138889;
    double a7 = -7.94637e-7;

    return (a0 + ((a1 + b) * x)) + (a2 * pow(x, 2)) + (a3 * pow(x, 3)) + (a4 * pow(x,4)) + (a5 * pow(x, 5))+ (a6 * pow(x, 6)) + (a7 * pow(x, 7));
}

int main() {
    int y, i, j;
    
    scanf("%d", &y); // ler a entrada inicial

    for (i = 0; i < y; i++) {
        double b;
        char hexadecimal[101]; 

        scanf("%lf", &b); // Vai ler o valor dado para b (lf funciona para ler a variavel em double)
        scanf("%s", hexadecimal);  

        int x = 1; // Posição do caractere inicia sempre como 1

        for ( j = 0; j < 100; j += 2) {
            char pares[3];
 // Como a mensagem está decodificada em hexadecimal, será necessario transformar, a cada 2 caracteres da mensagem representa 1 caracter real. E por se tratar de uma string, apesar de par, o valor não poderá ser apenas 2, pois o "\0" conta como um valor. 
            pares[0] = hexadecimal[j];
            pares[1] = hexadecimal[j + 1];
            pares[2] = '\0';

            int valor;
            sscanf(pares, "%x", &valor); // scanf com duplo "s" para representar a leitura de um valor de string que no caso está representada pela variavel "par"

            if (valor == 0) {
                break; // Código vai encerrar ao encontrar um valor neutro
            }

            if (variavel(x, b) >= 0) { // Caso o valor seja maior ou igual a zero dará um caractere
                printf("%c", valor);
            }

            x++;
        }

        printf("\n"); 
    }

    return 0;
}
