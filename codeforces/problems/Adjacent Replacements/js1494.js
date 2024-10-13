process.stdin.resume();
process.stdin.setEncoding("utf-8");
 
let inputString = "";
let currentLine = 0;
 
process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});
 
process.stdin.on("end", (_) => {
    inputString = inputString
        .trim()
        .split("\n")
        .map((string) => {
            return string.trim();
        });
 
    main();
});
 
function readline() {
    return inputString[currentLine++];
}

function main(){
    let n = parseInt(readline());
    let v = readline().split(' ').map(x => parseInt(x));
    v = v.map((x) => (x % 2 == 0) ? x - 1 : x);
    console.log(...v);
}