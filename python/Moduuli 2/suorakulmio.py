kanta1 = input("Kerro suorakulmion kannan pituus: ")
korkeus1 = input("Kerro suorakulmion korkeus: ")

kanta = float(kanta1)
korkeus = float(korkeus1)

piiri = kanta * 2 + korkeus * 2
pinta_ala = kanta * korkeus

print("Suorakulmion piiri on " + str(piiri) + (" ja pinta-ala on ") + str(pinta_ala))
