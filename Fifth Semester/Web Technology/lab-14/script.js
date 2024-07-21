let alertBtn = document.getElementById("alertBtn");
let confirmBtn = document.getElementById("confirmBtn");
let promptBtn = document.getElementById("promptBtn");

console.log(alertBtn)

alertBtn.addEventListener("click", function(){
    alert("This is alert!!");
})
confirmBtn.addEventListener("click", function(){
    confirm("Are you sure you want to continue?")
})
promptBtn.addEventListener("click", function(){
    prompt("Enter your message")
})

let displaySum = document.querySelector("#sum");
let addBtn = document.querySelector("#addBtn");

function sum() {
    let a = parseInt(document.querySelector("#a").value);
    let b = parseInt(document.querySelector("#b").value);
    
    displaySum.innerHTML = "Sum = "+ (a + b);
}

addBtn.addEventListener("click", sum);


document.querySelector("#name").innerText = "Aakash Dhakal";
