//
// Created by Hugo Vieira on 05/01/2020.
//

#ifndef LPPROG2FI_CHECK_H
#define LPPROG2FI_CHECK_H
#include "library.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "R9.h"
int checkConsist(TAB tab,CEL cel,int n);
int checklin(CEL *cel,int n);
int checkcol(CEL *cel,int n);
int checkdiaprin(CEL *cel,int n);
int checkdiasec(CEL *cel,int n);
int checkbox(TAB *tab,CEL *cel,int n,int size);
#endif //LPPROG2FI_CHECK_H
