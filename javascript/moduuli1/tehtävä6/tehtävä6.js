'use strict';

const answer = confirm("Should I calculate the square root?");

if (answer) {
   const lukuStr = prompt("Anna luku: ");
   const luku = parseInt(lukuStr);

   if(luku >= 0){
       let x = Math.sqrt(luku);
        document.querySelector('#target').innerHTML = "The square root is " + x;

   } else if (luku < 0){
       document.querySelector('#target').innerHTML = "The square root of a negative number is not defined";
   }

} else{
     document.querySelector('#target').innerHTML = "The square root is not calculated.";
}