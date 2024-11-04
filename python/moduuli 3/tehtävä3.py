suku = input("sukupuoli mies tai nainen:")
hemoglobiini = int(input("hemoglobiini (g/l):"))

if(suku == "mies"):
    if(hemoglobiini >= 134 and hemoglobiini <= 195):
        print("Sun hemoglobiini on normaali")
    elif(hemoglobiini > 195):
        print("Sun hemoglobiini on korkea")
    elif(hemoglobiini < 134):
        print("Sun hemoglobiini on alhainen")


if(suku == "nainen"):
    if(hemoglobiini >= 117 and hemoglobiini <= 175):
        print("Sun hemoglobiini on normaali")
    elif(hemoglobiini > 175):
        print("Sun hemoglobiini on korkea")
    elif(hemoglobiini < 117):
        print("Sun hemoglobiini on alhainen")