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

