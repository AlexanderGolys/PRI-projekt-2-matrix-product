//
//  v2.c
//  zad2
//
//  Created by Alexander Golys on 02/11/2018.
//  Copyright © 2018 Alexander Golys. All rights reserved.
//

#include <stdio.h>

int hex_to_dec (int a){
    int wyn = 0;
    for (int i=0; a!=0; ++i){
        int pom = 0;
        pom = a - a/8;
        a/=8;
        for(int j = 0; i<j; ++j)
            pom *= 10;
        wyn += pom;
    }
    return wyn;
}

int dec_to_hex(int a){
    int pow10 = 1;
    int pow8 = 1;
    for (int i = 0; a!=0; ++i){
        for int (j = 0; j<i; ++j){
            pow10*=10;
            pow8*=8;
        }
        wyn+=pow8*((a - (a/10)*10))
        a/=10;
    }
    
}

int main (void){
    

    
}
