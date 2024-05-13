# Behavioral Pattern - Padrões comportamentais

Estes padrões são voltados aos algoritmos e a designação de responsabilidades entre objetos

## Iterator - Iterador

O Iterador é um padrão de projeto comportamental que permite a passagem sequencial através de uma estrutura de dados complexa sem expor seus detalhes internos. Graças a ele, os clientes podem examinar elementos de diferentes coleções de maneira semelhante usando uma única interface iterador

### Problema

Coleções são amplamente usadas na programação como contêineres para grupos de objetos. Elas devem oferecer métodos para acessar elementos de forma eficiente, independentemente da complexidade da estrutura de dados. A travessia de coleções, como árvores, pode variar de acordo com as necessidades, como percorrer em profundidade ou amplitude

Adicionar muitos algoritmos de travessia às coleções pode desviar sua função principal de armazenamento eficiente de dados. Por outro lado, o código cliente pode não se preocupar com a estrutura interna da coleção, mas ainda precisa lidar com suas diferentes maneiras de acesso aos elementos, o que pode levar ao acoplamento com classes de coleções específicas

### Solução

Iterators são objetos que encapsulam os detalhes da travessia de uma coleção, como a posição atual e a quantidade de elementos restantes. Isso permite que múltiplos iterators percorram a mesma coleção independentemente um do outro. Eles geralmente oferecem um método para acessar os elementos da coleção, que o cliente pode chamar até que não haja mais elementos, indicando que a travessia está completa

Todos os iterators seguem a mesma interface, o que permite que o código cliente seja compatível com qualquer tipo de coleção ou algoritmo de travessia, desde que haja um iterador apropriado disponível. Se uma travessia especial é necessária, basta criar uma nova classe de iterador sem alterar a coleção ou o código cliente. Isso promove a modularidade e a reutilização do código

### Código

```{python}
from __future__ import annotations
from collections.abc import Iterable, Iterator
from typing import Any

class AlphabeticalOrderIterator(Iterator):
    _position: int = None
    _reverse: bool = False

    def __init__(self, collection: WordsCollection, reverse: bool = False) -> None:
        self._collection = collection
        self._reverse = reverse
        self._position = -1 if reverse else 0

    def __next__(self) -> Any:
        try:
            value = self._collection[self._position]
            self._position += -1 if self._reverse else 1
        except IndexError:
            raise StopIteration()

        return value


class WordsCollection(Iterable):
    def __init__(self, collection: list[Any] | None = None) -> None:
        self._collection = collection or []


    def __getitem__(self, index: int) -> Any:
        return self._collection[index]

    def __iter__(self) -> AlphabeticalOrderIterator:
        return AlphabeticalOrderIterator(self)

    def get_reverse_iterator(self) -> AlphabeticalOrderIterator:
        return AlphabeticalOrderIterator(self, True)

    def add_item(self, item: Any) -> None:
        self._collection.append(item)


if __name__ == "__main__":
    collection = WordsCollection()
    collection.add_item("First")
    collection.add_item("Second")
    collection.add_item("Third")

    print("Straight traversal:")
    print("\n".join(collection))
    print("")

    print("Reverse traversal:")
    print("\n".join(collection.get_reverse_iterator()), end="")

```

### UML

![](https://refactoring.guru/images/patterns/diagrams/iterator/structure.png?id=35ea851f8f6bbe51d79eb91e6e6519d0)
