# ebpf_decoder

This repository is created to learn:
1. How to use GitHub issue.
2. How to use [Meson](https://github.com/mesonbuild/meson).
3. How to use [Ninja](https://github.com/ninja-build/ninja).
4. How to parse eBPF instruction via C++.

## Usage

Build libbpf at first.
```
cd submodule/libbpf/src
make
```

Then build this program.
```
# cd ../../..
make
```

Execute.
```
./build/ebpf_decoder <eBPF object file>
```

## Lisence
Copyright (c) 2024 Yuji YAMADA
This software is released under the MIT License, see [LICENSE](./LICENSE).
