import random
class Auto:

    def __init__(self, rekisteritunnus, huippunopeus):
        self.rekisteritunnus = rekisteritunnus
        self.huippunopeus = huippunopeus
        self.nopeus = 0
        self.kuljettumatka = 0

    def kiihdytä(self, muutos):
        self.nopeus += muutos
        if self.nopeus > self.huippunopeus:
            self.nopeus = self.huippunopeus
        elif self.nopeus < 0:
            self.nopeus = 0

    def kulje(self, tuntimäärä):
        self.kuljettumatka += self.nopeus * tuntimäärä
        print(self.rekisteritunnus, self.huippunopeus, self.kuljettumatka, self.nopeus)


class Sähköauto(Auto):
    def __init__(self, rekisteritunnus, huippunopeus, akkukapasiteetti):
        self.akkukapasiteetti = akkukapasiteetti
        super().__init__(rekisteritunnus, huippunopeus)

class BensaAuto(Auto):
    def __init__(self, rekisteritunnus, huippunopeus, tankki):
        self.tankki = tankki
        super().__init__(rekisteritunnus, huippunopeus)

#sähköauton (ABC-15, 180 km/h, 52.5 kWh)
#polttomoottoriauton (ACD-123, 165 km/h, 32.3 l)
sähköauto = Sähköauto("ABC-15", 180, 52.5)
polttis = BensaAuto("ACD-123", 165, 32.3)

sähköauto.kiihdytä(100000)
polttis.kiihdytä(10000)

sähköauto.kulje(3)
polttis.kulje(3)

