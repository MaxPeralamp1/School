mitta = float(input("Anna kuhan mitta: "))

if mitta < 37:
    print("Kuha on alimittainen. Pituudesta puuttuu: " + str(37 - mitta) + "cm")
else:
    print("Kuha on sallitussa mitassa")