use std::io;
use std::collections::HashMap;
use std::iter::{Enumerate, Zip};

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

fn solve(n: i32, q: i32, exts: Vec<String>, mimes: Vec<String>, qs: Vec<String>) {
    let mut table: HashMap<String, String> = HashMap::new();
    
    for (ext, mime) in  exts.iter().zip(mimes.iter()) {
        table.insert(ext.trim().to_lowercase(), mime.to_string());
    }
    
    for q in qs.iter() {
        if !q.contains('.') {
            println!("UNKNOWN");
            continue;
        }

        match q.split('.').last() {
            Some(split) => {
                if let Some(e) = table.get(&split.to_lowercase()) {
                    println!("{e}");
                } else {
                    println!("UNKNOWN")
                }
            }
            None => println!("UNKNOWN")
        }
    }
}

fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32); // Number of elements which make up the association table.
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let q = parse_input!(input_line, i32); // Number Q of file names to be analyzed.

    let (mut exts, mut mimes) = (Vec::new(), Vec::new());
    for i in 0..n as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        let ext = inputs[0].trim().to_string(); // file extension
        let mt = inputs[1].trim().to_string(); // MIME type.

        exts.push(ext);
        mimes.push(mt);
    }

    let mut qs = Vec::new();
    for i in 0..q as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let fname = input_line.trim_matches('\n').to_string(); // One file name per line.
        qs.push(fname);
    }
    
    solve(n, q, exts, mimes, qs); 
}
