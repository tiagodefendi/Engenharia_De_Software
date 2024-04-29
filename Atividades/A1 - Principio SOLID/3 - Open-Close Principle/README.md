# Open-Close Principle

Esse princípio defende algo que pode parecer paradoxal: uma classe deve estar fechada para modificações e aberta para extensões. No entanto, o aparente paradoxo se esclarece quando o projeto da classe prevê a possibilidade de extensões e customizações. Para isso, o projetista pode se valer de recursos como herança, funções de mais alta ordem (ou funções lambda) e padrões de projeto, como Abstract Factory, Template Method e Strategy. Especificamente, no próximo capítulo, iremos tratar de padrões de projeto que permitem customizar uma classe sem modificar o seu código.

Em resumo, o Princípio Aberto/Fechado tem como objetivo a construção de classes flexíveis e extensíveis, capazes de se adaptarem a diversos cenários de uso, sem modificações no seu código fonte.

## Violando o Princípio Aberto-Fechado (OCP):

No exemplo original, temos uma classe CartaoCredito que possui um método CalculaDesconto. Dentro deste método, há uma série de condicionais que verificam o tipo de cartão de crédito (Bandeira_A, Bandeira_B, etc.) para calcular o desconto. Isso viola o OCP, pois se novas bandeiras de cartão forem adicionadas, será necessário alterar o código existente para incluir as novas condições.

```
class CartaoCredito:
    def __init__(self, bandeira):
        self.bandeira = bandeira

    def CalculaDesconto(self, valor_fatura):
        if self.bandeira == "Bandeira_A":
            # Lógica para calcular desconto da bandeira A
            pass
        elif self.bandeira == "Bandeira_B":
            # Lógica para calcular desconto da bandeira B
            pass

```

## Respeitando o Princípio Aberto-Fechado (OCP):

Para respeitar o OCP, devemos projetar nossas classes de forma que elas estejam abertas para extensões (novos tipos de cartão de crédito) e fechadas para modificações (alterações no código existente). Neste exemplo, criamos uma classe abstrata CartaoCredito com um método abstrato CalculaDesconto, que será implementado pelas subclasses correspondentes a cada bandeira de cartão de crédito.

```
from abc import ABC, abstractmethod

class CartaoCredito(ABC):
    @abstractmethod
    def CalculaDesconto(self, valor_fatura):
        pass

class CartaoBandeira_A(CartaoCredito):
    def CalculaDesconto(self, valor_fatura):
        # Lógica para calcular desconto da bandeira A
        pass

class CartaoBandeira_B(CartaoCredito):
    def CalculaDesconto(self, valor_fatura):
        # Lógica para calcular desconto da bandeira B
        pass

class CartaoBandeira_C(CartaoCredito):
    def CalculaDesconto(self, valor_fatura):
        # Lógica para calcular desconto da bandeira C
        pass

```

Neste exemplo, as subclasses CartaoBandeira_A, CartaoBandeira_B e CartaoBandeira_C estendem a classe abstrata CartaoCredito, implementando o método CalculaDesconto de acordo com as particularidades de cada bandeira. Isso permite adicionar novas bandeiras sem modificar o código existente na classe base, respeitando assim o Princípio Aberto-Fechado (OCP).

>**A primeira versão do código, que viola o princípio, está no primeiro commit do arquivo, já a versão "correta" está no segundo commit**
