(* filesystem_operations.dats created by Jeffrey Brusseau on Sat 31 Dec 2022 03:46:53 PM CST *)

#include "share/atspre_define.hats"
#include "share/atspre_staload.hats"
    // better names
#define get_dir_name dirent_get_d_name_gc
#define string_ptr_free strptr_free
    // for reading the directory
staload "libats/libc/SATS/dirent.sats"
staload _ = "libats/libc/DATS/dirent.dats"

// --------------OPEN AND WRITE TO FILE--------------
val out = fileref_open_exn ("package.toml", file_mode_w)

val () = fprint_string (out, "[package]\nname = \"ats_package_manager\"\nversion = \"0.0.1\"\nauthors = [\"Jeffrey Brusseau <bobajeff82@gmail.com>\"]\nedition = \"2021\"")
val () = fileref_close (out)

// --------------READ DIRECTORY----------------------
fun loop (dir_ptr: !DIRptr1) : void = let
  val (proof_optional | dir_entry) = readdir (dir_ptr)
in
    if dir_entry > 0 then let
        prval Some_v @(proof, f_proof) = proof_optional  //f_proof is a proof function?
        val str = get_dir_name (!dir_entry)
        prval () = f_proof (proof)
        val () = if (str != "." && str != "..") then (print! ("\t - ") ; println! (str))
        val () = string_ptr_free (str)
    in
        loop (dir_ptr)
    end else let
        prval None_v () = proof_optional in
    end
end

val () = println! ("files in directory:")
val dir_ptr = opendir_exn (".")
val () = loop (dir_ptr)
val () = closedir_exn (dir_ptr)

// --------------OPEN AND READ FILE------------------
fun loop(stdin_ref: FILEref): void = let
    val isnot = fileref_isnot_eof(stdin_ref)
in
    if isnot then let
        val line = fileref_get_line_string(stdin_ref)
        val () = fprintln!(stdout_ref, line)
        val () = string_ptr_free(line)
    in
        loop(stdin_ref)
    end else ()
end

val () = println! ("\ncontents of package.toml:")
val out = fileref_open_exn ("package.toml", file_mode_r)
val () = loop(out);
val () = fileref_close (out)


implement main0 () = ()