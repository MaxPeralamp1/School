//interactive programs
//printing into web page
const nimi = "max";
document.querySelector('#p').innerHTML = nimi;

//changing the types of variables

const int = 10;
//to string
const intStr = int.toString();
//back to int
const backToInt = parseInt(intStr);


///read user input
const userInput = prompt('Tähän voi kirjoitella mitä vaan:');


//conditional expressions
const age = 18;
if(age < 18){
    console.log("Olet alaikäinen");
}

//comparison operators
//equal ===
//different than !=
//greater or smaller > <
//greater or equal >=

//logical operators
const number = prompt('Enter and integer');
if (number % 2 === 0 && number > 10) {
    console.log('You entered an even number greater than 10');
}

if (number % 2 === 0) {
    console.log('You entered an even number');
}
else {
    console.log('You entered an odd number.');
}

//switch

const hyttiluokka = prompt("Kerro hyttiluokka(A/B):");
switch(hyttiluokka){
    case 'A':
        console.log("A luokka");
        break;
    case 'B':
        console.log("B luokka");
        break;
    default:
        console.log("Invalid input");
}

//Loops

//while
let heads = 0, tails = 0;
while (heads + tails < 100){
    const r = Math.random();
    if(r>0.5){
        heads++;
    }else{
        tails++;
    }
}
console.log('Heads: ' + heads + ', tails: ' + tails)

//for loop
for(let i = 1; i<= 10; i++){
    console.log(i);
}

//arrays

const numbers = [17, 2, 8];

//looping an array
const names = ['Frank', 'Scott', 'Jasmine', 'Don'];

for(let i = 0; i < names.length; i++){
    console.log(names[i]);
}

//for-of
for(const name of names){
    console.log(name);
}

//object literals
const student = {
  firstName: 'Greg',
  lastName: 'Focker',
  studentId: '234359',
  phone: '040 5902123',
}

const greeting = ('Hello, my name is' + student.firstName + student.lastName);
const studentInfo = `student number: ${student['studentId']}, phone number: ${student['phone']}`

student.address = 'Schoolroad 7';  // adds 'address' property to previous example
delete student.phone;              // deletes 'phone' propertt from previous example
console.log(student);

const chosenProperty = "lastName";
console.log(student[chosenProperty]);

const student2 = {
      firstName: 'Ahmed',
      lastName: 'Hussein',
      credits :175,
      hasLeft: function() {return 240-this.credits}
    }

console.log("Student " + student2.firstName + " is missing " + student2.hasLeft() + " credits.");


//functions


const n1 = 3; // global variable

function hello() {
    var n2 = 5; // an internal variable of a function

    if (n2>0) {
        const n3 = 8; // an internal variable of a block
        var n4 = 9; // an internal variable of a function
    }
    console.log(n1); // global variable is visible everywhere
    console.log(n2); // the internal variable is aviailable inside the function
    //console.log(n3); -- an internal variable of a block is not available outside the function
    console.log(n4); // the internal variable of the function is available inside the function

}

hello();

console.log(n1); // the global variable is visible everywhere
//console.log(n2); -- the function's internal variable does not appear outside the function
//console.log(n3); -- the internal variable of a block does not appear outside the block
//console.log(n4); -- the function's internal variable does not appear outside the function


//array as parameter
function grow(array) {
    for (let i = 0; i<array.length; i++) {
        array[i]++;
    }
    return;
}

const numberss = [5,6,7];
grow(numberss);
console.log(numberss[0] + ' ' + numberss[1] + ' ' + numberss[2]);



//arrow functions
const neliojuuri = (a, b) => (a*a + b*b);
console.log(neliojuuri(2, 5));





































