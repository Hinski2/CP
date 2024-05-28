let rec wczytaj n acc =
  match n with
  | 0 -> List.rev acc
  | _ -> wczytaj (n - 1) ((Scanf.scanf " %d" (fun a -> a)) :: acc)
;;

let rec get_kth xs k = 
    match k with
    | 1 -> List.hd xs 
    | _ -> get_kth (List.tl xs) (k - 1)
;;

let int_of_bool = function
    | false -> 0
    | true -> 1
;;

let policz m xs = 
    let rec itr acc xs =
        match xs with 
        | [] -> acc
        | h::t -> itr (acc + int_of_bool(h >= m && h != 0)) t
    in itr 0 xs
;;

let (n, k) = Scanf.sscanf (read_line ()) "%d %d" (fun a b -> (a, b)) in 
  let xs = List.rev (List.sort compare (wczytaj n [])) in 
  let kx = get_kth xs k in 
  print_int (policz kx xs)




