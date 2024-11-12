'use strict';

const amount = parseInt(prompt("Number of participants: "));

const participants = [];

for (let i = 0; i < amount; i++){
    const name = prompt("Kerro nimi:");
    participants.push(name);
}

participants.sort();
const ol = document.getElementById('ol');

for (let i = 0; i < amount; i++){
    const li = document.createElement("li");
    li.innerHTML = participants[i]
    ol.appendChild(li);
}

