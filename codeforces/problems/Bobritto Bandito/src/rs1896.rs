// Template
use std::io::{self, Read};
use std::str::FromStr;

pub struct Scanner {
    buff: Vec<u8>,
    idx: usize,
}

impl Scanner {
    pub fn new() -> Self {
        let mut input = String::new();
        io::stdin().read_to_string(&mut input).unwrap();
        Self {buff: input.into_bytes(), idx: 0}
    }

    pub fn read<T: FromStr>(&mut self) -> T 
    where 
        T::Err: std::fmt::Debug
    {
        while self.idx < self.buff.len() && self.buff[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }

        let start = self.idx;
        while self.idx < self.buff.len() && !self.buff[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }

        unsafe {
            std::str::from_utf8_unchecked(&self.buff[start..self.idx])
        }
        .parse::<T>()
        .unwrap()
    }

    pub fn read_vec<T: FromStr>(&mut self, n: usize) -> Vec<T>
    where
        T::Err: std::fmt::Debug,
    {
        (0..n).map(|_| self.read()).collect()
    }
}

///  scan!(sc, a, b, c);
#[macro_export]
macro_rules! scan {
    ($sc:expr, $($var:ident),+ $(,)?) => { $( let $var = $sc.read::<_>(); )+ };
}

///  scan_as!(sc, i64; n, m, k);
#[macro_export]
macro_rules! scan_as {
    ($sc:expr, $t:ty; $($var:ident),+ $(,)?) => { $( let $var: $t = $sc.read(); )+ };
}

#[macro_export]
macro_rules! out {
    ($($x:expr),+ $(,)?) => {
        {
            use std::io::{Write, stdout};
            let mut stdout = stdout().lock();
            let mut first = true;
            $(
                for item in $x {
                    if !first { write!(stdout, " ").unwrap(); }
                    write!(stdout, "{}", item).unwrap();
                    first = false;
                }
            )+
            writeln!(stdout).unwrap();
        }
    };
}
// Template


use std::cmp;
fn solve(sc: &mut Scanner) {
    scan_as!(sc, i32; n, m, l, r);
    let a = cmp::min(-l, m);
    let b = cmp::min(r, m - a);

    out!([-a, b]);
}

fn main() {
    // get input 
    let mut sc = Scanner::new();
    scan!(sc, t);
    for _ in 0..t {
        solve(&mut sc);
    }
}
