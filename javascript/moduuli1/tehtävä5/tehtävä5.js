'use strict';

const vuosiStr = prompt("Kerro vuosiluku: ")
const vuosi = parseInt(vuosiStr);

if(vuosi % 4 === 0){
    document.querySelector('#target').innerHTML = "Vuosi on karkausvuosi";
} else if (vuosi % 100 === 0){
    if(vuosi % 400 === 0){
        document.querySelector('#target').innerHTML = "Vuosi on karkausvuosi";
    }
} else {
    document.querySelector('#target').innerHTML = "Vuosi ei ole karkausvuosi";
}




