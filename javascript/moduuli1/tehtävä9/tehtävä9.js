'use strict';

 const num = parseInt(prompt("Enter an integer:"));

            if (isNaN(num)) {
                document.getElementById("target").innerHTML = "Please enter a valid integer.";
            } else if (num <= 1) {
                document.getElementById("target").innerHTML = `${num} is not a prime number.`;
            } else if (num === 2) {
                document.getElementById("target").innerHTML = `${num} is a prime number.`;
            } else {
                let onPrime = true;
                for (let i = 2; i <= Math.sqrt(num); i++) {
                    if (num % i === 0) {
                        onPrime = false;
                        break;
                    }
                }


            document.getElementById("target").innerHTML = onPrime
                    ? `${num} is a prime number.`
                    : `${num} is not a prime number.`;

        };