/*	$OpenBSD: strtoimax.c,v 1.1 2006/01/13 17:58:09 millert Exp $	*/
/*-
* Copyright (c) 1992 The Regents of the University of California.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 3. Neither the name of the University nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
*/
#include "ctype.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
/*
* Convert a string to an intmax_t
*
* Ignores `locale' stuff.  Assumes that the upper and lower case
* alphabets and digits are each contiguous.
*/
int strtoimax(const char *nptr, char **endptr, int base)
{
	const char *s;
	int acc, cutoff;
	int c;
	int neg, any, cutlim;
	/*
	* Skip white space and pick up leading +/- sign if any.
	* If base is 0, allow 0x for hex and 0 for octal, else
	* assume decimal; if base is already 16, allow 0x.
	*/
	s = nptr;
	do {
		c = (unsigned char)*s++;
	} while (isspace(c));
	if (c == '-') {
		neg = 1;
		c = *s++;
	}
	else {
		neg = 0;
		if (c == '+')
			c = *s++;
	}
	if ((base == 0 || base == 16) &&
		c == '0' && (*s == 'x' || *s == 'X')) {
		c = s[1];
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = c == '0' ? 8 : 10;
	/*
	* Compute the cutoff value between legal numbers and illegal
	* numbers.  That is the largest legal value, divided by the
	* base.  An input number that is greater than this value, if
	* followed by a legal input character, is too big.  One that
	* is equal to this value may be valid or not; the limit
	* between valid and invalid numbers is then based on the last
	* digit.  For instance, if the range for intmax_t is
	* [-9223372036854775808..9223372036854775807] and the input base
	* is 10, cutoff will be set to 922337203685477580 and cutlim to
	* either 7 (neg==0) or 8 (neg==1), meaning that if we have
	* accumulated a value > 922337203685477580, or equal but the
	* next digit is > 7 (or 8), the number is too big, and we will
	* return a range error.
	*
	* Set any if any `digits' consumed; make it negative to indicate
	* overflow.
	*/
	/* BIONIC: avoid division and module for common cases */
#define  CASE_BASE(x) \
            case x:  \
	        if (neg) { \
                    cutlim = INTMAX_MIN % x; \
		    cutoff = INTMAX_MIN / x; \
	        } else { \
		    cutlim = INTMAX_MAX % x; \
		    cutoff = INTMAX_MAX / x; \
		 }; \
		 break

	switch (base) {
	case 4:
		if (neg) {
			cutlim = (int)(INTMAX_MIN % 4);
			cutoff = INTMAX_MIN / 4;
		}
		else {
			cutlim = (int)(INTMAX_MAX % 4);
			cutoff = INTMAX_MAX / 4;
		}
		break;
		CASE_BASE(8);
		CASE_BASE(10);
		CASE_BASE(16);
	default:
		cutoff = neg ? INTMAX_MIN : INTMAX_MAX;
		cutlim = cutoff % base;
		cutoff /= base;
	}
#undef CASE_BASE

	if (neg) {
		if (cutlim > 0) {
			cutlim -= base;
			cutoff += 1;
		}
		cutlim = -cutlim;
	}
	for (acc = 0, any = 0;; c = (unsigned char)*s++) {
		if (isdigit(c))
			c -= '0';
		else if (isalpha(c))
			c -= isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0)
			continue;
		if (neg) {
			if (acc < cutoff || (acc == cutoff && c > cutlim)) {
				any = -1;
				acc = INTMAX_MIN;
				errno = ERANGE;
			}
			else {
				any = 1;
				acc *= base;
				acc -= c;
			}
		}
		else {
			if (acc > cutoff || (acc == cutoff && c > cutlim)) {
				any = -1;
				acc = INTMAX_MAX;
				errno = ERANGE;
			}
			else {
				any = 1;
				acc *= base;
				acc += c;
			}
		}
	}
	if (endptr != 0)
		*endptr = (char *)(any ? s - 1 : nptr);
	return (acc);
}