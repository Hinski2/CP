let (k, n, w) = Scanf.scanf "%d %d %d" (fun a b c -> (a, b, c)) in 
	print_int (max (w * (w + 1) / 2 * k - n) 0)