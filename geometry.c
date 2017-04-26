/*
 * geometry.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file contains a simple geomtery functions.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

#include "geometry.h"

#define FUZZY_EQ 0.01

#define DEBUG(file, line, func, msg) fprintf(stderr, "DEBUG - %s_%d_%s: %s", file, line, func, msg);

double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }

    /* Maths */
    return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

}

bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b){

    /* Equal if dist <= FUZZY_EQ */
    if(coord_2d_dist(a, b) <= FUZZY_EQ){
        return true;
    }
    else{
        return false;
    }

}

void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b){
    /*
    / input checks /
    if(!mid){
        DEBUG(__file__, __line__, __func__, "'mid' must not be null");
        return;
    }
    if(!a){
        DEBUG(__file__, __line__, __func__, "'a' must not be null");
        return;
    }
    if(!b){
        DEBUG(__file__, __line__, __func__, "'b' must not be null");
        return;
    }
    */
    /* Maths */
    mid->x = ((a->x + b->x) / 2.0 );
    mid->y = ((a->y + b->y) / 2.0 );

}


double coord_2d_area_triangle(const coord_2d_t *a, const coord_2d_t *b, const coord_2d_t *c){
   /*  input checks /
    if(!c){
        DEBUG(__file__, __line__, __func__, "'c' must not be null");
        return NAN;
    }
    if(!a){
        DEBUG(__file__, __line__, __func__, "'a' must not be null");
        return NAN;
    }
    if(!b){
        DEBUG(__file__, __line__, __func__, "'b' must not be null");
        return NAN;
    }
    */
    return abs( ( a->x * (b->y - c->y)) + (b->x * (c->y - a->y))+ (c->x * (a->y - b->y) ) / 2);
}

