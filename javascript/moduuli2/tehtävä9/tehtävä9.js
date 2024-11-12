'use strict';

function even(numbers){
    const numbers2 = [];
    for (let i = 0; i < numbers.length; i++) {
        if(numbers[i] % 2 === 0){
            numbers2.push(numbers[i]);
        }
    }
    return numbers2;
}

const numbers = [1, 2, 3, 4, 5, 16];

console.log(numbers, even(numbers));