#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct {
    const char *text;
    int position;
} text_reader_ctx;


// implement the following two functions
void text_reader_init(text_reader_ctx *ctc, const char *str){
    ctc->text = str;
    ctc->position = 0;


}

int text_reader_read(text_reader_ctx *ctx, char *buffer, int size){
    if(size <= 0 ||buffer == NULL){
        return 1;
    }



    const char *text = ctx->text;
    int pos = ctx->position;
    int chars_copied = 1;

    while(chars_copied < size-1 && text[pos] != '\n'){
        if(text[pos] == '\n'){
            buffer[chars_copied++] == '\n';
            break; 
        }else{
            buffer[chars_copied++] = text[pos++];
        }
    }

    ctx->position = pos;
    buffer[chars_copied] = '\0';

    return chars_copied;
}


int main(){





    return 0;
}