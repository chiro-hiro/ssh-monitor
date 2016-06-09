/* SSH monitor and String Helper under the 2-term BSD license
 * 
 * Copyright (c) 2016 Dung Tran <tad88.dev@gmail.com>.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "str-helper.h"

/* Clean string remove secial characters */
char*
string_clean(const char* input_string) {
    char *p = input_string;
    char *s = malloc((strlen(input_string) + 1) * sizeof (char));
    char *r = s;
    while (*p != 0x00) {
        if ((*p >= '0' && *p <= '9')
                || (*p >= 'A' && *p <= 'Z')
                || (*p >= 'a' && *p <= 'z')
                || *p == '.') {
            *(s++) = *p;
        }
        else if(*p == ' '
                || *p == ':'){
            *(s++) = '-';
        }
        p++;
    }
    *(++s) = 0x00; /* End string */
    return r;
}

/* Generate filename */
char*
string_file_name(const char* host) {
    char *p = NULL;
    p = malloc(1024 * sizeof (char));
    time_t t;
    time(&t);
    struct tm ltm = *localtime(&t);
    sprintf(p, "/var/log/ssh-monitor/%s-%d-%d-%d-%d-%d-%d.log",
            host, ltm.tm_yday,
            ltm.tm_mon + 1,
            ltm.tm_year+1900,
            ltm.tm_hour,
            ltm.tm_min,
            ltm.tm_sec);
    return p;
}