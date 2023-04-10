#ifndef _CRYPTO_H_
#define _CRYPTO_H_


/**
 * Cypher / Uncypher a message using the Caeser cipher algorithm.
 *
 * @param[in]  msg        Message to cipher/uncipher.
 * @param[in]  decalage   Number of digits to shift.
 * @param[out] out        Result of the treatment.
 *
 * @return  0 - No error.
 *         -1 - Bad parameters.
 */
int caesar_cypher( const char* msg, int decalage, char* out );


#endif
