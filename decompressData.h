//@author: João Gabriel Silva Fernandes

#include <stdio.h>

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif



#define CHUNK 256000		//size of buffer in bytes
#define COMPRESSION_LEVEL 9	//de -1 a 9 -> -1 = Z_DEFAULT_COMPRESSION ( que é igual a 6)

typedef unsigned char byte;

/*
	source 		-> ponteiro para arquivo fonte a ser lido
	dest_stream	-> ponteiro para array de bytes, isto é, ponteiro para a stream destino;
	final_size 	-> quantidade total de bytes colocados na stream
*/
int my_decompress(FILE *source, byte **dest_stream, unsigned long *final_size );

/*
	source 		-> ponteiro para arquivo fonte a ser lido
	dest 		-> ponteiro para arquivo destino a ser escrito
*/
int my_compress(FILE *source, FILE *dest);