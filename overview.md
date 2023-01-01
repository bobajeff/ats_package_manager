# Overview for making a package manager

- ☑ read directory structor
    - ☐ check for `package.toml` 
        - ☑ read `package.toml` 
        - ☐ parse toml file
        - ☐ check for `[bin]` section
            - ☐ get `name` and `path` if exists
    - ☐ confirm `/src` directory and `main.dats` or `lib.dats`
    - ☐ check for `build.dats`
    - ☐ check for /src/bin
- ☐ check dependencies
    - ☐ check files for `"staload"` lines that are loading `.dats`
- ☐ build dependencies
    - ☑  run build commands in shell
- ☐ build target (bin)
