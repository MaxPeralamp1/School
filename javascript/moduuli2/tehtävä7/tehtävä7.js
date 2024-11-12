'use strict';

function dice(sides){
    function getRndInteger(min, max) {
    return Math.floor(Math.random() * (max - min) ) + min;
    }
    const num = getRndInteger(1, sides + 1);
    console.log(num);
    return num;
}

const sides = parseInt(prompt("Kuinka monta kylkeä nopalla on: "));
while (true){
    if (dice(sides) == sides){
        break;
    }
}