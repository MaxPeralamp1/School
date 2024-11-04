import mysql.connector
from geopy.distance import geodesic as GD

lista = []
yhteys = mysql.connector.connect(
    host="localhost",
    port=3306,
    database='flight_game',
    user='max',
    password='vittu',
    autocommit=True,
    collation='utf8mb4_general_ci'
)

def etäisyys(icao, icao1):
    sql = f"SELECT * FROM airport where IDENT='{icao}' OR IDENT='{icao1}'"
    print(sql)
    kursori = yhteys.cursor()
    kursori.execute(sql)
    tulos = kursori.fetchall()
    if kursori.rowcount >0 :
        for rivi in tulos:
            lista.append(rivi[4])
            lista.append(rivi[5])
    location1 = (lista[0], lista[1])
    location2 = (lista[2], lista[3])
    print("The distance between location1 and location2 is: ", GD(location1, location2).km, "km")
    return

icao = input("anna ICAO koodi: ")
icao1 = input("anna toinen ICAO koodi: ")
etäisyys(icao, icao1)
