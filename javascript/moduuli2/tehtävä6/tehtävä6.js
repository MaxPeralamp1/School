'use strict';

function dice(){
    function getRndInteger(min, max) {
    return Math.floor(Math.random() * (max - min) ) + min;
    }
    const num = getRndInteger(1, 7);
    console.log(num);
    return num;
}

while (true){
    if (dice() == 6){
        break;
    }
}