let policz a b =
  let rec rec_policz a b =
    match b with
    | 0 -> a
    | _ -> rec_policz (if a mod 10 = 0 then a / 10 else a - 1) (b - 1)
  in rec_policz a b
;;


let (a, b) = Scanf.sscanf (read_line ()) "%d %d" (fun a b -> (a, b)) in
  print_int (policz a b);
  print_newline ()
;;