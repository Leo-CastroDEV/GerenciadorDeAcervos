#include <stdio.h>      // Biblioteca padrão de entrada e saída (printf, scanf, fopen)
#include <stdlib.h>     // Biblioteca de funções auxiliares (qsort, malloc, free)
#include <string.h>     // Biblioteca para manipulação de strings (fgets, strcmp, etc.)
#include <locale.h>     // Biblioteca para permitir acentuação no console

// -----------------------------------------------------------------------------
// CONSTANTES E DEFINIÇÕES
// -----------------------------------------------------------------------------

// Quantidade máxima de livros permitidos no acervo
#define MAX_LIVROS 20

// Tamanho máximo para cada campo de string do livro
#define TAM_TITULO 100
#define TAM_AUTOR 50
#define TAM_AREA 50
#define TAM_EDITORA 50

// Nome do arquivo que armazenará os dados
#define NOME_ARQUIVO "acervo_biblioteca.dat"

// -----------------------------------------------------------------------------
// ESTRUTURA PRINCIPAL DO SISTEMA
// -----------------------------------------------------------------------------

// Struct responsável por armazenar todas as informações de um livro
typedef struct {
    int codigo;                      // Código de identificação do livro
    char titulo[TAM_TITULO];         // Nome do livro
    char autor[TAM_AUTOR];           // Nome do autor
    char area[TAM_AREA];             // Área de conhecimento
    int ano;                         // Ano de publicação
    char editora[TAM_EDITORA];       // Nome da editora
} Livro;

// Vetor que representa o acervo da biblioteca
Livro acervo[MAX_LIVROS];

// Contador que indica quantos livros existem atualmente no acervo
int contador_livros = 0;

// -----------------------------------------------------------------------------
// PROTÓTIPOS DAS FUNÇÕES
// -----------------------------------------------------------------------------
void carregar_dados_do_arquivo();
void salvar_dados_no_arquivo();
void menu();
void limpar_buffer();
void cadastrar_livro();
void imprimir_acervo();
void pesquisar_livro_codigo();
void ordenar_livros_ano();
void excluir_acervo();

// -----------------------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// -----------------------------------------------------------------------------

int main() {
    setlocale(LC_ALL, ""); // Permite acentuação no terminal

    int opcao;

    carregar_dados_do_arquivo(); // Tenta carregar dados salvos anteriormente

    // Loop principal do menu (executa até o usuário escolher 0)
    do {
        menu(); // Exibe as opções na tela

        // Verifica se a entrada foi válida
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            limpar_buffer(); // Remove caracteres inválidos
            continue;
        }

        limpar_buffer(); // Remove o ENTER deixado pelo scanf

        // Escolha da operação conforme a opção digitada
        switch (opcao) {
            case 1:
                cadastrar_livro();
                break;

            case 2:
                imprimir_acervo();
                break;

            case 3:
                pesquisar_livro_codigo();
                break;

            case 4:
                ordenar_livros_ano();
                break;

            case 5:
                excluir_acervo();
                break;

            case 0:
                salvar_dados_no_arquivo(); // Salva antes de fechar
                printf("Saindo... Dados salvos com sucesso.\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0); // Repete até o usuário escolher sair

    return 0;
}

// -----------------------------------------------------------------------------
// FUNÇÃO: limpar_buffer
// Remove lixo deixado no buffer de entrada para evitar bugs com fgets/scanf
// -----------------------------------------------------------------------------

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -----------------------------------------------------------------------------
// FUNÇÃO: menu
// Exibe o menu principal para o usuário
// -----------------------------------------------------------------------------

void menu() {
    printf("\n========== Menu Principal ==========\n");
    printf("\n1. Cadastrar novo livro\n");
    printf("2. Imprimir todos os livros\n");
    printf("3. Pesquisar livro por codigo\n");
    printf("4. Ordenar livros por ano de publicacao\n");
    printf("5. Excluir TODO o acervo\n");
    printf("0. Sair do programa\n");
    printf("\nEscolha uma opção: ");
}


// -----------------------------------------------------------------------------
// FUNÇÃO: cadastrar_livro
// Realiza o cadastro de um novo livro no acervo
// -----------------------------------------------------------------------------

void cadastrar_livro() {
    // Verifica se há espaço disponível
    if (contador_livros >= MAX_LIVROS) {
        printf("Erro: Acervo cheio. Maximo de %d livros atingido.\n", MAX_LIVROS);
        return;
    }

    Livro novo_livro;

    printf("--- Cadastro de Livro ---\n");

    // Gera código automaticamente
    novo_livro.codigo = contador_livros + 1;
    printf("Codigo do livro: %d\n", novo_livro.codigo);

    // Lê os demais dados do livro
    printf("Titulo: ");
    fgets(novo_livro.titulo, TAM_TITULO, stdin);
    novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(novo_livro.autor, TAM_AUTOR, stdin);
    novo_livro.autor[strcspn(novo_livro.autor, "\n")] = 0;

    printf("Area: ");
    fgets(novo_livro.area, TAM_AREA, stdin);
    novo_livro.area[strcspn(novo_livro.area, "\n")] = 0;

    printf("Editora: ");
    fgets(novo_livro.editora, TAM_EDITORA, stdin);
    novo_livro.editora[strcspn(novo_livro.editora, "\n")] = 0;

    printf("Ano de publicacao: ");
    while (scanf("%d", &novo_livro.ano) != 1) {
        printf("Ano invalido. Tente novamente: ");
        limpar_buffer();
    }
    limpar_buffer();

    // Adiciona o livro ao vetor
    acervo[contador_livros] = novo_livro;
    contador_livros++;

    printf("\nLivro cadastrado com sucesso!\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO: imprimir_acervo
// Mostra todos os livros armazenados
// -----------------------------------------------------------------------------

void imprimir_acervo() {
    if (contador_livros == 0) {
        printf("O acervo esta vazio.\n");
        return;
    }

    printf("\n--- Acervo da Biblioteca (%d livros) ---\n", contador_livros);

    for (int i = 0; i < contador_livros; i++) {
        printf("---------------------------------------\n");
        printf("Cod: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    }

    printf("---------------------------------------\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO: pesquisar_livro_codigo
// Permite localizar um livro digitando seu código numérico
// -----------------------------------------------------------------------------

void pesquisar_livro_codigo() {
    if (contador_livros == 0) {
        printf("O acervo está vazio.\n");
        return;
    }

    int codigo_busca;
    printf("Digite o codigo do livro: ");

    // Captura o código do livro
    while (scanf("%d", &codigo_busca) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        limpar_buffer();
    }
    limpar_buffer();

    // Procura o livro no acervo
    for (int i = 0; i < contador_livros; i++) {
        if (acervo[i].codigo == codigo_busca) {
            printf("\nLivro encontrado:\n");
            printf("---------------------------------------\n");
            printf("Cod: %d\n", acervo[i].codigo);
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Area: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            printf("---------------------------------------\n");
            return;
        }
    }

    printf("\nNenhum livro encontrado com esse codigo.\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO: comparar_ano
// Função auxiliar usada pelo qsort para ordenar por ano
// -----------------------------------------------------------------------------

int comparar_ano(const void *a, const void *b) {
    Livro *A = (Livro *)a;
    Livro *B = (Livro *)b;

    // Ordenação crescente (ano menor primeiro)
    return A->ano - B->ano;
}

// -----------------------------------------------------------------------------
// FUNÇÃO: ordenar_livros_ano
// Ordena os livros pela data crescente de publicação
// -----------------------------------------------------------------------------

void ordenar_livros_ano() {
    if (contador_livros < 2) {
        printf("Necessario pelo menos 2 livros para ordenar.\n");
        return;
    }

    qsort(acervo, contador_livros, sizeof(Livro), comparar_ano);
    printf("Acervo ordenado por ano de publicação (crescente).\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO: excluir_acervo
// Apaga todos os livros da memória e do arquivo
// -----------------------------------------------------------------------------

void excluir_acervo() {
    contador_livros = 0;

    FILE *arquivo = fopen(NOME_ARQUIVO, "wb");
    if (!arquivo) {
        printf("Erro ao acessar arquivo.\n");
        return;
    }

    fwrite(&contador_livros, sizeof(int), 1, arquivo);
    fclose(arquivo);

    printf("TODO o acervo foi excluido!\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO: salvar_dados_no_arquivo
// Salva a quantidade e os livros em um arquivo binário
// -----------------------------------------------------------------------------

void salvar_dados_no_arquivo() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "wb");
    if (!arquivo) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    fwrite(&contador_livros, sizeof(int), 1, arquivo);
    fwrite(acervo, sizeof(Livro), contador_livros, arquivo);

    fclose(arquivo);
}

// -----------------------------------------------------------------------------
// FUNÇÃO: carregar_dados_do_arquivo
// Lê o arquivo binário e restaura o acervo
// -----------------------------------------------------------------------------

void carregar_dados_do_arquivo() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "rb");
    if (!arquivo) {
        printf("Arquivo nao encontrado. Iniciando acervo vazio.\n");
        return;
    }

    fread(&contador_livros, sizeof(int), 1, arquivo);
    fread(acervo, sizeof(Livro), contador_livros, arquivo);

    fclose(arquivo);

    printf("Dados carregados com sucesso (%d livros).\n", contador_livros);
}
