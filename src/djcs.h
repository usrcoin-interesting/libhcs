#ifndef DJCS_H
#define DJCS_H

#include <gmp.h>
#include "hcs_rand.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    mpz_t g;
    mpz_t *n;
    unsigned long s;
} djcs_public_key;

typedef struct {
    mpz_t j;
    mpz_t lambda;
    mpz_t d;
    mpz_t mu;
    mpz_t *n;
    unsigned long s;
} djcs_private_key;

djcs_public_key*  djcs_init_public_key(void);

djcs_private_key* djcs_init_private_key(void);

int djcs_generate_key_pair(unsigned long s, djcs_public_key *pk,
        djcs_private_key *vk, hcs_rand *hr, unsigned long bits);

void djcs_encrypt(djcs_public_key *pk, hcs_rand *hr, mpz_t rop, mpz_t plain1);

void djcs_decrypt(djcs_private_key *vk, mpz_t rop, mpz_t cipher1);

void djcs_ep_add(djcs_public_key *pk, mpz_t rop, mpz_t cipher1, mpz_t plain1);

void djcs_ee_add(djcs_public_key *pk, mpz_t rop, mpz_t cipher1, mpz_t cipher2);

void djcs_ep_mul(djcs_public_key *pk, mpz_t rop, mpz_t cipher1, mpz_t plain1);

void djcs_free_public_key(djcs_public_key *pk);

void djcs_free_private_key(djcs_private_key *vk);

#ifdef __cplusplus
}
#endif

#endif
