'use strict';



async function chuck(query){
    console.log("Start");
    let data;
    try{
        const response = await fetch('https://api.chucknorris.io/jokes/search?query=' + encodeURIComponent(query));
        data = await response.json();
        console.log(data.value);

        const targetElement = document.getElementById('results');
        targetElement.innerHTML = "";

        if (data.result && data.result.length > 0) {
            data.result.forEach(joke => {
                const article = document.createElement("article");
                const p = document.createElement("p");
                p.textContent = joke.value;
                article.appendChild(p)
                targetElement.appendChild(article);
            });
        } else {
            const p = document.createElement("p");
            p.textContent = "Not funny.";
            targetElement.appendChild(p);
        }
    } catch(error){
        console.log(error.message);

    } finally{
        console.log("End");
    }



}


const form = document.getElementById('searchQuery');

form.addEventListener('submit', function (event) {
    event.preventDefault();
    const query = document.getElementById('query').value;
    chuck(query);
})