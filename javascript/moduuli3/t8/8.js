'use strict';

const calculate = document.getElementById("start");
calculate.addEventListener("click", function () {
    const num1 = parseInt(document.getElementById("num1").value);
    const num2 = parseInt(document.getElementById("num2").value);
    let result = 0;
    const operation = document.getElementById("operation");
    const resultTarget = document.getElementById("result");
    if (operation.value === "add") {
        result = num1 + num2;
    } else if (operation.value === "sub") {
        result = num1 - num2;
    } else if (operation.value === "multi") {
        result = num1 * num2;
    } else if (operation.value === "div") {
        if (num2 === 0) {
            resultTarget.textContent = "Cannot divide by zero.";
            return;
        }
        result = num1 / num2;
    }
    resultTarget.textContent = result.toString();
})




