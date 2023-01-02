(* don't compile this! it's only a note!*)
// What does natLte mean?
    // I think `Lte` means less than or equal to and `nat` means natural number
typedef natLte (n:int) = intBtwe (0, n)
typedef intBtwe (lb:int, ub:int) = g1intBtwe (int_kind, lb, ub)
// lb = 0 ub = n
typedef g1intBtwe (tk:tk, lb:int, ub:int) = [i: int | lb <= i; i <= ub] g1int (tk, i)
// `i` is between `lb` and `ub` (Btwe must stand for between, lb = lower bound ; ub = upper bound)
stadef g1int = g1int_int_t0ype 
abst@ype g1int_int_t0ype (tk:tkind, int) = g0int (tk)
// tk is tkind
sortdef tk = tkind

// -------------------------
tkindef int_kind = "atstype_int"

// looks like the type natLte(n) has to be a number less than or equal to n and of kind "atstype_int"