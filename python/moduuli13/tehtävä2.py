import mysql.connector
from flask import Flask, request, Response
import json


yhteys = mysql.connector.connect(
    host="localhost",
    port=3306,
    database='flight_game',
    user='root',
    password='yuk7whc3ct3wr',
    autocommit=True,
    collation='utf8mb4_general_ci'
)

app = Flask(__name__)
@app.route('/kenttä/<icao>')
def hae_lentokentat(icao):
    try:
        sql = f"SELECT name,municipality FROM airport where IDENT='{icao}'"
        print(sql)
        kursori = yhteys.cursor()
        kursori.execute(sql)
        tulos = kursori.fetchall()
        if kursori.rowcount >0 :
            for rivi in tulos:
                name = rivi[0]
                municipality = rivi[1]
                print(f"Päivää! Olen {rivi[0]}. Sijaitseen {rivi[1]} ")
        vastaus = {
            "ICAO": icao,
            "Name": name,
            "Municipality": municipality,
        }
        tilakoodi = 200
    except ValueError:
        tilakoodi = 400
        vastaus = {
            "status": tilakoodi,
            "teksti": "Virheellinen yhteenlaskettava"
        }
    jsonvast = json.dumps(vastaus)
    return Response(response=jsonvast, status=tilakoodi, mimetype="application/json")

if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=3000)

