# 2. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?

```{}
void sendMail(ContaBancaria conta, String msg) {
    Cliente cliente = conta.getCliente();
    String endereco = cliente.getMailAddress();
    "Envia mail"
}
```

---

## Resposta:

Demeter

```
void sendMail(Cliente cliente, String msg) {
    String endereco = cliente.getMailAddress();
    "Envia mail"
}
```

## Justificativa:

O Princípio de Demeter — também chamado de Princípio do Menor Privilégio (Principle of Least Privilege) — defende que a implementação de um método deve invocar apenas os seguintes outros métodos:

* de sua própria classe

* de objetos passados como parâmetros

* de objetos criados pelo próprio método

* de atributos da classe do método

A função, ao chamar dois métodos get em sequência, viola o Princípio de Demeter. O motivo é que os objetos intermediários — retornados pelos métodos get — são usados apenas como passagem para se chegar ao objeto final, que é aquele que de fato nos interessa e sobre o qual vamos executar uma operação útil

```{}
void sendMail(ContaBancaria conta, String msg) {
    Cliente cliente = conta.getCliente();
    String endereco = cliente.getMailAddress();
}
```

Uma das soluções possiveis é mudar o parâmetro de entrada do método passando o cliente direto, assim não precisaria um objeto intermediário
