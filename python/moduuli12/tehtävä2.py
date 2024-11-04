import requests
import json

city = input("Kerro kaupungin nimi:")
request = "http://api.openweathermap.org/geo/1.0/direct?q=" + city + "&limit=5&appid=f5ea492bfa0236957697a766a64744d9"

try:
    vastaus = requests.get(request)
    if vastaus.status_code == 200:
        vastaus = vastaus.json()
except requests.exceptions.RequestException as e:
    print ("Hakua ei voitu suorittaa.")



lat = vastaus[0]["lat"]
lon = vastaus[0]["lon"]

request = "https://api.openweathermap.org/data/2.5/weather?lat=" + str(lat) + "&lon=" + str(lon) + "&appid=bdc7fe10eb3021f3fb378f3ca583babd"

try:
    vastaus = requests.get(request)
    if vastaus.status_code == 200:
        vastaus = vastaus.json()
        print(vastaus["weather"][0]["main"])
        print(round(vastaus["main"]["temp"]-273.15, 0))
except requests.exceptions.RequestException as e:
    print ("Hakua ei voitu suorittaa.")
