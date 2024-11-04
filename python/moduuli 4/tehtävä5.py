tunnus = str("python")
salasana = str("rules")
yritykset = 0

while True:
    idinput = input("Anna käyttäjätunnus: ")
    pswrdinput = input("Anna salasana: ")
    if yritykset <= 3:
        if (idinput == tunnus and pswrdinput == salasana):
            print("Tervetuloa")
            break
        else:
            print("Väärät tunnukset")
            yritykset += 1
    else:
        print("Pääsy evätty")
        break

