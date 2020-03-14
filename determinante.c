#include <stdio.h>
#include <stdlib.h> 









float **matrizDin(int l, int c)
{
    int i;
    float **matriz = (float **) malloc(sizeof(float *) * l);
    for(i = 0; i < l; i++)
    {
        matriz[i] = (float *) malloc(sizeof(float *) * c);
    }
    return matriz;
}

float** suprimeLc(float **mat, int nMat, int l, int c)
{
    int i, j;
    float **matD = matrizDin(nMat, nMat);
    
    for(i=0; i<nMat; i++)
    {
        for(j=0; j<nMat; j++)
        {
            matD[i][j] = mat[i][j];
        }
    }

    for(i=l; i<nMat-1; i++)
    {
        for(j=0; j<nMat; j++)
        {
            matD[i][j] = matD[i+1][j];
        }
    }
    
    for(i=0; i<nMat-1; i++)
    {
        for(j=c; j<nMat; j++)
        {
            matD[i][j] = matD[i][j+1];
        }
    }

    
    return matD;
    
 }


float determinante(int n, float **mat)
{
  if(n == 2)
    return ((mat[0][0] * mat[1][1])-(mat[0][1]*mat[1][0]));
}


void main()
{
    int i, j;
    float **matA = matrizDin(5, 5);
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            matA[i][j] = i+j;
        }
    }
    
    for(i=0; i<5; i++)
    {
        printf("\n");
        for(j=0; j<5; j++)
        {
            printf("%.1f  ", matA[i][j]);
        }
    }


    float **matD = suprimeLc(matA, 5, 5, 5);
    printf("\n");
    printf("\n");
    printf("\n");


    

    for(i=0; i<5; i++)
    {
        printf("\n");
        for(j=0; j<5; j++)
        {
            printf("%.1f  ", matD[i][j]);
        }
    }

    
}

