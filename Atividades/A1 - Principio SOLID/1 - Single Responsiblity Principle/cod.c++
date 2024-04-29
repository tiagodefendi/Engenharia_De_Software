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
