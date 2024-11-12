'use strict';

const dogs = []

for (let i = 0; i < 6; i++){
    const dog = prompt("Kerro koira:");
    dogs.push(dog);
}

dogs.sort();
dogs.reverse();

for(let dog of dogs){
    const li = document.createElement("li");
    li.innerHTML = dog
    ul.appendChild(li);
}
