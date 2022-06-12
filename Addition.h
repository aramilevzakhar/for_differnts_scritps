#ifndef ADDITION_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define BLOCK_SIZE 16
#define nb 4
#define nk 4

int 
len(int);

void
e(unsigned char***, unsigned char***, unsigned char**, int);
void 
d(unsigned char***, unsigned char***, unsigned char**, int);


void 
show(unsigned char***,int,int);
void 
keyShow(unsigned char**);

void 
sbox(unsigned char*);
void 
invsbox(unsigned char*);

void 
sub_sbox(unsigned char*);
void 
sub_invsbox(unsigned char*);


void 
subMixColumns(unsigned char**);
void 
subInvMixColumns(unsigned char**);

void 
rotWord(unsigned char*, int);
unsigned short int 
rcon(int,int);
unsigned char** 
KeyExpansion(unsigned char**,size_t); // generate roundkey


void
SubBytes(unsigned char***,int);
void 
ShiftRows(unsigned char***,int);
void 
MixColumns(unsigned char***,int);
void
AddRoundKey(unsigned char***, unsigned char**,size_t); // xor state 


void
InvSubBytes(unsigned char***,int);
void
InvShiftRows(unsigned char***,int);
void 
InvMixColumns(unsigned char***,int);

#endif
