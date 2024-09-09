syöte = int(input("\nHaluatko 1: tallena uusi lentoasema, 2: hakea lentoaseman, 3: lopettaa "))
lentoasemat = {}

while syöte != 3:
    if syöte == 1:
        airfield_icao = input("Anna lentokentän icao-koodi:")
        airfield_name = input("Anna lentokentän nimi:")
        if airfield_icao in lentoasemat:
            print("Lentoasema on jo olemassa")
        elif airfield_icao not in lentoasemat:
            lentoasemat[airfield_icao] = airfield_name

    if syöte == 2:
        airfield_icao = input("Anna lentokentän icao-koodi:")
        for icao in lentoasemat:
            if icao == airfield_icao:
                print(f"Lentoaseman nimi on {lentoasemat[icao]}")
    if airfield_icao not in lentoasemat:
        print("Lentokenttää ei ole olemassa.")
    syöte = int(input("\nHaluatko 1: tallena uusi lentoasema, 2: hakea lentoaseman, 3: lopettaa "))