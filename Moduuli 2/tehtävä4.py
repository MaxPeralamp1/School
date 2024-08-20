import math
import statistics
luku1 = input("Anna luku 1: ")
luku2 = input("Anna luku 2: ")
luku3 = input("Anna luku 3: ")

summa = int(luku1) + int(luku2) + int(luku3)
tulo = int(luku1) * int(luku2) * int(luku3)
keskiarvo = statistics.mean([int(luku1), int(luku2), int(luku3)])

print("Lukujen summa on " + str(summa) + " , tulo " + str(tulo) + " , ja keskiarvo " + str(keskiarvo))