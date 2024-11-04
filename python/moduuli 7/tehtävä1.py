kuukausi = int(input("Kerro kuukauden numero(1-12): "))
vuodenajat = ("talvi", "kevät" , "kesä", "syksy")

if kuukausi in (12, 1, 2):
    vuodenaika = vuodenajat[0]
    print(f"Kuukausi numero {kuukausi} kuuluu vuodenaikaan {vuodenaika}")
elif kuukausi in (3,4 , 5):
    vuodenaika = vuodenajat[1]
    print(f"Kuukausi numero {kuukausi} kuuluu vuodenaikaan {vuodenaika}")
elif kuukausi in (6,7,8):
    vuodenaika = vuodenajat[2]
    print(f"Kuukausi numero {kuukausi} kuuluu vuodenaikaan {vuodenaika}")
elif kuukausi in (9,10,11):
    vuodenaika = vuodenajat[3]
    print(f"Kuukausi numero {kuukausi} kuuluu vuodenaikaan {vuodenaika}")