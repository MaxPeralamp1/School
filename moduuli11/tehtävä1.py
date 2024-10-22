class Julkaisu:
    def __init__(self, nimi):
        self.nimi = nimi

    def tulosta_tiedot(self):
        print("Nimi " + self.nimi)

class Kirja(Julkaisu):
    def __init__(self, nimi, kirjoittaja, sivumäärä):
        self.nimi = nimi
        self.kirjoittaja = kirjoittaja
        self.sivumäärä = sivumäärä
        super().__init__(nimi)

    def tulosta_tiedot(self):
        super().tulosta_tiedot()
        print("Kirjoittaja " + self.kirjoittaja)
        print("Sivumäärä " + str(self.sivumäärä))

class Lehti(Julkaisu):
    def __init__(self, nimi, päätoimittaja):
        self.nimi = nimi
        self.päätoimittaja = päätoimittaja
        super().__init__(nimi)

    def tulosta_tiedot(self):
        super().tulosta_tiedot()
        print("Päätoimittaja " + self.päätoimittaja)


julkaisu1 = Lehti("Aku Ankka", "Aki Vittuenmuista")
julkaisu1.tulosta_tiedot()
print("")
julkaisu2 = Kirja("Hytti n:o 6", "Rosa Liksom", 200)
julkaisu2.tulosta_tiedot()