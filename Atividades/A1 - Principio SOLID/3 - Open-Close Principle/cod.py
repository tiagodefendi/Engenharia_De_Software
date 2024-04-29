class CartaoCredito:
    def __init__(self, bandeira):
        self.bandeira = bandeira

    def CalculaDesconto(self, valor_fatura):
        if self.bandeira == "Bandeira_A":
            # Lógica para calcular desconto da bandeira A
            pass
        elif self.bandeira == "Bandeira_B":
            # Lógica para calcular desconto da bandeira B
            pass
