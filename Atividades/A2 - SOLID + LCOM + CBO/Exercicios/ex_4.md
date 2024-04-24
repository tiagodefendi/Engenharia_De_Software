# 4. Calcule o CBO e LCOM da seguinte classe: (Leia o Capitulo 5 do Livro do Marco Túlio - Engenharia de software moderna para aprender como realizar o Cálculo)

    ```{}
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

---

## Resposta:

CBO = 7

LCOM = 1

## Justificativa:

CBO:

CBO conta o número de classes das quais A depende de forma sintática (ou estrutural)

1. A herda de B

    ```{}
    class A extends B;
    ```

2. A declara três variáveis locais do tipo C

    ```{}
    C f1, f2, f3;
    ```

3. A declara um parâmetro tipo do tipo D

    ```{}
    void m1(D p) {
        "usa f1 e f2"
    }
    ```

4. A declara um parâmetro tipo do tipo E

    ```{}
    void m2(E p) {
        "usa f2 e f3"
    }
    ```

5. A declara um parâmetro tipo do tipo F

    ```{}
    void m3(F p) {
        "usa f3"
    }
    ```

CBO(A) = 1 + 3 + 1 + 1 + 1 = 7

LCOM:

```{}
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

Pares de Métodos (M) | Conjunto A | Interseção Conjunto A
:-:|:-:|:-:
(m1, m2) | A(m1) = {f1, f2} <br> A(m2) = {f2, f3} | {f2}
(m1, m3) | A(m1) = {f1, f2} <br> A(m3) = {f3} | ∅
(m2, m3) | A(m2) = {f2, f3} <br> A(m3) = {f3} | {f3}

Logo, LCOM(A) = 1, pois a classe A tem três possíveis pares de métodos, mas dois deles acessam pelo menos um atributo em comum (veja terceira coluna da tabela). Resta um único par de métodos que não tem atributos em comum.

