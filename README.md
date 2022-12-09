# Implementaion of RISC-V Out-of-Order superscalar pipeline.

[![CircleCI](https://circleci.com/gh/koyamanX/turboV/tree/develop.svg?style=svg)](https://circleci.com/gh/koyamanX/turboV/tree/develop)

## Prerequisite
- Installation of Docker
- Development container image for strom
```bash
$ pushd image
$ ./build.sh # This will take a while
$ popd
$ ./run.sh # Now, you can enter development container 
```

## Integration Test
```bash
./run.sh
mkdir build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=./
make
make install
make test
```

## Specification
- The RISC-V Instruction Set Mannual Volume I: Unprivileged ISA
  - Document Version 20191213
- The RISC-V Instruction Set Mannual Volume II: Privileged ISA
  - Document Version 20211203

## Important Notes
- This project is still work in progress
