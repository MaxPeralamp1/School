'use strict';

async function chuck(){
    console.log("Start");
    let data;
    try{
        const response = await fetch('https://api.chucknorris.io/jokes/random');
        data = await response.json();
        console.log(data.value);
    } catch(error){
        console.log(error.message);

    } finally{
        console.log("End");
    }
}
chuck();