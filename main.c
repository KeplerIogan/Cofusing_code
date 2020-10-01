#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap (float *a, float *b) {

    float c;
    c = *a;
    *a = *b;
    *b = c;
}


void main() {

    printf("\n\n");

    FILE *m = fopen("matrix.txt", "r");
    char sym;
    int l = 1;
    float max;

    sym = fgetc(m);

    while(sym != '|') {

        if (sym == ' ') {
            l++;
        }
        sym = fgetc(m);
    }
    printf("Number of m: %d\n\n", l - 1);

    fseek(m, 0, SEEK_SET);
    sym = fgetc(m);

    float mat[l - 1][l];
    float mod[l - 1][l];

    for(
//--------------------------------------------
    int i
  =0    ;i<l
  -1        ;i++
    ){        for(
    int           j=0;
      j<              l;j++){if(sym
      ==                           '-'){
      sym                         = 
      fgetc(            m);mat
      [i            ][j]=(
    sym       -'0')*( -1  );
  sym     =fgetc(m  /**/  );/*
na    */  while(    free){/*  */
  if(sym!=' '&&sym!='\n'){mat[  i]
    [j             ]=mat[       i]
      [j    ]*10+(            sym-
    '0'           )*(       -1    );
    sym           =fgetc    (m    );
      /*            NN          NN*/
      /*            NN        NN  */
      /*          */}else   {   //
      break;    }}        /*    */
      /*        a=      zi      */
    while(    free  ){if      (sym
  ==      ' '||                  sym
    =='|'||    sym=='\n'){sym=fgetc(m);
//--------------------------------------------
                    } else {

                        break;
                    }
                }
            } else {

                mat[i][j] = sym - '0';
                sym = fgetc(m);

                while(free) {
                    if (sym != ' ' && sym != '\n') {

                        mat[i][j] = mat[i][j] * 10 + (sym - '0');
                        sym = fgetc(m);
                    } else {

                        break;
                    }
                }

                while(free) {
                    if (sym == ' ' || sym == '|' || sym == '\n') {

                        sym = fgetc(m);
                    } else {

                        break;
                    }
                }
            }
        }
    }

    printf("1. Gauss:\n\n");
//------------------------------------------------------------
    for (int i = 0; i < l - 1; i++) {
        for(int j = 0; j < l; j++) {

            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < l; j++) {

            mod[i][j] = mat[i][j];
        }

    }

    float k;

//смещение по уровню
    for (int lvl = 0; lvl < l - 2; lvl++) {
//вычисление коэффициена для строки
        for (int j = lvl + 1; j < l - 1; j++) {
            k = mat[j][lvl] / mat[lvl][lvl];
            printf("\nk = %f\n", k);
//вычисление строки
            for(int str = lvl; str < l; str++) {

                mat[j][str] = mat[j][str] - mat[lvl][str] * k;
            }
        }

        printf("\n");
        for (int i = 0; i < l - 1; i++) {

            for(int j = 0; j < l; j++) {

                printf("%.2f ", mat[i][j]);
            }
            printf("\n");
        }

    }

    printf("\n");

    float root[l - 1];
    float subroot;

//нахождение корней

    root [l - 2] = mat[l - 2][l - 1] / mat[l - 2][l -2];
    printf("\n\n");


    for (int i = l  - 3; i >= 0; i--) {

        subroot = mat[i][l - 1];

        for (int j = l  - 2; j >= i + 1; j--) {

            subroot -= mat[i][j] * root[j];
        }

        root[i] = subroot / mat[i][i];
    }

    for (int i = 0; i < l - 1; i++) {

        printf("\nx%d = %f\n", i + 1, root[i]);
    }
    fclose(m);

    printf("2. Mod Gauss:\n\n");
//mod Gauss----------------------------------


    printf("\n");

    int y = 0;

    for (int i = 0; i < l - 1; i++) {

        for(int j = 0; j < l; j++) {

            printf("%.2f ", mod[i][j]);
        }
        printf("\n");
    }

//смещение по уровню

    for (int lvl = 0; lvl < l - 2; lvl++) {

//поиск наибольшего для диагонали

        max = mod[lvl][y];

        printf("\n\n%f\n\n", max);

        for (int i = lvl + 1; i < l - 2; i++) {

            if (fabs(mod[i][y]) > fabs(max)) { max = mod[i][y]; }
        }
//если нашёл, то свап строк

        if (fabs(max) >= fabs(mod[lvl][y])) {

            for (int i = 1; i < l - 2; i++) {

                if (fabs(max) == fabs(mod[i][y])) {

                    for (int j = 0; j < l - 1; j++) { swap(&mod[lvl][j], &mod[i][j]); }

                    break;

                }

            }
        }

        y++;

//вычисление коэффициена для строки

        for (int j = lvl + 1; j < l - 1; j++) {
            k = mod[j][lvl] / mod[lvl][lvl];
            printf("\nk = %f\n", k);

//вычисление строки

            for(int str = lvl; str < l; str++) {

                mod[j][str] = mod[j][str] - mod[lvl][str] * k;
            }

            for (int i = 0; i < l - 1; i++) {

                for(int j = 0; j < l; j++) {

                    printf("%.2f ", mod[i][j]);
                }
                printf("\n");
            }
        }
    }


    float mod_root[l - 1];
    float mod_subroot;

//нахождение корней

    mod_root [l - 2] = mod[l - 2][l - 1] / mod[l - 2][l -2];
    printf("\n\n");


    for (int i = l  - 3; i >= 0; i--) {

        mod_subroot = mod[i][l - 1];

        for (int j = l  - 2; j >= i + 1; j--) {

            mod_subroot -= mod[i][j] * mod_root[j];
        }

        mod_root[i] = mod_subroot / mod[i][i];
    }

    for (int i = 0; i < l - 1; i++) {

        printf("\nx%d = %f\n", i + 1, mod_root[i]);
    }

}
