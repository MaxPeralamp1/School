'use strict';

const calculate = document.getElementById("start");
calculate.addEventListener("click", function () {
    const calculation = document.getElementById("calculation").value;

    let num1, num2, operator, result;

    const resultTarget = document.getElementById("result");
    if (calculation.includes("+")) {
        [num1, num2] = calculation.split('+').map(Number);
        operator = "+";
    } else if (calculation.includes("-")) {
        [num1, num2] = calculation.split('-').map(Number);
        operator = "-";
    } else if (calculation.includes("*")) {
        [num1, num2] = calculation.split('*').map(Number);
        operator = "*";
    } else if (calculation.includes("/")) {
        [num1, num2] = calculation.split('/').map(Number);
        operator = "/";
    }
    if (isNaN(num1) || isNaN(num2)) {
        resultTarget.textContent = "Invalid numbers. Please provide integers.";
        return;
    }
    switch (operator) {
        case "+":
            result = num1 + num2;
            break;
        case "-":
            result = num1 - num2;
            break;
        case "*":
            result = num1 * num2;
            break;
        case "/":
            result = num1 / num2;
            break;
        default:
            resultTarget .textContent = "Unexpected error.";
            return;
    }

    resultTarget.textContent = `Result: ${result}`;
})
