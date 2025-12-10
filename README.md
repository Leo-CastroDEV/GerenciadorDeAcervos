📚 Gerenciador de Acervos – Sistema em C

Um sistema simples e funcional para cadastro, consulta, ordenação e gerenciamento de livros em um acervo.
Desenvolvido em linguagem C, utilizando manipulação de arquivos, ordenação com qsort, vetores de structs e boas práticas de entrada e saída de dados.

🚀 Funcionalidades

O sistema permite:

✔ Cadastrar livros com: título, autor, área, ano e editora
✔ Gerar código automaticamente para cada livro
✔ Listar todos os livros do acervo
✔ Pesquisar livro por código
✔ Ordenar livros por ano de publicação (ordem crescente)
✔ Salvar automaticamente os dados em arquivo binário
✔ Carregar dados ao iniciar o programa
✔ Excluir todo o acervo (memória + arquivo)

🧠 Estrutura do Projeto
📂 Arquivos Principais
main.c
acervo_biblioteca.dat   → gerado automaticamente

🧱 Estrutura do Livro

Cada livro é armazenado usando a struct:

typedef struct {
int codigo;
char titulo[TAM_TITULO];
char autor[TAM_AUTOR];
char area[TAM_AREA];
int ano;
char editora[TAM_EDITORA];
} Livro;

🔧 Como Compilar

No terminal, execute:

✔ Windows (MinGW)
gcc main.c -o acervo.exe

✔ Linux / MacOS
gcc main.c -o acervo

▶️ Como Executar
Windows:
acervo.exe

Linux / MacOS:
./acervo

🖥️ Menu do Sistema

O programa exibe:

========== Menu Principal ==========

1. Cadastrar novo livro
2. Imprimir todos os livros
3. Pesquisar livro por codigo
4. Ordenar livros por ano de publicacao
5. Excluir TODO o acervo
0. Sair do programa

💾 Persistência de Dados

Todos os dados são armazenados em:

acervo_biblioteca.dat


Sempre que o usuário:

Inicia o programa → dados são carregados automaticamente

Sai do programa → dados são salvos

Exclui o acervo → arquivo é sobrescrito com zero registros

🧮 Ordenação por Ano

A ordenação usa qsort() com comparação crescente:

int comparar_ano(const void *a, const void *b) {
Livro *A = (Livro *)a;
Livro *B = (Livro *)b;
return A->ano - B->ano;
}

🧽 Tratamento de Erros e Entradas

O projeto usa:

✔ limpar_buffer() para evitar bugs com scanf e fgets
✔ verificação de entradas inválidas
✔ prevenção de overflow de strings
✔ validação de ano

📌 Limitações Atuais

Máximo de 20 livros (definido por #define MAX_LIVROS 20)

Sem edição de livros (apenas cadastro e consulta)

Ordenação apenas por ano

Pesquisas apenas pelo código

🛠️ Melhorias Futuras (Sugestões)

Se quiser evoluir o projeto, aqui vão ótimas ideias:

Editar informações de um livro

Excluir um único livro

Aumentar o limite de acervo

Exportar dados para .txt ou .csv

Pesquisa por título ou autor

Ordenação por título, autor ou área

Interface gráfica (GTK, Win32 ou ncurses)

👨‍💻 Autor

Leonardo Castro
Estudante de Análise e Desenvolvimento de Sistemas e desenvolvedor apaixonado por tecnologia.

📜 Licença

Este projeto é de uso livre para estudo, modificação e aprendizado.