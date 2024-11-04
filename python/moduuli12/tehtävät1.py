import requests
import json

pyyntö = "https://api.chucknorris.io/jokes/random"


try:
    vastaus = requests.get(pyyntö)
    if vastaus.status_code == 200:
        vastaus = vastaus.json()
        print(json.dumps(vastaus, indent=2))
        print(vastaus["value"])
except requests.exceptions.RequestException as e:
    print ("Hakua ei voitu suorittaa.")