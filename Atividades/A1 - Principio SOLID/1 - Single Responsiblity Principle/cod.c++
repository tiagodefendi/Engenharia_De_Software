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
