import mysql.connector

yhteys = mysql.connector.connect(
    host="localhost",
    port=3306,
    database='flight_game',
    user='max',
    password='vittu',
    autocommit=True,
    collation='utf8mb4_general_ci'
)

def hae_lentokentat(country):
    sql = f"SELECT name,municipality FROM airport where IDENT='{country}'"
    print(sql)
    kursori = yhteys.cursor()
    kursori.execute(sql)
    tulos = kursori.fetchall()
    if kursori.rowcount >0 :
        for rivi in tulos:
            print(f"Päivää! Olen {rivi[0]}. Sijaitseen {rivi[1]} ")
    return

icao = input("anna ICAO koodi: ")
hae_lentokentat(icao)
