vuosi = int(input("Kerro vuosiluku: "))

tulos = vuosi / 4
sadalla = vuosi / 100
sadalla4 = vuosi / 400

if sadalla.is_integer():
    if sadalla4.is_integer():
        print(">Vuosi on karkausvuosi")
    else:
        print("Vuosi ei ole karkausvuosi")
elif tulos.is_integer():
    print("Vuosi on karkausvuosi")
else:
    print("Vuosi ei ole karkausvuosi")