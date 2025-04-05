#include <stdio.h>

int main()
{

    int abssisa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ordenada[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int efeito, linha, coluna;
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
        printf("Linha 2 e coluna %i...\n", 4 + i);
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
        navios[1 + i][7 - i] = 3;
        printf("Linha %i e coluna %i...\n", 2 + i, 8 - i);
    }

    printf("Coordenada do quarto navio\n");
    for (int i = 0; i < 3; i++)//Navio na diagonal
    {
        navios[3 + i][1 + i] = 3;
        printf("Linha %i e coluna %i...\n", 4 + i, 2 + i);
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

    printf("Qual efeito usar? \nCone(1) \nCruz(2) \nOctógono(3)\n");
    scanf("%d", &efeito);
    printf("Em qual linha quer usar?\n");
    scanf("%d", &linha);
    printf("Em qual coluna quer usar?\n");
    scanf("%d", &coluna);
    coluna=coluna-3;
    linha=linha-2;
    switch (efeito)
    {
    case 1:
        int cone[5][3];
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                cone[i][j] = 0;
                if (i == 2)
                {
                    cone[i][j] = 1;
                }
                if ((i == 1 || i == 3) && j == 1)
                {
                    cone[i][j] = 1;
                }
                if (j == 2)
                {
                    cone[i][j] = 1;
                }
            }
        }
        printf("...................\n");
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                mar[linha + j][coluna + i] = mar[linha + j][coluna + i] + cone[i][j];
            }
        }

        break;
    case 2:
        int cruz[5][3];
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                cruz[i][j] = 0;
                if (i == 2)
                {
                    cruz[i][j] = 1;
                }
                if (j == 1)
                {
                    cruz[i][j] = 1;
                }
                printf("%d", cruz[i][j]);
            }
            printf("\n");
        }
        printf("...................\n");
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                mar[linha + j][coluna + i] = mar[linha + j][coluna + i] + cruz[i][j];
            }
        }
        break;

    case 3:
        int oct[5][3];
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                oct[i][j] = 0;
                if (i == 2)
                {
                    oct[i][j] = 1;
                }
                if ((i == 1 || i == 3) && j == 1)
                {
                    oct[i][j] = 1;
                }
            }
        }
        printf("...................\n");
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                mar[linha + j][coluna + i] = mar[linha + j][coluna + i] + oct[i][j];
            }
        }
        break;

    default:
        printf("Nenhum efeito encontrado");
        break;
    }
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", mar[j][i]);
        }
        printf("\n");
    }

    return 0;
}