'use strict';


function concat(array){
    let result = "";
    for (let i = 0; i < array.length; i++){
        result += array[i]
    }
    document.querySelector('#target').innerHTML = result;
}

const names = ['Johnny', 'Deedee,', 'Joey', 'Marky'];
concat(names);


