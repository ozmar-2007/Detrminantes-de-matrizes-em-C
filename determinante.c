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
    float **matTmp = matrizDin(nMat, nMat);
    float **matD = matrizDin(nMat-1, nMat-1);
    
    for(i=0; i<nMat; i++)
    {
        for(j=0; j<nMat; j++)
        {
            matTmp[i][j] = mat[i][j];
        }
    }

    for(i=l; i<nMat-1; i++)
    {
        for(j=0; j<nMat; j++)
        {
            matTmp[i][j] = matTmp[i+1][j];
        }
    }
   
    for(i=0; i<nMat-1; i++)
    {
        for(j=c; j<nMat-1; j++)
        {
            matTmp[i][j] = matTmp[i][j+1];
        }
    }
    
    for(i=0; i<nMat; i++)
    {
        free(matTmp[i]);
    }
    
    free(matTemp);

    
    for(i=0; i<nMat-1; i++)
    {
        for(j=0; j<nMat-1; j++)
        {
            matD[i][j] = matTmp[i][j];
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


    

    for(i=0; i<4; i++)
    {
        printf("\n");
        for(j=0; j<4; j++)
        {
            printf("%.1f  ", matD[i][j]);
        }
    }

    
}

