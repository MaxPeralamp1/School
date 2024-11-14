from flask import Flask, request, Response
import json

app = Flask(__name__)
@app.route('/alkuluku/<alkuluku>')
def alkuluku():
    try:
        args = request.args
        alkuluku = args['alkuluku']
        if alkuluku <= 1:
            print(f"{alkuluku} is not a prime number.")
        elif alkuluku <= 3:
            print(f"{alkuluku} is a prime number.")
        elif alkuluku % 2 == 0 or alkuluku % 3 == 0:
            print(f"{alkuluku} is not a prime number.")
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
    except ValueError:
        tilakoodi = 400
        vastaus = {
            "status": tilakoodi,
            "teksti": "Virheellinen yhteenlaskettava"
        }
    jsonvast = json.dumps(vastaus)
    return Response(response=jsonvast, status=tilakoodi, mimetype="application/json")



if __name__ == '__main__':
    app.run(use_reloader=True, host='0.0.0.0', port=8080)