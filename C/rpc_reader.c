#include <stdio.h>

#include <rpc/rpc.h>    /* xdr is a sub-library of rpc */

main()                /* reader.c */
{
     XDR xdrs;
     int i, j;

xdrstdio_create(&xdrs, stdin, XDR_DECODE);

     for (j = 0; j < 8; j++) {
         if (!xdr_int(&xdrs, &i)) {
             fprintf(stderr, "failed!\n");
             exit(1);
         }
         printf("%ld ", i);
     }
     printf("\n");
     exit(0);
}
