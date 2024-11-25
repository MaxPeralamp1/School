'use strict';

async function tvmaze(query){
    console.log("start");
    let data;
    try{
        const response =  await fetch('https://api.tvmaze.com/search/shows?q=' + query);
        data = await response.json();
        console.log(data);

    } catch(error) {
        console.log(error.message);

    } finally {
        console.log("end");
    }

    const targetElement = document.getElementById('results');
    targetElement.innerHTML = "";
    for (const key of data) {
        console.log(key);
        const article = document.createElement("article");
        const h2 = document.createElement('h2');
        h2.textContent = key.show.name;
        article.appendChild(h2);
        const a = document.createElement('a');
        a.href = key.show.url;
        a.target = '_blank';
        a.textContent = "linkki";
        article.appendChild(a);
        const img = document.createElement('img');
        img.alt = key.show.name;
        img.src = key.show.image?.medium;
        article.appendChild(img);
        const div = document.createElement('div');
        div.innerHTML = key.show.summary;
        article.appendChild(div);


        targetElement.appendChild(article);
    }



}


const form = document.getElementById('searchQuery');

form.addEventListener('submit', function (event) {
    event.preventDefault();
    const query = document.getElementById('query').value;
    tvmaze(query);
})


