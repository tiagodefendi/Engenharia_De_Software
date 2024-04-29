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
