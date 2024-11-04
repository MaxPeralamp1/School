nimi = input("Kerro nimi: ")
nimet = set()
while True:
    if len (nimi) == 0:
        break
    else:
        if nimi not in nimet:
            print("Uusi nimi.")
            nimet.add(nimi)
        else:
            print("Aiemmin syötetty nimi.")

    nimi = input("Kerro nimi: ")

for x in nimet:
    print(x)
