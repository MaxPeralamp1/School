#ulkoisen rajapinnan käyttö

import json
import requests

hakusana = input("Anna hakusana: ")

pyyntö = "https://api.tvmaze.com/search/shows?q=" + hakusana

try:
    vastaus = requests.get(pyyntö)

    if vastaus.status_code == 200:
        json_vastaus = vastaus.json()
        print(json.dumps(json_vastaus, indent=4))
        for a in json_vastaus:
            print(a["show"]["name"])
except requests.exceptions.RequestException as e:
    print("Ongelma")


#assosiaatio

class Koira:
    tehty = 0
    def __init__(self, nimi, syntymävuosi, haukahdus="vuhvuh"):
        self.nimi = nimi
        self.syntymävuosi = syntymävuosi
        self.haukahdus = haukahdus
        Koira.tehty = Koira.tehty + 1

    def hauku(self, kerrat):
        for i in range(kerrat):
            print(self.nimi + " haukkuu " + self.haukahdus)
        return

    class Hoitola:
        def __init__(self):
            self.koirat = []

        def koira_sisään(self, koira):
            self.koirat.append(koira)
            print(koira.nimi + " kirjattu sisään")
            return

        def koira_ulos(self, koira):
            self.koirat.remove(koira)
            print(koira.nimi + " kirjattu ulos")
            return

        def tervehdi_koiria(self):
            for koira in self.koirat:
                koira.hauku(1)






#tilapäinen assosiaatio

class Auto:
    def __init__(self, rekisteritunnus, väri):
        self.rekisteritunnus = rekisteritunnus
        self.väri = väri

class Maalaamo:
    def maalaa(self, auto, väri):
        auto.väri = väri



maalaamo = Maalaamo()

auto = Auto("ABC-123", "sininen")
maalaamo.maalaa(auto, "punainen")





#periytyminen


class Työntekijä:
    työntekijöiden_lukumäärä = 0
    def __init__(self, etunimi, sukunimi):
        Työntekijä.työntekijöiden_lukumäärä = Työntekijä.työntekijöiden_lukumäärä + 1
        self.työntekijänumero = Työntekijä.työntekijöiden_lukumäärä
        self.etunimi = etunimi
        self.sukunimi = sukunimi

    def tulosta_tiedot(self):
        print(self.työntekijänumero, self.etunimi, self.sukunimi)

class Tuntipalkkainen(Työntekijä):
    def __init__(self, etunimi, sukunimi, tuntipalkka):
        self.tuntipalkka = tuntipalkka
        super().__init__(etunimi, sukunimi)

    def tulosta_tiedot(self):
        super().tulosta_tiedot()
        print("Tuntipalkka: " + self.tuntipalkka)

def Kuukausipalkkainen(Työntekijä):
    def __init__(self, nimi, sukunimi, kuukausipalkka):
        self.kuukausipalkka = kuukausipalkka
        super().__init__(nimi, sukunimi)

    def tulosta_tiedot(self):
        super().tulosta_tiedot()
        print("Kuukausipalkka: " + self.kuukausipalkka)


työntekijät = []
työntekijät.append(Tuntipalkkainen("Viivi", "Virta", 12.35))
työntekijät.append(Kuukausipalkkainen("Ahmed", "Habib", 2750))
työntekijät.append(Työntekijä("Pekka", "Puro"))
työntekijät.append(Tuntipalkkainen("Olga", "Glebova", 14.92))

for i in työntekijät:
    i.tulosta_tiedot()



























