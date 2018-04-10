#include <stdio.h>

#include <rpc/rpc.h>    /* xdr is a sub-library of rpc */

main()       /* writer.c */
{
     XDR xdrs;
     int i;

xdrstdio_create(&xdrs, stdout, XDR_ENCODE);

     for (i = 0; i < 8; i++) {
         if (!xdr_int(&xdrs, &i)) {
             fprintf(stderr, "failed!\n");
             exit(1);
         }
     }
     exit(0);
}
