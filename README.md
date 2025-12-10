# 📚 Gerenciador de Acervos -- Sistema em C

Um sistema simples e funcional para cadastro, consulta, ordenação e
gerenciamento de livros em um acervo.\
Desenvolvido em linguagem **C**, utilizando manipulação de arquivos,
ordenação com `qsort`, vetores de structs e boas práticas de entrada e
saída de dados.

------------------------------------------------------------------------
🎥 Demonstração em Vídeo


<div align="center">
  <iframe width="560" height="315" 
          src="https://youtu.be/uBxwbRlgwrw" 
          title="Demonstração do Projeto" 
          frameborder="0" 
          allowfullscreen>
  </iframe>
</div>

------------------------------------------------------------------------
## 🚀 Funcionalidades

✔ **Cadastrar livros** com título, autor, área, ano e editora\
✔ **Gerar código automaticamente** para cada livro\
✔ **Listar todos os livros do acervo**\
✔ **Pesquisar livro por código**\
✔ **Ordenar livros por ano de publicação**\
✔ **Salvar automaticamente** os dados em arquivo binário\
✔ **Carregar dados ao iniciar o programa**\
✔ **Excluir todo o acervo**

------------------------------------------------------------------------

## 🧠 Estrutura do Projeto

### 📂 Arquivos

    main.c
    acervo_biblioteca.dat   → criado automaticamente

### 🧱 Struct principal

``` c
typedef struct {
    int codigo;
    char titulo[100];
    char autor[50];
    char area[50];
    int ano;
    char editora[50];
} Livro;
```

------------------------------------------------------------------------

## 🔧 Como Compilar

### Windows

    gcc main.c -o acervo.exe

### Linux / MacOS

    gcc main.c -o acervo

------------------------------------------------------------------------

## ▶️ Como Executar

### Windows

    acervo.exe

### Linux / MacOS

    ./acervo

------------------------------------------------------------------------

## 🖥️ Menu do Sistema

    1. Cadastrar novo livro
    2. Imprimir todos os livros
    3. Pesquisar livro por codigo
    4. Ordenar livros por ano
    5. Excluir acervo
    0. Sair

------------------------------------------------------------------------

## 💾 Persistência de Dados

O programa salva automaticamente as informações no arquivo:

    acervo_biblioteca.dat

------------------------------------------------------------------------

## 📌 Melhorias Futuras

-   [ ] Editar livro\
-   [ ] Excluir livro específico\
-   [ ] Exportar dados para CSV\
-   [ ] Busca por título ou autor\
-   [ ] Ordenação por título ou área

------------------------------------------------------------------------

## 👨‍💻 Autor

**Leonardo Castro**\
Estudante de ADS e desenvolvedor iniciante.

------------------------------------------------------------------------

## 📜 Licença

Uso livre para fins educacionais.
