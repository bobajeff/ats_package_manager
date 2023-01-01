(* execute_commands_test.dats created by Jeffrey Brusseau on Sun 01 Jan 2023 02:15:20 PM CST *)

#include "share/atspre_define.hats"
#include "share/atspre_staload.hats"

staload STDLIB = "libats/libc/SATS/stdlib.sats"

// --------------CREATE TEST FILE--------------
val out = fileref_open_exn ("hello.dats", file_mode_w)

val () = fprint_string (out, "#include \"share/atspre_define.hats\"\n#include \"share/atspre_staload.hats\"\n\nval () = print \"hello\\n\"\n\nimplement main0 () = ()")
val () = fileref_close (out)

// --------------RUN BUILD COMMAND ON TEST FILE--------------
val () = ignoret($STDLIB.system("patscc hello.dats -o hello && ./hello"))


implement main0 () = ()