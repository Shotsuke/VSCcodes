console.log(document);
if(document.nodeType == 9) console.log("Top Node");
var divs = document.getElementsByTagName("div")[0];
console.log(divs);
divs.innerText = "Have Been Modified";

console.log(divs.clientHeight);
console.log(divs.clientWidth);