#include <stdio.h>
#include <stdlib.h>

float **matrizDin(int l, int c);
float** suprimeLc(float **mat, int nMat, int l, int c);
float determinante(float **mat, int nMat);

int main()
{
    /*
    int i, j;
    float **matA = matrizDin(5, 5);    
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Digite um numero a%i%i: ", i, j);
            scanf(" %f", &matA[i][j]);
        }
    }

    matA[0][0]= 0;
    matA[0][1]= 1;
    matA[0][2]= 2;
    matA[1][0]= 1;
    matA[1][1]= 3;
    matA[1][2]= 1;
    matA[2][0]= 2;
    matA[2][1]= 1;
    matA[2][2]= 2;
    
    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<3; j++)
        {
            printf("%.1f  ", matA[i][j]);
        }
    }

    float **matD = suprimeLc(matA, 3, 0, 0);
    printf("\n");
    printf("\n");
    printf("\n");

    for(i=0; i<2; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
        {
            printf("%.1f  ", matD[i][j]);
        }
    }
    
    printf(" \n\n%.2f ", determinante(matA, 3));
    */
    return 0;
}

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
    
    for(i=0; i<nMat-1; i++)
    {
        for(j=0; j<nMat-1; j++)
        {
            matD[i][j] = matTmp[i][j];
        }
    }

    for(i=0; i<nMat; i++)
        {
            free(matTmp[i]);
        }
    free(matTmp);

    return matD;
}

float determinante(float **mat, int nMat)
{
    if(nMat == 2)
    {
        return ((mat[0][0] * mat[1][1])-(mat[0][1]*mat[1][0]));
    }
    
    float resultado=0;
    int j;
    for(j=0; j<nMat; j++)
    {
        if(0+j % 2 == 0)
        {
            resultado = resultado + (  mat[0][j] * determinante(suprimeLc(mat, nMat, 0, j), nMat-1) );
        }
        else
        {
            resultado = resultado + ( mat[0][j] * (determinante(suprimeLc(mat, nMat, 0, j), nMat-1)) * -1 );
        }
    }
    return resultado;
}
