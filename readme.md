# RIPEMD160 WASM

RIPEMD160 implementation extracted from [Bitcoin Core](https://github.com/bitcoin/bitcoin/blob/master/src/crypto/ripemd160.cpp) and compiled to WebAssembly.

## Usage
```js
import {ripemd160} from 'https://bitvm.github.io/ripemd160/ripemd160.js'

const preimage = new Uint8Array([97, 98, 99])    // Our preimage is "abc"
const digest = ripemd160(preimage)

console.log(digest)
```


## Development
The following command compiles the sources to wasm:
```sh
clang src/ripemd160.cpp --no-standard-libraries --target=wasm32 -Wl,--no-entry -o ripemd160.wasm
```
