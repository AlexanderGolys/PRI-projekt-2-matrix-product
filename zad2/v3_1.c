
//
//  v3.1
//  zad2
//
//  Created by Alexander Golys on 02/11/2018.
//  Copyright © 2018 Alexander Golys. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct element {
    struct element *next;
    double value;
} Element;

typedef struct size {
    int col;
    int row;
    Element *m1x1;
} Size;

void add_to_matrix (Element *first, double add_value)
{
    Element *ptr, *new;
    ptr = first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new = malloc(sizeof(Element));
    if (new == NULL){
        puts("---error---");
        exit(1);}
    
    new->value = add_value;
    new->next = NULL;
    ptr->next = new;
}

Size load_matrix (Element *first, Size size, char *in){
    
    bool f_check = false;
    bool l_check = false;
    double add_value;
    char entry[1000000];
    int l_counter = 0;
    

    while(1){
        

    in = fgets (entry, 1000000, stdin); //wczytuje linię
        
        if (strcmp(in, "\n") == 0) //jesli linia będzie pusta, przerwij
            break;
    
    if(f_check == false){ //jesli nie znamy pierwszego wyrazu
        
        if (strncmp(in, "\n", 1) == 0){ //jesli linia będzie pusta, zgłoś błąd
            puts("---error---");
            exit(1);}
        
        first->next = NULL;
    
      if ((in[0]<48 || in[0]>57) && in[0]!=45){
            puts("---error---");
            exit(1);
        }
        
        first->value = strtod(in, &in);
        
        if (in[0]!=48 && first->value == 0){
            puts("---error---");
            exit(1);
        }
        
        ++size.col;
    }
    
       
    
    ++size.row; //zwieksz liczbe rzedow
        
    bool f_go_check = true; //wczytywanie pierwszej komorki w rzedzie
        
    while (strncmp(in, "\n", 1)) //dopóki nie skończą się liczby w linii
    {
        
           if ((in[0]<48 || in[0]>57) && in[0]!=32 && in[0]!=45){
            puts("--error--");
               exit(1);
        }
        if (in[0]==45 && in[1]==45)
        {
            puts("--error--");
            exit(1);
        }
        if ((f_go_check == false || f_check == false) && (in[1]<48 || in[1]>57) && in[1]!=45){
            puts("--error--");
            exit(1);
        }
        f_go_check = false;
        
        add_value = strtod(in, &in);
        
        if (in[0]!=48 && add_value == 0){
            puts("--error--");
            exit(1);
        }
        
        add_to_matrix(first, add_value);
    
        if (in[0]!=48 && first->value == 0){
            puts("--error--");
            exit(1);
        }
            ++l_counter;
        
        if(l_check){
        if (l_counter>size.col){
                puts("--error--");
            exit(1);}}else
                ++size.col;
    }
        if (l_check)
            if (size.col != l_counter){
                printf("%i%i", size.col, l_counter);
                puts("--error--");
                exit(1);}
        
        l_counter = 0;
        l_check = true; // zaznacza, że liczba kolumn jest znana
        f_check = true;

    }

    size.m1x1 = first;
    return size;

}

int place_check (double a) //sprawdza ilosc cyfr po przecinku
{
    if ((int)floor(10*a)%10 == 0)
        return 0;
    else if ((int)floor(100*a)%10 == 0)
        return 1;
    else if ((int)floor(1000*a)%10 == 0)
        return 2;
    else if ((int)floor(10000*a)%10 == 0)
        return 3;
    else if ((int)floor(100000*a)%10 == 0)
        return 4;
    else if ((int)floor(1000000*a)%10 == 0)
        return 5;
    else
        return 6;
    
}

void free_matrix ( Element* element ){
    Element* previous = NULL;
    while(element)
    {
        previous = element;
        element = element->next;
        free (previous);
    }}

int max_place;
Element *v1_00;
Element *v2_00;
Size size1 = {0, 0,};
Size size2 = {0, 0,};





int main(void){
        
        char *inn;
        inn = malloc(1000000*sizeof(char));
    if (inn == NULL){
        puts("--error--");
        exit(1);
    }
    
    v1_00 = malloc(sizeof(Element));
    if (v1_00 == NULL){
        puts("---error---");
        exit(1);
    }
    size1 = load_matrix(v1_00, size1, inn);
    
    v2_00 = malloc(sizeof(Element));
    if (v2_00 == NULL){
        puts("---error---");
        exit(1);
    }
    size2 = load_matrix(v2_00, size2, inn);
        
        free(inn);
    
        if (size1.col != size2.row){
            puts("--error--");
            exit(1);}
        
    double m1[size1.row][size1.col];
    double m2[size2.row][size2.col];
    double out[size1.row][size2.col];

    Element *pt=size1.m1x1;
    
    int i, ii, iii;
    for (i=0; i<size1.row; ++i)
        for (ii=0; ii<size1.col; ++ii)
        {
            m1[i][ii] = pt->value;
            pt = pt->next;
        }
    
     
    pt = size2.m1x1;
    
    for (i=0; i<size2.row; ++i)
        for (ii=0; ii<size2.col; ++ii)
        {
            m2[i][ii] = pt->value;
            pt = pt->next;
        }

    free_matrix(v1_00);
    free_matrix(v2_00);

        
        for (i=0; i<size1.row; ++i)
            for (ii=0; ii<size2.col; ++ii)
                out[i][ii]=0;
    
    for (i=0; i<size1.row; ++i)
        for (ii=0; ii<size2.col; ++ii)
            for (iii=0; iii<size1.col; ++iii){
                out[i][ii] = out[i][ii] + m1[i][iii]*m2[iii][ii];
                if (place_check(out[i][ii]) > max_place)
                    max_place = place_check(out[i][ii]);
            }
    
    
    return 0;
}


