from abc import ABC, abstractmethod

class CartaoCredito(ABC):
    @abstractmethod
    def CalculaDesconto(self, valor_fatura):
        pass

class CartaoBandeira_A(CartaoCredito):
    def CalculaDesconto(self, valor_fatura):
        # Lógica para calcular desconto da bandeira A
        pass

class CartaoBandeira_B(CartaoCredito):
    def CalculaDesconto(self, valor_fatura):
        # Lógica para calcular desconto da bandeira B
        pass

class CartaoBandeira_C(CartaoCredito):
    def CalculaDesconto(self, valor_fatura):
        # Lógica para calcular desconto da bandeira C
        pass
