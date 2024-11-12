'use strict';

const nums = [];
while(true){
    const num = parseInt(prompt("Anna numero:"))

    if (num == 0){
        break
    }

    nums.push(num);

}

nums.sort((a,b) => b-a);

for(let x of nums){
    console.log(x);
}