import math
leiviskä = float(input("Anna leiviskät:"))
naula = float(input("Anna naulat:"))
luoti = float(input("Anna luodit:"))

massa = luoti * 13.3 + naula * 32 * 13.3 + leiviskä * 20 * 32 * 13.3

print(massa)

kilot = massa / 1000

grammat1 = math.trunc(kilot) * 1000
grammat2 = massa - grammat1
grammatvastaus = str(grammat2)
grammatvastaus.split(".")


print(f"Massa nykymittojen mukaan:\n" + str(math.trunc(kilot)) + " kilogrammaa ja " + grammatvastaus[0:6] + " grammaa")