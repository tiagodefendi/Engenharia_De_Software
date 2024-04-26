# 3. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?

```{}
void imprimeDataContratacao(Funcionario func) {
    Date data = func.getDataContratacao();
    String msg = data.format();
    System.out.println(msg);
}
```

---

## Resposta:

Single Responsiblity Principle

```{}
void imprimeDataContratacao(String msg) {
    System.out.println(msg);
}
```

## Justificativa:

A função imprimeDataContratacao() está assumindo diversas responsabilidades para si.

1. Acesso ao objeto Funcionário e get de data:

    ```{}
    Date data = func.getDataContratacao();
    ```

2. Conversão de data para string:

    ```{}
    String msg = data.format();
    ```

Para isso, uma solução seria passar a mensagem como parâmetro
