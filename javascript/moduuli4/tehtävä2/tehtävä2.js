'use strict';

async function tvmaze(query){
    console.log("start");
    try{
        const response =  await fetch('https://api.tvmaze.com/search/shows?q=' + query);
        const data = await response.json();
        console.log(data);

    } catch(error) {
        console.log(error.message);

    } finally {
        console.log("end");
    }
}


const form = document.getElementById('searchQuery');

form.addEventListener('submit', function (event) {
    event.preventDefault();
    const query = document.getElementById('query').value;
    tvmaze(query);
})