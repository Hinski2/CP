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

function solve(){
    let n = parseInt(readline())
    let v = new Array(n);
    v = [...v.keys()].map((x) => x + 1);
    for(let i = (n % 2) ? 1 : 0; i < n; i += 2){
        let a = v[i], b = v[i + 1];
        v[i] = b, v[i + 1] = a;
    }
    console.log(...v)
}

    

function main(){
    let t = parseInt(readline())
    while(t--)
        solve();
}