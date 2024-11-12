'use strict';

const numbers = new Set();

while (true) {
  const input = prompt("Syötä numero:");
  const num = parseFloat(input);

  if (numbers.has(num)) {
    console.log("Tämä numero on jo syötetty, lopetetaan ohejlma");
    break;
  } else {
    numbers.add(num);
  }
}

const sortedNumbers = Array.from(numbers).sort((a, b) => a - b);
console.log("Numbers entered in ascending order:", sortedNumbers);
