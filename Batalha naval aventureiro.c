#include <stdio.h>

int main() {
    
    int main()
{

    int abssisa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ordenada[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int mar[10][10], navios[10][10];

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            mar[j][i] = 0;
            navios[j][i] = 0;
        }
    }

    printf("Coordenada do primeiro navio\n");
    for (int i = 0; i < 3; i++) //Navio na horizontal
    {
        navios[1][3 + i] = 3;
        printf("Linha 1 e coluna %i...\n", 4 + i);
    }

    printf("Coordenada do segundo navio\n");
    for (int i = 0; i < 3; i++)//Navio na vertical
    {
        navios[6 + i][9] = 3;
        printf("Linha %i e coluna 10...\n", 7 + i);
    }

    printf("Coordenada do terceiro navio\n");
    for (int i = 0; i < 3; i++)//Navio na diagonal
    {
        navios[4 + i][7 - i] = 3;
        printf("Linha %i e coluna %i...\n", 5 + i, 8 - i);
    }

    printf("Coordenada do quarto navio\n");
    for (int i = 0; i < 3; i++)//Navio na diagonal
    {
        navios[3 + i][1 + i] = 3;
        printf("Linha %i e coluna %i...\n", 4 + i, 2 - i);
    }

    for (int j = 0; j < 10; j++)//adição dos navios ao mar
    {
        for (int i = 0; i < 10; i++)
        {
            mar[j][i] = mar[j][i] + navios[j][i];
        }
    }

    for (int coluna = 0; coluna < 10; coluna++)
    {
        if (coluna == 0)
        {
            printf("   %d ", abssisa[coluna]); // Na primeira coluna de numeros é pra ter o espaço para ficar alinhado
        }
        else
        {
            printf("%d ", abssisa[coluna]);
        }
    }
    printf("\n");

    for (int linha = 0; linha < 10; linha++)
    {
        for (int coluna = 0; coluna < 10; coluna++) // Vai printar a primeira linha e vai repetir isso 10 vezes como o código acima
        {
            if (coluna == 0) // Quando está no começo da primeira linha printar o numero da execução
            {
                if (linha < 9) // (numeros de 1 a 9) O 10 ocupa o lugar de dois digitos por isso os anteriores precisão de um espaço
                {

                    printf("%i  ", ordenada[linha]);
                }
                else // (10)E quando é o 10 não precisa
                {
                    printf("%i ", ordenada[linha]);
                }
                printf("%i ", mar[linha][coluna]);
            }
            else
            {
                printf("%i ", mar[linha][coluna]);
            }
        }
        printf("\n");
    }

    return 0;
}
