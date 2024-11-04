def galtoliter(gal):
    liter = gal * 3.785
    return liter

gal = float(input("Kerro gallonat: "))

while gal >= 0:
    print(galtoliter(gal))
    gal = float(input("Kerro gallonat: "))