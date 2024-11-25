'use strict';
const students = [
  {
    name: 'John',
    id: '2345768',
  },
  {
    name: 'Paul',
    id: '2134657',
  },
  {
    name: 'Jones',
    id: '5423679',
  },
];


const targetElement = document.getElementById('target');
        for (const key in students) {
          if (students.hasOwnProperty(key)) {
            const option = document.createElement('option');
            option.textContent = students[key].name;
            option.value = students[key].id;
            targetElement.appendChild(option);
          }
        }
