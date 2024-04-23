2. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?
    ```
    void sendMail(ContaBancaria conta, String msg) {
    Cliente cliente = conta.getCliente();
    String endereco = cliente.getMailAddress();
    "Envia mail"
    }
    ```

Resposta:
Justificativa:
