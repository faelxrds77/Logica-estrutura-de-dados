// territorio = livro
// biblioteca = mapa
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// Constantes globais
#define MAX_TERRITORIOS 50
#define TAM_STRING 100

// Definição da estrutura (Struct)
struct Territorio {
    char nome [TAM_STRING];
    char cor [TAM_STRING];
    int tropas;

};

// Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função principal (main)
int main() {
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalTer = 0;
    int opcao;

    //Laço principal do menu
    do{

        // Exibe o menu de opções
        printf("===================\n");
        printf("MAPA DO MUNDO ESTADO ATUAL\n");
        printf("===================\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("0 - Sair\n");
        printf("--------------------\n");
        printf("Escolha uma opção\n");

        // Lê a opção do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

        // Processamento da Opção
        switch (opcao)
        {
        case 1: // Cadastro de território
            printf("Cadastro de novo território\n\n");

            if (totalTer < MAX_TERRITORIOS) {
                printf("Nome do território:");
                fgets(mapa[totalTer].nome, TAM_STRING, stdin);

                printf("Dominado por (ex.: Exército azul):");
                fgets(mapa[totalTer].cor, TAM_STRING, stdin);

                mapa[totalTer].nome[strcspn(mapa[totalTer].nome, "\n")]; 
                 mapa[totalTer].cor[strcspn(mapa[totalTer].cor, "\n")] ;

                  printf("Quantidade de tropas:");
                  scanf("%d", &mapa[totalTer].tropas);
                  limparBufferEntrada();

                  totalTer++;
                  // totalTer = totalTer +1

                  printf("\n Território cadastrado com sucesso!\n");
            }else{
                printf("Mapa cheio! Não foi possível cadastrar mais territórios.\n");
            }

            printf("\n Pressione Enter para continuar...");
            getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu
            break;

            case 2: // Listagem de territórios
            printf("Lista de territórios cadastrados\n");


            if (totalTer == 0) {
                printf("\n Nenhum territórios cadastrado ainda!\n");
            }else{
                for (int i = 0; i < totalTer; i++) {
                    printf("--------------------\n");
                    printf("- Território %d\n", i + 1);
                    printf("- Nome: %s\n", mapa[i].nome);
                    printf("- Cor: %s\n", mapa[i].cor);
                    printf("- Tropas: %d\n", mapa[i].tropas);
                }
                      printf("--------------------\n");
            }
            // A pausa é crucial para que o usuário veja a lista antes do próximo loop limpar a tela.

             printf("\n Pressione Enter para continuar...");
             getchar();
             break;

             case 0: // Sair
              printf("\n Saindo do sistema...");
              break;
            
              default: // Opção válida
               printf("\n Opcao inválida! Tente novamente.");
                printf("\n Pressione Enter para continuar...");
                getchar();
                break;
        }

    }while (opcao !=0);

    return 0; // Fim
}

