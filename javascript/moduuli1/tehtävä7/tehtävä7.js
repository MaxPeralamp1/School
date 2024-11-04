'use strict';

const throwsStr = prompt('Kerro kuinka monta kertaa noppaa heitetään: ')
const throws = parseInt(throwsStr);

function getRandomInt(max){
    return Math.floor(Math.random() * max);
}
let summa = 0;
let heitto = 0;
for (let i = 0; i < throws; i++) {
    heitto = getRandomInt(6) + 1;
    summa = heitto + summa;
    console.log(heitto);
}

document.querySelector('#target').innerHTML = "Heittojen summa on: " + summa;
