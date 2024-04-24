# 5. Qual das seguintes classes é mais coesa? Justifique computando os valores de LCOM de cada uma delas

    ```{}
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

## Resposta:

A classe A é mais coesa que a classe B

## Justificativa:

LCOM parte do pressuposto que, em uma classe coesa, qualquer par de métodos deve acessar pelo menos um atributo em comum. Ou seja, o que dá coesão a uma classe é o fato de seus métodos trabalharem com os mesmos atributos. Por isso, a coesão de uma classe é prejudicada — isto é, seu LCOM aumenta em uma unidade — sempre que achamos um par de métodos (f1,f2), onde f1 manipula alguns atributos e f2 manipula atributos diferentes

Dessa forma, pode-se afirmar que a classe A é mais coesa que a classe B, tendo em vista que o LCOM(A) = 0 e LCOM(B) = 3, ou seja, LCOM(B) > LCOM(A)

LCOM(A):

```{}
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
```

Pares de Métodos (M) | Conjunto A | Interseção Conjunto A
:-:|:-:|:-:
(f, g) | A(f) = {x} <br> A(g) = {x} | {x}
(f, h) | A(f) = {x} <br> A(h) = {x} | {x}
(g, h) | A(g) = {x} <br> A(h) = {x} | {x}

Logo, LCOM(A) = 0, pois a classe A tem três possíveis pares de métodos, e todos eles acessam pelo menos um atributo em comum (veja terceira coluna da tabela). Não resta nenhum único par de métodos que não tem atributos em comum

LCOM(B):

```{}
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

Pares de Métodos (M) | Conjunto A | Interseção Conjunto A
:-:|:-:|:-:
(f, g) | A(f) = {x} <br> A(g) = {y} | ∅
(f, h) | A(f) = {x} <br> A(h) = {z} | ∅
(g, h) | A(g) = {y} <br> A(h) = {z} | ∅

Logo, LCOM(B) = 3, pois a classe B tem três possíveis pares de métodos, e nenhum deles acessam pelo menos um atributo em comum (veja terceira coluna da tabela). restam todos par de métodos que não tem atributos em comum

