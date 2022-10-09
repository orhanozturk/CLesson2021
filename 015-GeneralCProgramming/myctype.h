#ifndef MYCTYPE_H
#define MYCTYPE_H

#include <stdint.h>

#define     UPPER      1
#define     LOWER      2
#define     DIGIT      4
#define     XDIGIT     8
#define     SPACE      16
#define     PUNCT      32
#define     PRINT      64
#define     CONTROL    128


extern const uint16_t ctype_[];

#define     is_upper(c)     (ctype_[c] & UPPER)
#define     is_lower(c)     (ctype_[c] & LOWER)
#define     is_digit(c)     (ctype_[c] & DIGIT)
#define     is_alpha(c)     (ctype_[c] & (UPPER | LOWER))
#define     is_alnum(c)     (ctype_[c] & (UPPER | LOWER | DIGIT))
#define     is_xdigit(c)    (ctype_[c] & XDIGIT)
#define     is_punct(c)     (ctype_[c] & PUNCT)
#define     is_space(c)     (ctype_[c] & SPACE)
#define     is_print(c)     (ctype_[c] & PRINT)



#endif // MYCTYPE_H
