# Overview for making a package manager

## Basic Plan

- do project in C
- port it to unsafe ATS
    - don't try make use of any standard libraries 
    - keep it as much to the core language as possible. Making libraries if need be along the way.
- learn to make it safe.
    - gradually play with type checking features of ATS

## Requirements
- ☑ read arguments (flags) to the command
    - ☐ check for `run` or `build` flags
    - ☐ check for `--bin` flag
- ☐ read directory structure
    - ☐ check for `package.toml` 
        - ☐ read `package.toml` 
        - ☐ parse toml file
        - ☐ check for `[bin]` section
            - ☐ get `name` and `path` if exists
    - ☐ confirm `/src` directory and `main.dats` or `lib.dats`
    - ☐ check for `build.dats`
        - ☐ validate `build.dats` is compatible with the package manager
    - ☐ check for `/src/bin`
- ☐ build target (bin)
    - ☐  run build commands in shell
    - ☐ build dependencies
        - ☐ create dependency graph
            - ☐ check files for `"staload"` lines that are loading `.dats`
            - ☐ create and run build instructions
            - ☐ execute build instructions
                - ☐ skip over source files that haven't changed since last build
                    where the object file is still present
                - ☐ catch errors in the execution of build commands