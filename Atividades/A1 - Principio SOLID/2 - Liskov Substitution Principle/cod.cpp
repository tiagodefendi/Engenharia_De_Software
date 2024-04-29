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
