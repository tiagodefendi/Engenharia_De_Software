# Dependence Invertion Principle

Esse princípio recomenda que uma classe cliente deve estabelecer dependências prioritariamente com abstrações e não com implementações concretas, pois abstrações (isto é, interfaces) são mais estáveis do que implementações concretas (isto é, classes). A ideia é então trocar (ou inverter) as dependências: em vez de depender de classes concretas, clientes devem depender de interfaces. Portanto, um nome mais intuitivo para o princípio seria Prefira Interfaces a Classes.

## Violando o Princípio da Inversão de Dependência:

No exemplo original, a classe PushButton possui uma dependência direta da classe Led, o que significa que está fortemente acoplada a ela. Isso viola o Princípio da Inversão de Dependência, pois qualquer modificação na classe Led pode afetar o funcionamento da classe PushButton.

```
#include <iostream>

class Led {
public:
    void Ligar() {
        std::cout << "Led ligado" << std::endl;
    }

    void Desligar() {
        std::cout << "Led desligado" << std::endl;
    }
};

class PushButton {
private:
    Led led;

public:
    void Acionar(bool input) {
        if (input) {
            led.Ligar();
        } else {
            led.Desligar();
        }
    }
};

```

## Respeitando o Princípio da Inversão de Dependência:

Para respeitar o Princípio da Inversão de Dependência, devemos introduzir uma abstração entre PushButton e Led, de modo que ambas as classes dependam da mesma abstração. No exemplo abaixo, criamos uma interface Dispositivo que define os métodos Ligar() e Desligar(), e tanto PushButton quanto Led dependem dessa abstração.

```
#include <iostream>

class Dispositivo {
public:
    virtual void Ligar() = 0;
    virtual void Desligar() = 0;
};

class Led : public Dispositivo {
public:
    void Ligar() override {
        std::cout << "Led ligado" << std::endl;
    }

    void Desligar() override {
        std::cout << "Led desligado" << std::endl;
    }
};

class PushButton {
private:
    Dispositivo* dispositivo;

public:
    PushButton(Dispositivo* disp) : dispositivo(disp) {}

    void Acionar(bool input) {
        if (input) {
            dispositivo->Ligar();
        } else {
            dispositivo->Desligar();
        }
    }
};

```
Neste exemplo, a classe PushButton agora depende da abstração Dispositivo, e a classe Led implementa essa abstração. Isso permite que ambas as classes sejam modificadas independentemente uma da outra, respeitando assim o Princípio da Inversão de Dependência.

>**A primeira versão do código, que viola o princípio, está no primeiro commit do arquivo, já a versão "correta" está no segundo commit**
