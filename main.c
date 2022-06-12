#include "Addition.h"
#include <stdlib.h>



int main(int argc, unsigned char* argv[]) {
	size_t i,j,k;
	int count = 0;
	char c;
	unsigned char* text;

	unsigned char str[51];
	strcpy(str, argv[1]);


	FILE* fp = NULL;

	if((fp = fopen(str,"rb"))==NULL){
		printf("Could not open file\n");
		return 0;

	}else{

		while(1){
			fread(&c, sizeof(unsigned char), 1, fp);
			++count;
			if(feof(fp)){
				break;
			}
		}
		fp = freopen(str,"rb",fp);
		text = (unsigned char*)malloc(count*sizeof(unsigned char));
		for(i = 0;i<count;i++){
			text[i] = (unsigned char)fgetc(fp);
		}
	}
	fclose(fp);
	printf("%d\n", count);	
	//size_t SIZE_TEXT = strlen(text);
    
	size_t SIZE_TEXT = count;
	size_t RIGHT_SIZE_TEXT = len(SIZE_TEXT);
	size_t ANZAHLDERBLOCKE = RIGHT_SIZE_TEXT/BLOCK_SIZE;

	text = (unsigned char*)realloc(text, RIGHT_SIZE_TEXT*sizeof(unsigned char));
	for(i = SIZE_TEXT;i<RIGHT_SIZE_TEXT;i++) text[i] = 0;

	unsigned char* key = (unsigned char*)malloc(nb*nb*sizeof(unsigned char) + 1);
	strcpy(key, "clave de 128bits");

	unsigned char** key4x4;
	unsigned char** kn;
	
	key4x4 = (unsigned char**)malloc(nb*sizeof(unsigned char*));
	kn = (unsigned char**)malloc(nb*sizeof(unsigned char*));
	for(i = 0;i<nb;i++){
		key4x4[i] = (unsigned char*)malloc(nb*sizeof(unsigned char));
		kn[i] = (unsigned char*)malloc(nb*sizeof(unsigned char));
		for(j = 0;j<nb;j++){
			key4x4[i][j] = key[i+nb*j];
			kn[i][j] = key[i+nb*j];
		}
	}
	free(key);

	unsigned char*** p3 = (unsigned char***)malloc(ANZAHLDERBLOCKE*sizeof(unsigned char**));
	for(i = 0;i<ANZAHLDERBLOCKE;i++){
		p3[i] = (unsigned char**)malloc(nb*sizeof(unsigned char*));
		for(j = 0;j<nb;j++){
			p3[i][j] = (unsigned char*)malloc(nb*sizeof(unsigned char));
			for(k = 0;k<nb;k++){
				p3[i][j][k] = text[i*BLOCK_SIZE+j+nb*k];
			}
		}
	}

	i = 1;
	size_t numberRounds = 10;
	unsigned char*** key_rounds = (unsigned char***)malloc(numberRounds*sizeof(unsigned char**));
	for(i = 1; i <= numberRounds; i++){
		key_rounds[i - 1] = (unsigned char**)malloc(nb*sizeof(unsigned char*));
		kn = KeyExpansion(kn, i);
		key_rounds[i-1] = kn;
	}


	printf("Encrypt - 1\nDecrypt - 2\n");
	int l1;
	scanf("%d", &l1);

	if(l1==1){ 
		e(p3,key_rounds, key4x4,ANZAHLDERBLOCKE); 
		show(p3, ANZAHLDERBLOCKE, 1);
		strcat(str, ".enc");
	}else if(l1==2){
		d(p3,key_rounds, key4x4,ANZAHLDERBLOCKE); 
		strcpy(str, "result");
	}else{
		printf("Invalid input\n");
	}

	FILE* fc = NULL;
	if((fc = fopen(str,"wb"))==NULL){
		printf("Unknown error");
		return 0;
	}else{
		for(i = 0;i<ANZAHLDERBLOCKE;i++){
			for(j = 0;j<nb;j++){
				for(k = 0;k<nb;k++){
					//printf("%02X ", p3[i][k][j]);
					fputc(p3[i][k][j],fc);
				}
			}
		}
	}
	fclose(fc);


	for(i = 0;i<numberRounds;i++){
		for(j = 0;j<nb;j++){
			free(key_rounds[i][j]);
		}
	}

	for(i = 0;i<ANZAHLDERBLOCKE;i++){
		for(j = 0;j<nb;j++){
			free(p3[i][j]);
		}
	}


	return 0;
}


