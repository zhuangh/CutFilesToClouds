
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main(int argc, char *argv[])
{
    char splitfn[280];
    long part = 0, chunk = 100 * 1024;
    FILE *fp, *op;
    char *fb;
    char *ofn = "StdIn";

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: splits [<filename>|-] [chunk(Kb)]\n");
	return 2;
    }

    if (argc > 2) {
	long lch = atol(argv[2]);

	if (lch < 1) {
            fprintf(stderr, "Invalid chunk size.\n");
	    return 2;
	}
	chunk = lch * 1024L;
    }

    fb = malloc((unsigned) chunk);
    if (fb == NULL) {
	fprintf(stderr, "Unable to allocate %ld byte I/O buffer.\n", chunk);
	return 1;
    }
    if (strcmp(argv[1], "-") != 0) {
	ofn = argv[1];
	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
	    fprintf(stderr, "Cannot open file %s\n", argv[1]);
	    return 2;
	}
    } else {
	fp = stdin;
    }



    while (1) {
	long fl;
//	chunk = chunk_series[part];


	fl = fread(fb, 1, (int) chunk, fp);
	if (fl > 0) {
	    sprintf(splitfn, "%s.%03ld", ofn, ++part);
	    op = fopen(splitfn, "wb");
	    if (op == NULL) {
                fprintf(stderr, "Cannot create output file %s\n", splitfn);
		return 2;
	    }
	    fwrite(fb, 1, (int) fl, op);
	    fclose(op);
	} else {
	    break;
	}

    }
    if (fp != stdin) {
	fclose(fp);
    }


   

    printf("It is divided into %ld part\n",part);

    while(1){
	
    
	break;
    
    
    }


    return 0;
}
