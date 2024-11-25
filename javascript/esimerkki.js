'use strict';

// kartta näkyviin
const map = L.map('map').setView([60.2, 24.9], 9);

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
  maxZoom: 19,
  attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>',
}).addTo(map);

const lomake = document.querySelector('form');
const hakusana = document.querySelector('input');
const tiedot = document.querySelector('#tiedot');
const markers = L.featureGroup().addTo(map);

lomake.addEventListener('submit', async function(evt) {
  evt.preventDefault();
  const APIkey = '7bfbeb2ebaec8cdb59103f744a3e8c1f';
  const kaupunki = hakusana.value;
  try {
    const weather = await fetchWeather(APIkey, kaupunki);
    // otsikko
    const otsikko = document.createElement('h3');
    otsikko.innerText = weather.name;
    // lämpötila
    const lampo = document.createElement('p');
    lampo.innerText = `Lämpötila: ${weather.main.temp}°C`;
    // tuulen nopeus ja suunta
    const tuulenNopeus = document.createElement('p');
    tuulenNopeus.innerText = `Tuulen nopeus: ${weather.wind.speed} m/s`;
    // säätila kuvana
    const ikoninOsoite = `https://openweathermap.org/img/wn/${weather.weather[0].icon}.png`;
    const ikoni = document.createElement('img');
    ikoni.alt = weather.weather[0].description;
    ikoni.src = ikoninOsoite;
    otsikko.appendChild(ikoni);
    // kootaan tiedot samaan paikkaan
    const kaikkiTiedot = document.createElement('article');
    kaikkiTiedot.append(otsikko, lampo, tuulenNopeus);
    // tyhjennetään vanhat tiedot ensin
    markers.clearLayers();
    // tiedot.innerHTML = '';
    // tiedot.appendChild(kaikkiTiedot);
    // keskitä kartta
    map.setView([weather.coord.lat, weather.coord.lon], 9);
    const marker = L.marker([weather.coord.lat, weather.coord.lon]).addTo(map);
    markers.addLayer(marker);
    marker.bindPopup(kaikkiTiedot);
    marker.openPopup();

  } catch (error) {
    console.error(error.message);
  }
});

async function fetchWeather(APIkey, kaupunki) {
  const request = `https://api.openweathermap.org/data/2.5/weather?appid=${APIkey}&units=metric&q=${kaupunki}`;
  const response = await fetch(request);
  if (!response.ok) {
    throw new Error('Server not found');
  }
  return await response.json();
}







<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.9.4/dist/leaflet.css"
          integrity="sha256-p4NxAoJBhIIN+hmNHrzRCf9tD/miZyoHS5obTRR9BMY="
          crossorigin=""/>
    <link rel="stylesheet" href="esim.css">

    <script src="https://unpkg.com/leaflet@1.9.4/dist/leaflet.js"
            integrity="sha256-20nQCchB9co0qIjJZRGuk2/Z9VM+kNiyxNV1lvTlZBo="
            crossorigin=""></script>
    <script src="esim.js" defer></script>
</head>
<body>
<h1>Esimerkki</h1>
<div class="lomake">
    <form>
        <input type="text" name="kaupunki" placeholder="Syötä kaupunki">
        <button type="submit">Hae</button>
    </form>
</div>
<div id="map"></div>
<div id="tiedot"></div>
</body>
</html>


#map {
    height: 180px;
}


