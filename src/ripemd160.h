// Copyright (c) 2014-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_RIPEMD160_H
#define BITCOIN_CRYPTO_RIPEMD160_H

#include <stdint.h>

typedef uint32_t size_t;

void memcpy (void *dst, const void *src, size_t len) {
    auto p = static_cast <char *> (dst);
    auto q = static_cast <const char *> (src);
    do {
        * p ++ = * q ++;
    } while (-- len);
}

/** A hasher class for RIPEMD-160. */
class CRIPEMD160
{
private:
    uint32_t s[5];
    unsigned char buf[64];
    uint64_t bytes{0};

public:
    static const size_t OUTPUT_SIZE = 20;

    CRIPEMD160();
    CRIPEMD160& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CRIPEMD160& Reset();
};

void __attribute__((export_name("RIPEMD160"))) RIPEMD160 (const unsigned char* data, unsigned char *hash) {
    CRIPEMD160 RIPEMD160;
    RIPEMD160.Write (data, hash - data);
    RIPEMD160.Finalize (hash);
}

#endif // BITCOIN_CRYPTO_RIPEMD160_H
