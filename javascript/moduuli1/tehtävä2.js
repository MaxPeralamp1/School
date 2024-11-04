'use strict';
const name = prompt('Kirjoita nimesi');
console.log("Hauska tavata" + name);
document.querySelector('#target').innerHTML = "Hauska tavata " + name;
