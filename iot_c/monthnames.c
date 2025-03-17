#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


typedef enum { English, Italian, Spanish } language;

const char *month(int number, language lang){
    static const char *months_en[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    static const char *months_it[] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno","Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
    static const char *months_sp[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};


    if (number < 1 || number > 12){
        return "Error";
    }
    switch (lang){
        case English:
            return months_en[number - 1];
        case Italian:
            return months_it[number - 1];
        case Spanish:
            return months_sp[number - 1];
        default:
            return "Error";
    }
}
const char *lang2str(language lang){
    switch (lang){
        case English:
            return "English";
        case Italian:
            return "Italian";
        case Spanish:
            return "Spanish";
        default:
            return "Error";
    }

}

int main(){

    

}