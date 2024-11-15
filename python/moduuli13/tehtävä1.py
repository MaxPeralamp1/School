from flask import Flask, request, Response
import json

app = Flask(__name__)
@app.route('/alkuluku/<number>')
def alkuluku(number):
    try:
        alkuluku = int(number)
        if alkuluku <= 1:
            print(f"{alkuluku} is not a prime number.")
            is_prime = False
        elif alkuluku <= 3:
            print(f"{alkuluku} is a prime number.")
            is_prime = True
        elif alkuluku % 2 == 0 or alkuluku % 3 == 0:
            print(f"{alkuluku} is not a prime number.")
            is_prime = False
        else:
            i = 5
            is_prime = True
            while i * i <= alkuluku:
                if alkuluku % i == 0 or alkuluku % (i + 2) == 0:
                    is_prime = False
                    break
                i += 6

        vastaus = {
            "number" : alkuluku,
            "isprime" : is_prime,
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
    #