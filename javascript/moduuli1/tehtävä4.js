'use strict';

function getRandomInt(max){
    return Math.floor(Math.random() * max);
}

const nimi = prompt("Kerro nimesi: ");

const house = getRandomInt(4);


if (house == 0){
    document.querySelector('#target').innerHTML = nimi + " olet Gryffindor";
} else if (house == 1){
    document.querySelector('#target').innerHTML = nimi + " olet Slytherin";
} else if (house == 2){
    document.querySelector('#target').innerHTML = nimi + " olet Hufflepuff"
} else if (house == 3){
    document.querySelector('#target').innerHTML = nimi + " olet Ravenclaw";
}
