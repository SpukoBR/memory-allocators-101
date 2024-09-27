# Memory Allocators 101

Este repositório contém uma implementação simples de um alocador de memória em C, conforme discutido no artigo ["Memory Allocators 101"](https://arjunsreedharan.org/post/148675821737/memory-allocators-101-write-a-simple-memory) por Arjun024. O objetivo deste projeto é construir um alocador de memória básico que inclui implementações de `malloc()`, `calloc()`, `realloc()` e `free()`.

## Visão Geral

Este projeto demonstra os conceitos fundamentais por trás da alocação de memória em C. O alocador é construído usando a chamada de sistema `sbrk()` para gerenciar a memória do heap. Observe que esta implementação é projetada para fins educacionais e não está otimizada para desempenho ou alinhamento.

## Layout da Memória

Entender o layout da memória de um processo é crucial:

- **Seção de Texto**: Contém instruções binárias executáveis.
- **Seção de Dados**: Armazena dados estáticos inicializados diferentes de zero.
- **BSS**: Contém dados estáticos inicializados com zero.
- **Heap**: Usado para dados alocados dinamicamente.
- **Stack**: Armazena variáveis automáticas, argumentos de função, etc.

A pilha (stack) e o heap crescem em direções opostas. O final do heap é demarcado pelo program break (`brk`), que pode ser manipulado usando a chamada de sistema `sbrk()`.

## Detalhes da Implementação

### `malloc(size_t size)`

Aloca `size` bytes de memória e retorna um ponteiro para a memória alocada. Utiliza `sbrk()` para estender o heap.

```
void *malloc(size_t size);
```

### `calloc(size_t num, size_t nsize)`

Aloca memória para um array de `num` elementos de `nsize` bytes cada, e inicializa todos os bytes com zero.

```
void *calloc(size_t num, size_t nsize);
```

### `realloc(void *block, size_t size)`

Altera o tamanho do bloco de memória apontado por `block` para `size`. Lida com redimensionamento e cópia de dados.

```
void *realloc(void *block, size_t size);
```

### `free(void *block)`

Libera o bloco de memória apontado por `block`. Marca o bloco como livre e, se o bloco estiver no final do heap, o libera de volta para o sistema operacional.

```
void free(void *block);
```

## Implementação

Os arquivos de código são organizados da seguinte forma:

- **`ft_malloc.c`**: Contém a implementação da função `ft_malloc()`, que aloca memória e gerencia a lista de blocos livres.
- **`ft_free.c`**: Contém a implementação da função `ft_free()`, que libera um bloco de memória e pode reduzir o tamanho do heap se o bloco liberado estiver no final.
- **`ft_calloc.c`**: Contém a implementação da função `ft_calloc()`, que aloca memória e inicializa todos os bytes com zero.
- **`ft_realloc.c`**: Contém a implementação da função `ft_realloc()`, que altera o tamanho do bloco de memória existente e copia os dados.

### Funções Utilizadas

- **`ft_malloc(size_t size)`**: Aloca um bloco de memória do tamanho especificado.
- **`ft_free(void *block)`**: Libera o bloco de memória especificado.
- **`ft_calloc(size_t num, size_t nsize)`**: Aloca memória para um array e inicializa todos os bytes com zero.
- **`ft_realloc(void *block, size_t size)`**: Redimensiona um bloco de memória existente.

## Compilando e Usando o Alocador

Para compilar o alocador de memória e usá-lo como uma biblioteca compartilhada:

1. **Compile o Alocador:**

    ```
    make
    ```

2. **Pré-carregue a Biblioteca:**

    ```
    export LD_PRELOAD=$PWD/memalloc.so
    ```

3. **Execute um Programa de Teste:**

    ```
    ls
    ```

    Seu alocador de memória personalizado será utilizado para este comando.

## Depuração

Para depuração, você pode imprimir mensagens de depuração nas funções `malloc()`, `free()`, `calloc()` e `realloc()` para rastrear sua execução e verificar o comportamento do alocador.

## Licença

Este projeto está licenciado sob a Licença MIT - consulte o arquivo `LICENSE` para obter detalhes.

## Agradecimentos

Agradecimentos a Arjun024 pelo artigo original e pela inspiração para este projeto. O código-fonte pode ser encontrado em [github.com/arjun024/memalloc](https://github.com/arjun024/memalloc).
