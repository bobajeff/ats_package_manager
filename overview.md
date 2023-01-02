# Overview for making a package manager

- ☑ read arguments (flags) to the command
    - ☐ check for `run` or `build` flags
    - ☐ check for `--bin` flag
- ☑ read directory structure
    - ☐ check for `package.toml` 
        - ☑ read `package.toml` 
        - ☐ parse toml file
        - ☐ check for `[bin]` section
            - ☐ get `name` and `path` if exists
    - ☐ confirm `/src` directory and `main.dats` or `lib.dats`
    - ☐ check for `build.dats`
        - ☐ validate `build.dats` is compatible with the package manager
    - ☐ check for `/src/bin`
- ☐ build target (bin)
    - ☑  run build commands in shell
    - ☐ build dependencies
        - ☐ create dependency graph
            - ☐ check files for `"staload"` lines that are loading `.dats`
            - ☐ create and run build instructions
            - ☐ execute build instructions
                - ☐ skip over source files that haven't changed since last build
                    where the object file is still present
                - ☐ catch errors in the execution of build commands