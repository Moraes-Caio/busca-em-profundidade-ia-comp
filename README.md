# Busca em Profundidade Iterativa (IDDFS) em C

Implementação em C do algoritmo de **Busca em Profundidade Iterativa** (*Iterative Deepening Depth-First Search*, IDDFS), desenvolvida para a disciplina de **Inteligência Computacional / Inteligência Artificial**.

O programa resolve um problema simples de busca em espaço de estados e mostra, passo a passo no terminal, como a pilha evolui durante a execução.

---

## O problema

- **Estado:** um número inteiro entre `0` e `100`.
- **Estado inicial:** informado pelo usuário.
- **Ações possíveis** (aplicadas nesta ordem):
  1. `estado - 5` (somente se o resultado for `>= 0`)
  2. `estado + 2` (somente se o resultado for `<= 100`)
- **Objetivo:** chegar a um **número primo** (entre 2 e 97).

A busca retorna a sequência de ações que leva do estado inicial até um número primo, com o menor limite de profundidade possível.

---

## Como o algoritmo funciona

A IDDFS combina a baixa memória da busca em profundidade com a completude da busca em largura:

1. Começa com limite de profundidade `0`.
2. Executa uma busca em profundidade (DFS) com esse limite, usando uma **pilha** e backtracking.
3. Se nenhum objetivo for encontrado, **aumenta o limite em 1** e repete a busca do zero.
4. Para quando encontra um número primo ou quando atinge o limite máximo (`TAM - 1 = 19`).

Como o limite cresce de um em um, a primeira solução encontrada é a de **menor número de ações**.

Durante a execução, o programa imprime:

- a pilha inicial de cada iteração;
- cada ação aplicada (`Estado X -> X - 5 = Y` ou `X + 2 = Y`), junto com a pilha atualizada e a profundidade de cada nó;
- os retornos (*backtracking*) quando um nó atinge o limite ou não tem mais filhos;
- o resultado final, com o estado encontrado e o número de ações.

---

## Estrutura do repositório

| Arquivo | Descrição |
|---|---|
| `Busca em Profundidade Iterativa.c` | Versão principal: IDDFS completa, com backtracking, validação de entrada e limite crescente. |
| `busca_em_profundidade.c` | Versão anterior/simplificada: simula a pilha com um limite informado pelo usuário, sem iterar o limite. |
| `busca_em_profundidade.exe` / `.o` | Binários gerados da compilação (Windows). |

---

## Como compilar e executar

É necessário um compilador C, como o `gcc`.

```bash
# Compilar
gcc "Busca em Profundidade Iterativa.c" -o busca

# Executar (Linux/macOS)
./busca

# Executar (Windows)
busca.exe
```

O programa pede o estado inicial (de 0 a 100) e valida a entrada: valores fora do intervalo ou textos que não são números são rejeitados e a pergunta é repetida.

---

## Exemplo de execução

**Estado inicial = 4**

| Limite | Resultado |
|---|---|
| 0 | Nenhum objetivo encontrado |
| 1 | Nenhum objetivo encontrado |
| 2 | Nenhum objetivo encontrado |
| 3 | **Objetivo encontrado: 3** |

Caminho encontrado: `4 → 6 → 1 → 3` (ações: `+2`, `-5`, `+2`), ou seja, **3 ações**.

**Estado inicial = 1** → `1 → 3` (`+2`), 1 ação.
**Estado inicial = 0** → `0 → 2` (`+2`), 1 ação.

---

## Conceitos abordados

- Busca em espaço de estados
- Busca em Profundidade (DFS) com limite de profundidade
- Busca em Profundidade Iterativa (IDDFS)
- Uso de pilha e backtracking
- Teste de objetivo (número primo)

---

## Autor

**Caio Moraes** — [@Moraes-Caio](https://github.com/Moraes-Caio)
