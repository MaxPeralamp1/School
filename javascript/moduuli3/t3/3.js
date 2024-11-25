'use strict';
const names = ['John', 'Paul', 'Jones'];


const targetElement = document.getElementById('target');
        names.forEach((text, index) => {
            const li = document.createElement('li');
            li.textContent = text;


            if (index === 1) {
                li.classList.add('my-item');
            }


            targetElement.appendChild(li);
        });