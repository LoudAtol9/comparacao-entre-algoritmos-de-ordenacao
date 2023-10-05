# Comparação entre algoritmos de ordenação

## Descrição
O projeto tem como finalidade  possibilitar a comparação entre os diferentes algoritmos de ordenação vistos em aula. Para isso foi utilizado uma mescla entre Python e C.

## Algoritmos trabalhados
### Insertion Sort  
- Complexidade pior caso: Θ(n²)
- Complexidade caso médio: Θ(n²)
- Complexidade melhor caso: Θ(n)
Similar ao jeito que se organiza as cartas de um baralho, o algoritmo consiste em encontrar a posição do próximo elemento não ordenado do array ao fazer sucessivas comparações entre ele e os elementos da parte já ordenada do array.

### Selection Sort
- Complexidade pior caso: Θ(n²)
- Complexidade caso médio: Θ(n²)
- Complexidade melhor caso: Θ(n²)
Consiste em encontrar o menor elemento da parte não ordenada do array e colocá-lo na ponta da parte ordenada do array.

### Merge Sort 
- Complexidade pior caso: Θ(nlog n)
- Complexidade caso médio: Θ(nlog n)
- Complexidade melhor caso: Θ(nlog n)
Um algoritmo de divisão e conquista, consiste em dividir sucessivamente o array original ao meio, até que hajam n arrays de um único elemento. É feita então a mescla desses arrays, de forma que o vetor original seja ordenado.

### Heap Sort
- Complexidade pior caso: Θ(nlog n)
- Complexidade caso médio: Θ(nlog n)
- Complexidade melhor caso: Θ(nlog n)
Utiliza uma estrutura max-heap a fim de ordenar o array recebido. Coloca-se a raiz da max-heap (e portanto o maior elemento) ao fim do vetor, e então é sucessivamente encontrada a nova max-heap para aquele vetor sem o elemento removido.

### Quick Sort
- Complexidade pior caso: Θ(n²)
- Complexidade caso médio: Θ(nlog n)
- Complexidade melhor caso: Θ(nlog n)
Consiste em selecionar um pivô e separar o array recebido em elementos maiores e menores que o dito pivô. Completada esta fase, é possível selecionar um novo pivô em cada um destes lados de forma recursiva, até que o vetor esteja ordenado.

	```parte de bibliotecas e instalação aqui embaixo```

