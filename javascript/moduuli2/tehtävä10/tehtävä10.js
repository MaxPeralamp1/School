'use strict';




const candidatesCount = parseInt((prompt("Kuinka monta osallistujaa:")));

const candidates = [];
for (let i = 1; i < candidatesCount +1; i++){
    const name = prompt(`Nimi ehdokkaalle ${i}:`);
    candidates.push({name: name, votes: 0});
}

console.log(candidates);

const votersCount = parseInt(prompt("Kuinka monta äänestäjää:"));

for (let i = 0; i < votersCount; i++){
    const who = prompt("Ketä äänestät?");
    const candidate = candidates.find(candidate => candidate.name === who);
    if (candidate) {
        candidate.votes += 1;
    }else {
        console.log("Osallistujaa ei vittu ole");
    }
}

candidates.sort((a, b) => b.votes - a.votes);
candidates.forEach(candidate => {
        console.log(`${candidate.name}: ${candidate.votes} ääntä`);
    });

const voittaja = candidates[0];

console.log(`Voittaja on ${voittaja.name}`);
