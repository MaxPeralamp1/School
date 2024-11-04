'use strict';

let aloitusvuosi = parseInt(prompt('Kerro aloitusvuosi'));
let lopetusvuosi = parseInt(prompt('Kerro lopetusvuosi'));

const ul = document.getElementById('ul');

for (;aloitusvuosi <= lopetusvuosi; aloitusvuosi++) {
    const li = document.createElement("li");
    if(aloitusvuosi % 4 === 0){
        console.log(aloitusvuosi);
        li.innerHTML = aloitusvuosi.toString();
        ul.appendChild(li);
    } else if (aloitusvuosi % 100 === 0){
        if(aloitusvuosi % 400 === 0){
            console.log(aloitusvuosi);
            li.innerHTML = aloitusvuosi.toString();
            ul.appendChild(li);
    }
}
}

