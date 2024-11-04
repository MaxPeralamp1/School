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
#, count(*) as maara
def hae_lentokentat(country):
    sql = f"SELECT type, COUNT(type) AS maara FROM airport where iso_country='{country}'GROUP by type asc"
    print(sql)
    kursori = yhteys.cursor()
    kursori.execute(sql)
    tulos = kursori.fetchall()
    if kursori.rowcount >0 :
        for rivi in tulos:
            print(f"Olen {rivi[0]}. Määrä {rivi[1]} ")
    return

country = input("anna maakoodi: ")
hae_lentokentat(country)