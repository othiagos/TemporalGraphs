# Temporal Graphs

## Sumário
- [Compilação](#Compilação)
- [Execução](#Execução)
- [Documentação](#Documentação)

# Compilação
Pode ser compilado com o seguinte comando:

``` sh
$ make
```

# Execução
a execução pode ser realizada tanto pelo Makefile: `make run`

quanto pela execução direta do executável: `bin/TemporalGraphs`

casos de teste podem ser encontrado em `docs/examples`

## Formato de Entrada
Cada caso de teste é composto por várias linhas. A primeira linha contém dois inteiros, N e M, que
representam, respectivamente, o número de vilas e conexões da Baicônia. É garantido que as via
formam caminhos entre todo par de vilas. Você pode assumir que que $1 ≤ N, M ≤ 10^6$
, e que as vilas
são numeradas com elementos do conjunto $\{1, 2, \dots , N\}$. Cada uma das $M$ linhas seguintes descreve uma
conexão entre um par de vilas, e contém cinco inteiros $u, v, a, ℓ, c,$ onde $u$ e $v$ são vilas $(1 ≤ u \not = v ≤ N)$,
$a$ é o ano de construção da via $(1 ≤ a ≤ 10^8), ℓ$ representa o tempo de travessia da via $(1 ≤ ℓ ≤ 10^5),$ e $c$ representa seu custo de construção $(1 ≤ c ≤ 10^5)$.


## Formato de Saída
A saída contém múltiplas linhas. Na $i$-ésima das primeiras $N$ linhas deve ser impresso um inteiro que
representa o tempo mínimo necessário para sair do palácio real e chegar à vila $i$. Na $N + 1$-ésima linha da
saída deve ser impresso um único inteiro $A_1$, que representa o primeiro ano no qual as distâncias listadas
nas linhas anteriores são mutuamente realizáveis. A $N + 2$-ésima linha da saída contém um único inteiro
$A_2$, que representa o primeiro ano a partir do qual é possível chegar em qualquer vila do reino a partir do
palácio real. Por fim, na linha $N + 3$, imprima um único inteiro, que representa o menor custo necessário
para conectar todo o reino.

# Documentação
O enunciado deste trabalho pode ser lido [aqui](https://github.com/othiagos/TemporalGraphs/tree/master/docs).