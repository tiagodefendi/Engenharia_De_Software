# Single Responsiblity Principle

Esse princípio é uma aplicação direta da ideia de coesão. Ele propõe o seguinte: toda classe deve ter uma única responsabilidade. Mais ainda, responsabilidade, no contexto do princípio, significa motivo para modificar uma classe. Ou seja, deve existir um único motivo para modificar qualquer classe em um sistema.

Um corolário desse princípio recomenda separar apresentação de regras de negócio. Portanto, um sistema deve possuir classes de apresentação, que vão tratar de aspectos de sua interface com os usuários, formato das mensagens, meio no qual as mensagens serão exibidas, etc. E classes responsáveis por regras de negócio, isto é, que vão realizar as computações, processamento, análises, etc. São interesses e responsabilidades diferentes. E que podem evoluir e sofrer modificações por razões distintas. Portanto, elas devem ser implementadas em classes diferentes. Por esse motivo, não é surpresa que existam desenvolvedores que tratam apenas de requisitos de front-end (isto é, de classes de apresentação) e desenvolvedores que tratam de requisitos de backend (isto é, de classes com regras de negócio).

## Violando o Princípio da Responsabilidade Única (SRP):

No exemplo temos uma classe chamada DebitoContaCorrente que possui três métodos: ValidarSaldo, DebitarConta e EmitirComprovante. Essa classe possui múltiplas responsabilidades, o que viola o Princípio da Responsabilidade Única (SRP). O SRP afirma que uma classe deve ter apenas uma razão para mudar, ou seja, deve ter apenas uma responsabilidade.

```
#include <iostream>

class DebitoContaCorrente {
public:
    void ValidarSaldo(float valor) {
        printf("Validando saldo da conta corrente: R$ %f\n", valor);
    }

    void DebitarConta(float valor) {
        printf("Debitando conta corrente: R$ %f\n", valor);
    }

    void EmitirComprovante() {
        printf("Emitindo comprovante da conta corrente\n");
    }
};

```
## Respeitando o Princípio da Responsabilidade Única (SRP):

Para respeitar o SRP, devemos dividir as responsabilidades em classes separadas. No caso, teremos três classes distintas: DebitoContaCorrente, SaldoContaCorrente e ComprovanteContaCorrente, cada uma com uma única responsabilidade.

```
#include <iostream>

class DebitoContaCorrente {
public:
    void DebitarConta(float valor) {
        printf("Debitando conta corrente: R$ %f\n", valor);
    }
};


class SaldoContaCorrente {
public:
    void ValidarSaldo(float valor) {
        printf("Validando saldo da conta corrente: R$ %f\n", valor);
    }
};

class ComprovanteContaCorrente {
public:
    void EmitirComprovante() {
        printf("Emitindo comprovante da conta corrente\n");
    }
};

```

Nesta versão, cada classe tem uma única responsabilidade, respeitando assim o Princípio da Responsabilidade Única (SRP).

>**A primeira versão do código, que viola o princípio, está no primeiro commit do arquivo, já a versão "correta" está no segundo commit**
