let displaySum = document.querySelector("#sum");
let addBtn = document.querySelector("#addBtn");

function sum() {
    let a = parseInt(document.querySelector("#a").value);
    let b = parseInt(document.querySelector("#b").value);
    
    displaySum.innerHTML = a + b;
    console.log(a + b);
}

addBtn.addEventListener("click", sum);
