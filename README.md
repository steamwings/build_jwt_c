# build_jwt_c

A one-function, POC library using [libjwt](https://github.com/benmcollins/libjwt)

First, run

```sh
brew install libjwt
```

### Build a library file

```sh
/usr/bin/clang -shared -fcolor-diagnostics -fansi-escape-codes -I./inc -I/opt/homebrew/Cellar/libjwt/1.16.0/include -L/opt/homebrew/Cellar/libjwt/1.16.0/lib -ljwt -g ./src/build_jwt.c -o ./out/build_jwt.so
```

### Demo it

[main.c](./src/main.c) is a demo. For a local build, try

```sh
/usr/bin/clang -fcolor-diagnostics -fansi-escape-codes -I./inc -I/opt/homebrew/Cellar/libjwt/1.16.0/include -L/opt/homebrew/Cellar/libjwt/1.16.0/lib -ljwt -g ./src/*.c -o ./out/main
```

and then `./out/main` should print something like this

```sh
returned: 0
hmacAuth: eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJpYXQiOiIxNjk1Njc1MDQ5Iiwic3ViIjoiMTIzNCJ9.JVHctlGx2WxWjr7ePRI8zCc2mgz0ek6aiYfkPth3fFMzqcdli1I4M0iFZ5hP-dWsX0aFCWvz2ETFfNw0jxW9Ew
```

(You can verify the signature at e.g. [jwt.io](https://jwt.io))

### Formatting

`brew install clang-format`
