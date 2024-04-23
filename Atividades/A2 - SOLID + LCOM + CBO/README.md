# Atividade Exercícios SOLID + LCOM + CBO

Para essa atividade foi requisitada a resolução dos execícios propostos pelo professor no qual se buscam por aprimorar estudos sobre SOLID, LCOM e CBO. Ao termino da atividade foi pedida a criação de um conjunto de slides com a resolução do execício.

## Exercícios

1. Qual princípio de projeto é violado pelo seguinte código?
    ```
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
2. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?
    ```
    void sendMail(ContaBancaria conta, String msg) {
    Cliente cliente = conta.getCliente();
    String endereco = cliente.getMailAddress();
    "Envia mail"
    }
    ```
3. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?
    ```
    void imprimeDataContratacao(Funcionario func) {
    Date data = func.getDataContratacao();
    String msg = data.format();
    System.out.println(msg);
    }
    ```
4. Calcule o CBO e LCOM da seguinte classe: (Leia o Capitulo 5 do Livro do Marco Túlio - Engenharia de software moderna para aprender como realizar o Cálculo)
    ```
    class A extends B {
    C f1, f2, f3;

    void m1(D p) {
        "usa f1 e f2"
    }
    void m2(E p) {
        "usa f2 e f3"
    }
    void m3(F p) {
        "usa f3"
    }
    }
    ```

5. Qual das seguintes classes é mais coesa? Justifique computando os valores de LCOM de cada uma delas
    ```
    class A {
    X x = new X();

    void f() {
        x.m1();
    }
    void g() {
        x.m2();
    }
    void h() {
        x.m3();
    }
    }

    class B {
    X x = new X();
    Y y = new Y();
    Z z = new Z();

    void f() {
        x.m();
    }
    void g() {
        y.m();
    }
    void h() {
        z.m();
    }
    }
    ```
