# Liskov Substitution Principle

Herança não é mais um conceito popular como foi na década de 80, hoje, o emprego de herança é mais restrito e raro. No entanto, alguns casos de uso ainda são justificados. Herança define uma relação é-um entre objetos de uma classe base e objetos de subclasses. A vantagem é que comportamentos (isto é, métodos) comuns a essas classes podem ser implementados uma única vez, na classe base. Feito isso, eles são herdados em todas as subclasses.O Princípio de Substituição de Liskov explicita regras para redefinição de métodos de classes base em classes filhas.

## Violando o Princípio da Substituição de Liskov (LSP):

No exemplo temos uma classe base Quadrilatero que possui duas subclasses Quadrado e Retangulo. A classe base possui um método para calcular a área simplesmente multiplicando a largura pela altura. No entanto, quando tentamos criar um objeto Quadrado com lados de comprimentos diferentes, a exceção é lançada, o que viola o LSP, pois isso significa que o objeto Quadrado não pode ser substituído pelo objeto Quadrilatero de forma transparente.

```
#include <iostream>
#include <stdexcept>

class Quadrilatero {
protected:
    int largura;
    int altura;
public:
    Quadrilatero(int larg, int alt) : largura(larg), altura(alt) {}

    int calcularArea() const {
        return largura * altura;
    }
};

class Quadrado : public Quadrilatero {
public:
    Quadrado(int lado) : Quadrilatero(lado, lado) {
        if (largura != altura) {
            throw std::invalid_argument("Erro: largura e altura diferentes!");
        }
    }
};

class Retangulo : public Quadrilatero {
public:
    Retangulo(int larg, int alt) : Quadrilatero(larg, alt) {}
};

```

## Respeitando o Princípio da Substituição de Liskov (LSP):

Para respeitar o LSP, devemos garantir que as subclasses possam ser substituídas pelas classes base sem alterar o comportamento do programa. No exemplo abaixo, a classe base Quadrilatero é modificada para não incluir lógica específica para retângulos ou quadrados. As subclasses Quadrado e Retangulo apenas estendem essa classe base e implementam suas próprias particularidades.

```
#include <iostream>

class Quadrilatero {
protected:
    int largura;
    int altura;
public:
    Quadrilatero(int larg, int alt) : largura(larg), altura(alt) {}

    int calcularArea() const {
        return largura * altura;
    }
};

class Quadrado : public Quadrilatero {
public:
    Quadrado(int lado) : Quadrilatero(lado, lado) {}
};

class Retangulo : public Quadrilatero {
public:
    Retangulo(int larg, int alt) : Quadrilatero(larg, alt) {}
};

```

Neste exemplo, a classe base Quadrilatero fornece uma interface comum para calcular a área, enquanto as subclasses Quadrado e Retangulo apenas herdam essa funcionalidade e não incluem lógica adicional que poderia violar o LSP.

>**A primeira versão do código, que viola o princípio, está no primeiro commit do arquivo, já a versão "correta" está no segundo commit**
