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
