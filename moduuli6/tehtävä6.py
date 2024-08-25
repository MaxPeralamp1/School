import math
def pizza(halkaisija, euro):
    säde = halkaisija / 2
    pinta_ala = math.pi * (säde * säde)
    neliö = pinta_ala / 10000
    neliöhinta = euro / neliö

    return neliöhinta


pizza1cm = float(input("Kerro pizzan halkaisija cm: "))
pizza1euro = float(input("Kerro pizzan hinta euroina: "))
pizza2cm = float(input("Kerro toisen pizzan halkaisija cm: "))
pizza2euro = float(input("Kerro toisen pizzan hinta euroina: "))


if pizza(pizza1cm, pizza1euro) > pizza(pizza2cm, pizza2euro):
    print("Toinen pizza oli edullisempi, " + str(pizza(pizza2cm, pizza2euro)) + " euroa neliömetri")
elif pizza(pizza2cm, pizza2euro) > pizza(pizza1cm, pizza1euro):
    print("Ensimmäinen pizza oli edullisempi, " + str(pizza(pizza1cm, pizza1euro)) + " euroa neliömetri")


