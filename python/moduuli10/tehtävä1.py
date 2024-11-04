class Hissi:
    def __init__(self, alin, ylin):
        self.alin = alin
        self.ylin = ylin
        self.nykyinenkerros = alin



    def siirrykerrokseen(self, kerros):
        if kerros < self.alin or kerros > self.ylin:
            print("Virhe: Kerros on sallitun alueen ulkopuolella.")
            return
        while self.nykyinenkerros < kerros:
            self.kerros_ylös()

        while self.nykyinenkerros > kerros:
            self.kerros_alas()

    def kerros_ylös(self):
        if self.nykyinenkerros < self.ylin:
            self.nykyinenkerros += 1
            print("Hissi on nyt kerroksessa"  + str(self.nykyinenkerros))
        else:
            print("Hissi on ylimmässä kerroksessa, ei voi siirtyä ylös.")

    def kerros_alas(self):
        if self.nykyinenkerros > self.alin:
            self.nykyinenkerros -= 1
            print("Hissi on nyt kerroksessa"  + str(self.nykyinenkerros))
        else:
            print("Hissi on alimmassa kerroksessa, ei voi siirtyä alas.")

class Talo:
    def __init__(self, hissien_määrä, alin_kerros, ylin_kerros):
        self.alin_kerros = alin_kerros
        self.ylin_kerros = ylin_kerros
        self.hissit = []

        for i in range (hissien_määrä):
            hissi = Hissi(alin_kerros, ylin_kerros)
            self.hissit.append(hissi)

    def aja_hissiä(self, hissin_numero, kohdekerros):
        hissi = self.hissit[hissin_numero]
        hissi.siirrykerrokseen(kohdekerros)

    def palohälytys(self):
        for hissi in self.hissit:
            hissi.siirrykerrokseen(self.alin_kerros)



talo = Talo(5, 1, 5)


print("Ajetaan hissiä 0 kerrokseen 3:")
talo.aja_hissiä(0, 3)

print("Ajetaan hissiä 1 kerrokseen 4:")
talo.aja_hissiä(1, 4)

print("Ajetaan hissiä 2 kerrokseen 1:")
talo.aja_hissiä(2, 1)

talo.palohälytys()