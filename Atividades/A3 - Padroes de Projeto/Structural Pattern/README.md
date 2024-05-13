# Structural Pattern - Padrões Estruturais

Os padrões estruturais explicam como montar objetos e classes em estruturas maiores mas ainda mantendo essas estruturas flexíveis e eficientes

## Adapter - Adaptador

O Adapter é um padrão de projeto estrutural que permite objetos com interfaces incompatíveis colaborarem entre si

### Problema


Você está desenvolvendo uma aplicação de monitoramento do mercado de ações que baixa dados em XML de várias fontes e os apresenta ao usuário em gráficos e diagramas. Para melhorar a aplicação, você decide integrar uma biblioteca de análise de terceiros, mas ela só trabalha com dados em formato JSON

Integrar diretamente a biblioteca seria complicado, pois ela não suporta o formato de dados atual da sua aplicação e modificar a biblioteca para aceitar XML pode ser inviável, especialmente se você não tiver acesso ao seu código-fonte

### Solução

Um adaptador é um objeto que converte a interface de um objeto para que outro objeto possa entendê-lo. Ele encobre a complexidade da conversão, permitindo que objetos com interfaces diferentes colaborem sem que um precise estar ciente do outro

Adaptadores podem converter dados entre formatos diferentes e facilitar a colaboração entre objetos com interfaces distintas. Na solução do Adapter para a aplicação da bolsa de valores, adaptadores XML-para-JSON são criados para cada classe da biblioteca de análise, permitindo que o código se comunique com a biblioteca através desses adaptadores, que traduzem os dados XML em JSON antes de passá-los para os métodos da biblioteca

### Código

```{python}
class Target:
    def request(self) -> str:
        return "Target: The default target's behavior."


class Adaptee:
    def specific_request(self) -> str:
        return ".eetpadA eht fo roivaheb laicepS"


class Adapter(Target, Adaptee):
    def request(self) -> str:
        return f"Adapter: (TRANSLATED) {self.specific_request()[::-1]}"


def client_code(target: "Target") -> None:
    print(target.request(), end="")


if __name__ == "__main__":
    print("Client: I can work just fine with the Target objects:")
    target = Target()
    client_code(target)
    print("\n")

    adaptee = Adaptee()
    print("Client: The Adaptee class has a weird interface. "
          "See, I don't understand it:")
    print(f"Adaptee: {adaptee.specific_request()}", end="\n\n")

    print("Client: But I can work with it via the Adapter:")
    adapter = Adapter()
    client_code(adapter)

```

### UML

![](https://refactoring.guru/images/patterns/diagrams/adapter/structure-object-adapter.png)
