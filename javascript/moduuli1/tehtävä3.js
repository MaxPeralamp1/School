'use strict';
const num1str = prompt("Anna numero: ");
const num2str = prompt("Anna numero: ");
const num3str = prompt("Anna numero: ");

const num1 = parseInt(num1str);
const num2 = parseInt(num2str);
const num3 = parseInt(num3str);

const sum = num1 + num2 + num3;
const product = num1 * num2* num3;
const average = sum / 3;

document.querySelector('#target').innerHTML = "Summa:" + sum + " Tulo: " + product + " Keskiarvo: " + average;