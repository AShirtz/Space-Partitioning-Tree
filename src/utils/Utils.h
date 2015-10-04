#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define round(x) ((x) >= 0 ? (long)((x)+0.5) : (long)((x)-0.5))
#define MAX_CAN_ADDR_LEN 11
#define UNIT_TILE_VOLUME (32/(3*(sqrt(3))))

#include "Objects.h"
#include "FileIO.h"
#include "Queries.h"

typedef void (pFuncCB) (Node *curNd, unsigned int depth, void *params);

/*	Tree functions	*/

void allocateChild (Node *curNd, Tuple tup);
void nodeInsert (Node *curNd, DataPointEntry *dpe, unsigned int depth);
void nodeTraverse (Node *curNd, unsigned int depth, void *params, pFuncCB *callBack);

/*	Basis Vectors	*/

void getBasisVector (int index, EucVec* output, double scale);
void evalBasisLinearCombo (double a, double b, double c, double d, EucVec* output);
void getBasisVectorMatrix (double* a, double scale);

/*	Conversion Functions	*/

void swap_row(double *a, double *b, int r1, int r2, int n);
void gauss_eliminate(double *a, double *b, double *x, int n);
void produceLatAddr (EucVec *inVec, LatAddr *outAddr);
unsigned int produceCanAddr (LatAddr *inAddr, CanAddr *outAddr);

#endif