/*
* Autor: Ilder Rafael Damasceno Ponte
* Prof: Dr. Vítor Alencar de Mesquita
* (UNILAB 2023)
* Jogo "SHOW DO MILHÃO" feito para console com interface de texto. 
* Trabalho para a disciplina ALGORITMOS E PROGRAMAÇÃO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Estrutura das perguntas
typedef struct
{
    char enunciado[1024];
    char op1[1024];
    char op2[1024];
    char op3[1024];
    char op4[1024];
    char op5[1024];
    int gabarito; 
}  
pergunta;

//Imprime mensagem de ajuda
void printHelp()
{
    printf("\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------- SHOW DO MILHÃO -------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" COMO JOGAR:\n");
    printf("\n");
    printf(" 1.NO JOGO HAVERÁ UM TOTAL DE 10 PERGUNTAS \n");
    printf(" 2.SERÃO 4 FACEIS, 4 MEDIANAS, E 2 DIFÍCEIS \n");
    printf(" 3.AS PERGUNTAS SÃO PSEUDO-ALEATORIAS \n");
    printf(" 4.PARA RESPONDER SELECIONE UM NÚMERO E PRESSIONE \"ENTER\" \n\n\n");
    system("pause");
}

//Imprime mensagem de detalhes da versão
void printVersion()
{
    printf("\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------- SHOW DO MILHÃO -------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf(" ------------------------------------------\n");
    printf("(UNILAB 2023) Version 0.1.1 (MR-Rafael2005)\n\n\n");
    system("pause");
}

//Imprime mensagem padrão para argumentos errados
void printDefautArgs()
{
    printf("\n");
    printf(" O ARGUMENTO DIGITADO É INVÁLIDO, OS VALIDOS SÃO:\n");
    printf(" --help ou -h \n");
    printf(" --version ou -v \n");
    printf("\n Uso: program [argumento] \n");
    printf("\n PARA JOGAR APENAS INICIE O PROGRAMA\n\n\n");
    system("pause");
}

int main(int nargs, char* args[])
{
    setlocale(LC_CTYPE, "pt_BR.utf8");
    /*
    * Define o padrão de caracteres a serem usados
    * ou
    * setlocale(LC_ALL,"Portuguese"); 
    * Para caracteres e números, mas de qualquer forma
    * se a CLI não tiver suporte a UTF-8 os acentos
    * e outros caracteres da lingua portuguesa não
    * serão demostrados corretamente
    */   

    //Verificar se a CLI suporta UTF-8
    /*Não utilizarei pois é uma medição imprecisa, na maioria das vezes reconhece que a CLI não suporta UTF-8 mesmo tendo suporte
    char *locale = setlocale(LC_CTYPE, NULL);
    char escolha;
    printf("%s\n\n", locale);
    if (locale != NULL) 
    {
        if (strstr(locale, "UTF-8") == NULL) 
        {
            printf("A CLI nao suporta UTF-8.\nO programa pode apresentar falhas na apresentacao de caracteres.\n");
            printf("Deseja continuar mesmo assim?\n1.Sim\n");
            scanf(" %c", &escolha);
        } 
    } else {
        printf("Nao foi possível determinar a configuração de caracteres da CLI. \nO programa pode apresentar falhas na apresentacao de caracteres.\n");
        printf("Deseja continuar mesmo assim?\n1.Sim\n");
        scanf(" %c", &escolha);
    }

    if(escolha != '1')
    {
        return 0;
    }
    */

    //Pega os arquivos txt e armazena nas variaveis
    FILE *pF, *pM, *pD;
    pF = fopen("./BancoDePerguntas/faceis.txt","r");
    pM = fopen("./BancoDePerguntas/medias.txt","r");
    pD = fopen("./BancoDePerguntas/dificeis.txt","r");
    
    //Verificar se algum dos txt contendo as perguntas não foi achado
    if (pF == NULL || pM == NULL || pD == NULL)
    {
        printf("Ocorreu um erro ao carregar as perguntas \n");
        printf("Verifique se os arquivos no diretorio \"BancoDePerguntas\" estão corretos"); 
        system("pause");
        return 0;   
    } 

    //Reconhecer se ha algum argumento ao executar o programa no prompt de comado. Por exeplo: program --help
    if(nargs == 2)
    {
        if(strcmp(args[1], "--help") == 0 || strcmp(args[1], "-h") == 0)
        {
            printHelp();
        } 
        else if(strcmp(args[1], "--version") == 0 || strcmp(args[1], "-v") == 0)
        {
            printVersion();
        } 
        else
        {
            printDefautArgs();
        }
         
        return 0;
    } 
    else if(nargs > 2)
    {
        printf("\n DIGITE APENAS UM ARGUMENTO \n");
        
        return 0;
    }

    //Colocar as perguntas dos arquivos txt nas variaveis de acordo com a dificuldade
    pergunta pFaceis[10], pMedias[10], pDificeis[10];
    char linha[1024];

    //Define as perguntas faceis
    for (int i = 0; i < 10; i++)
    {
        fgets(linha, 1024, pF);
        strcpy(pFaceis[i].enunciado, linha);
        fgets(linha, 1024, pF);
        
        fgets(linha, 1024, pF);
        strcpy(pFaceis[i].op1, linha);
        fgets(linha, 1024, pF);
        strcpy(pFaceis[i].op2, linha);
        fgets(linha, 1024, pF);
        strcpy(pFaceis[i].op3, linha);
        fgets(linha, 1024, pF);
        strcpy(pFaceis[i].op4, linha);
        fgets(linha, 1024, pF);
        strcpy(pFaceis[i].op5, linha);

        fgets(linha, 1024, pF);
        
        if(pFaceis[i].op1[1] == '*')
        {
            pFaceis[i].op1[1] = '.';
            pFaceis[i].gabarito = 1;
        } 
        else if(pFaceis[i].op2[1] == '*')
        {
            pFaceis[i].op2[1] = '.';
            pFaceis[i].gabarito = 2;
        } 
        else if(pFaceis[i].op3[1] == '*')
        {
            pFaceis[i].op3[1] = '.';
            pFaceis[i].gabarito = 3;
        }
        else if(pFaceis[i].op4[1] == '*')
        {
            pFaceis[i].op4[1] = '.';
            pFaceis[i].gabarito = 4;
        }
        else if(pFaceis[i].op5[1] == '*')
        {
            pFaceis[i].op5[1] = '.';
            pFaceis[i].gabarito = 5;
        } 
        else
        {
            printf("ERRO: UMA DAS PERGUNTAS NÃO APRESENTA RESPOSTA");
            printf("PERGUNTA: \n%s \n%s\n%s\n%s\n%s\n%s\n", pFaceis[i].enunciado, pFaceis[i].op1, pFaceis[i].op2, pFaceis[i].op3 , pFaceis[i].op4, pFaceis[i].op5);
            printf("VERIFIQUE A PERGUNTA ENTRE AS FACEIS\n");
            system("pause");
            return 1;
        }     
    }

    //Define as perguntas medias
    for (int i = 0; i < 10; i++)
    {
        fgets(linha, 1024, pM);
        strcpy(pMedias[i].enunciado, linha);
        fgets(linha, 1024, pM);

        fgets(linha, 1024, pM);
        strcpy(pMedias[i].op1, linha);
        fgets(linha, 1024, pM);
        strcpy(pMedias[i].op2, linha);
        fgets(linha, 1024, pM);
        strcpy(pMedias[i].op3, linha);
        fgets(linha, 1024, pM);
        strcpy(pMedias[i].op4, linha);
        fgets(linha, 1024, pM);
        strcpy(pMedias[i].op5, linha);

        fgets(linha, 1024, pM);
        
        if(pMedias[i].op1[1] == '*')
        {
            pMedias[i].op1[1] = '.';
            pMedias[i].gabarito = 1;
        } 
        else if(pMedias[i].op2[1] == '*')
        {
            pMedias[i].op2[1] = '.';
            pMedias[i].gabarito = 2;
        } 
        else if(pMedias[i].op3[1] == '*')
        {
            pMedias[i].op3[1] = '.';
            pMedias[i].gabarito = 3;
        } 
        else if(pMedias[i].op4[1] == '*')
        {
            pMedias[i].op4[1] = '.';
            pMedias[i].gabarito = 4;
        } 
        else if(pMedias[i].op5[1] == '*')
        {
            pMedias[i].op5[1] = '.';
            pMedias[i].gabarito = 5;
        } 
        else 
        {
            printf("ERRO: UMA DAS PERGUNTAS NÃO APRESENTA RESPOSTA");
            printf("PERGUNTA: \n%s \n%s\n%s\n%s\n%s\n%s\n", pMedias[i].enunciado, pMedias[i].op1, pMedias[i].op2, pMedias[i].op3 , pMedias[i].op4, pMedias[i].op5);
            printf("VERIFIQUE A PERGUNTA ENTRE AS MEDIAS\n");
            system("pause");
            return 1;
        }
    }
    
    //Define as perguntas dificeis
    for (int i = 0; i < 10; i++)
    {
        fgets(linha, 1024, pD);
        strcpy(pDificeis[i].enunciado, linha);
        fgets(linha, 1024, pD);
        
        fgets(linha, 1024, pD);
        strcpy(pDificeis[i].op1, linha);
        fgets(linha, 1024, pD);
        strcpy(pDificeis[i].op2, linha);
        fgets(linha, 1024, pD);
        strcpy(pDificeis[i].op3, linha);
        fgets(linha, 1024, pD);
        strcpy(pDificeis[i].op4, linha);
        fgets(linha, 1024, pD);
        strcpy(pDificeis[i].op5, linha);

        fgets(linha, 1024, pD);

        if(pDificeis[i].op1[1] == '*')
        {
            pDificeis[i].op1[1] = '.';
            pDificeis[i].gabarito = 1;
        } 
        else if(pDificeis[i].op2[1] == '*')
        {
            pDificeis[i].op2[1] = '.';
            pDificeis[i].gabarito = 2;
        } 
        else if(pDificeis[i].op3[1] == '*')
        {
            pDificeis[i].op3[1] = '.';
            pDificeis[i].gabarito = 3;
        } 
        else if(pDificeis[i].op4[1] == '*')
        {
            pDificeis[i].op4[1] = '.';
            pDificeis[i].gabarito = 4;
        } 
        else if(pDificeis[i].op5[1] == '*')
        {
            pDificeis[i].op5[1] = '.';
            pDificeis[i].gabarito = 5;
        } 
        else
        {
            printf("ERRO: UMA DAS PERGUNTAS NÃO APRESENTA RESPOSTA");
            printf("PERGUNTA: \n%s \n%s\n%s\n%s\n%s\n%s\n", pDificeis[i].enunciado, pDificeis[i].op1, pDificeis[i].op2, pDificeis[i].op3 , pDificeis[i].op4, pDificeis[i].op5);
            printf("VERIFIQUE A PERGUNTA ENTRE AS DIFICEIS\n");
            system("pause");
            return 1;
        }
    }

    //Começar o jogo
    int continuar, escolha, pFeitas[4] = {-1,-1,-1,-1}, premios[10] = {50,100,500,1000,5000,10000,50000,100000,500000,1000000};

    for(int i = 0; i < 10; i++)
    {
        //Resetar as peguntas quando passar de facil pra medio, e de medio para dificil
        if(i == 4 || i == 8)
        {
            pFeitas[0] = -1;
            pFeitas[1] = -1;
            pFeitas[2] = -1;
            pFeitas[3] = -1;
        }

        //Gerar uma pergunta aleatoria sem repetir
        int pergunta;
        srand(time(NULL));//Define o tempo atual como parametro para rand(), aumentando a pseudo-aleatoriedade dos numeros gerados
        
        while (1)
        {
            pergunta = rand() % 10;

            if (pergunta == pFeitas[0])
            {
                continue;
            } 
            else if (pergunta == pFeitas[1])
            {
                continue;
            }
            else if (pergunta == pFeitas[2])
            {
                continue;
            } 
            else if (pergunta == pFeitas[3])
            {
                continue;
            }
            
            if(pFeitas[0] == -1)
            {
                pFeitas[0] = pergunta;
            } 
            else if(pFeitas[1] == -1)
            {
                pFeitas[1] = pergunta;
            } 
            else if(pFeitas[2] == -1)
            {
                pFeitas[2] = pergunta;
            } 
            else if(pFeitas[3] == -1)
            {
                pFeitas[3] = pergunta;
            }        
            
            break;
        }

        //Apresenta o cabeçalho da pergunta
        if(i < 9)
        {
            printf(" ------------------------------------------\n");
            printf(" ------------------------------------------\n");
            printf(" ------------------------------------------\n");
            printf(" ------------- SHOW DO MILHÃO -------------\n");
            printf(" ------------------------------------------\n");
            printf(" ------------------------------------------\n");
            printf(" ------------------------------------------\n");
            printf("\n");
            printf("\n");
            printf("VALENDO %d REAIS: ", premios[i]);
        }
        else
        {
            printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf(" $$$$$$$$$$$$$ SHOW DO MILHÃO $$$$$$$$$$$$$\n");
            printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf("\n");
            printf("\n");
            printf("PERGUNTA FINAL VALENDO %d REAIS: ", premios[i]);
        }

        //Apresenta a pergunta com base na dificuldade
        if(i < 4)
        {
            printf("%s",pFaceis[pergunta].enunciado);
            printf("\n");
            printf("%s",pFaceis[pergunta].op1);
            printf("%s",pFaceis[pergunta].op2);
            printf("%s",pFaceis[pergunta].op3);
            printf("%s",pFaceis[pergunta].op4);
            printf("%s",pFaceis[pergunta].op5);
            printf("\n");
            printf(": ");
            scanf(" %d", &escolha);

            if(escolha == pFaceis[pergunta].gabarito)
            {
                system("cls");
                printf("MAS CHERTA A RESPOSTA!\n");
                printf("VOCÊ GANHOU %d REAIS!\n",premios[i]);
                printf("DESEJA CONTINUAR E TENTAR GANHAR %d REAIS?\n",premios[i+1]);
                printf("1 - SIM\n");
                printf("0 - NÃO\n");
                printf(": ");
                scanf(" %d", &continuar);

                if(continuar == 0)
                {
                    system("cls");
                    printf("VOCÊ DESISTIU...\n");
                    printf("PRÊMIO: %d REAIS\n",premios[i]);
                    //getch();
                    system("pause");
                    return 0;
                }
            } 
            else 
            {
                system("cls");
                printf("MA VAI PRA LÁ, VAI PRA LÁ...\n");
                printf("VOCÊ PERDEU TUDO!\n");
                //getch();
                system("pause");
                return 0;
            }
        }
        else if (i < 8)
        {
            printf("%s",pMedias[pergunta].enunciado);
            printf("\n");
            printf("%s",pMedias[pergunta].op1);
            printf("%s",pMedias[pergunta].op2);
            printf("%s",pMedias[pergunta].op3);
            printf("%s",pMedias[pergunta].op4);
            printf("%s",pMedias[pergunta].op5);
            printf("\n");
            printf(": ");
            scanf(" %d", &escolha);

            if(escolha == pMedias[pergunta].gabarito)
            {
                system("cls");
                printf("MAS CHERTA A RESPOSTA!\n");
                printf("VOCÊ GANHOU %d REAIS!\n",premios[i]);
                printf("DESEJA CONTINUAR E TENTAR GANHAR %d REAIS?\n",premios[i+1]);
                printf("1 - SIM\n");
                printf("0 - NÃO\n");
                printf(": ");
                scanf(" %d", &continuar);

                if(continuar == 0)
                {
                    system("cls");
                    printf("VOCÊ DESISTIU...\n");
                    printf("PRÊMIO: %d REAIS\n",premios[i]);
                    //getch();
                    system("pause");
                    return 0;
                }
            } 
            else 
            {
                system("cls");
                printf("MA VAI PRA LÁ, VAI PRA LÁ...\n");
                printf("VOCÊ PERDEU TUDO!\n");
                //getch();
                system("pause");
                return 0;
            }
        } 
        else
        {
            printf("%s",pDificeis[pergunta].enunciado);
            printf("\n");
            printf("%s",pDificeis[pergunta].op1);
            printf("%s",pDificeis[pergunta].op2);
            printf("%s",pDificeis[pergunta].op3);
            printf("%s",pDificeis[pergunta].op4);
            printf("%s",pDificeis[pergunta].op5);
            printf("\n");
            printf(": ");
            scanf("%d",&escolha);

            if(escolha == pDificeis[pergunta].gabarito)
            {
                if(i<9)
                {
                    system("cls");
                    printf("MAS CHERTA A RESPOSTA!\n");
                    printf("VOCÊ GANHOU %d REAIS!\n",premios[i]);
                    printf("DESEJA CONTINUAR E TENTAR GANHAR %d REAIS?\n",premios[i+1]);
                    printf("1 - SIM\n");
                    printf("0 - NÃO\n");
                    printf(": ");
                    scanf(" %d",&continuar);

                    if(continuar == 0)
                    {
                        system("cls");
                        printf("VOCÊ DESISTIU...\n");
                        printf("PRÊMIO: %d REAIS\n",premios[i]);
                        //getch();
                        system("pause");
                        return 0;
                    }
                }
                else
                {
                    system("cls");
                    printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
                    printf(" $$$$$$$$$$  MAS CHERTA A RESPOSTA!  $$$$$$$$\n");
                    printf(" $$$$$$$$$$  VOCÊ É O GRANDE CAMPEÃO $$$$$$$$\n");
                    printf(" $$$$$$$$$$$$$$$  E GANHOU  $$$$$$$$$$$$$$$$$\n");
                    printf(" $$$$$$$$$$$$$$$$$$  UM  $$$$$$$$$$$$$$$$$$$$\n");
                    printf(" $$$$$$$$$$$$$$$$  MILHÃO  $$$$$$$$$$$$$$$$$$\n");
                    printf(" $$$$$$$$$$$$$$$  DE REAIS !!!  $$$$$$$$$$$$$\n");
                    printf(" $$$$$$$ RECEBA AS PALMAS DO AUDITÓRIO! $$$$$\n");
                    printf(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
                    //getch();
                    system("pause");
                    return 0;
                }
            }
            else
            {
                system("cls");
                printf("MA VAI PRA LÁ, VAI PRA LÁ...\n");
                printf("VOCÊ PERDEU TUDO!\n");
                //getch();
                system("pause");
                return 0;
            }
            //system("cls");
        }
        system("cls"); //Limpar o console a cada pergunta
    }
}