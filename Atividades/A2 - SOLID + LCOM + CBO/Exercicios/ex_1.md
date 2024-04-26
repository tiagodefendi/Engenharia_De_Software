# 1. Qual princípio de projeto é violado pelo seguinte código?

```{}
void onclick() {
    num1 = textfield1.value();
    c1 = BD.getConta(num1)
    num2 = textfield2.value();
    c2 = BD.getConta(num2)
    valor = textfield3.value();
    beginTransaction();
    try {
        c1.retira(valor);
        c2.deposita(valor);
        commit();
    }
    catch() {
        rollback();
    }
}
```

---

## Resposta:

Single Responsiblity Principle

## Justificativa:

A função onclick() está assumindo diversas responsabilidades para si.

1. Busca de valores nos campos de texto:

    ```{}
    num1 = textfield1.value();
    num2 = textfield2.value();
    valor = textfield3.value();
    ```

2. Acesso e uso do método get no Banco de dados "BD":

    ```{}
    c1 = BD.getConta(num1)
    c2 = BD.getConta(num2)
    ```

3. Efetua transação:

    ```{}
    beginTransaction();
    try {
        c1.retira(valor);
        c2.deposita(valor);
        commit();
    }
    ```

4. Trata exceções:

    ```{}
    try {
        c1.retira(valor);
        c2.deposita(valor);
        commit();
    }
    catch() {
        rollback();
    }
    ```
