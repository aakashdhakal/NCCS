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
