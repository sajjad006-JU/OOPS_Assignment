#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int row;
    int col;
    int value;
} Element;

typedef struct SparseMatrix {
    int rows;
    int cols;
    int num_nonzero;
    Element* data;
} SparseMatrix;

SparseMatrix* createSparseMatrix(int row, int col, int n) {

    SparseMatrix* m1=malloc(sizeof(SparseMatrix));
    m1->rows=row;
    m1->cols=col;
    m1->num_nonzero=n;
    Element* data=malloc(n*sizeof(Element));
    m1->data=data;
    return m1;
}

SparseMatrix* acceptSparseMatrix() {
    int row, col, n;
    printf("Enter the number of rows and cols: ");
    scanf("%d", &row);
    scanf("%d", &col);
    printf("Enter the no of non zero values: ");
    scanf("%d", &n);

    SparseMatrix* m1=createSparseMatrix(row, col, n);

    int x, k=0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            scanf("%d", &x);
            if (x!=0) {
                m1->data[k].row=i;
                m1->data[k].col=j;
                m1->data[k].value=x;
                k++;
            }
        }
    }
    return m1;
}

void displaySparseMatrix(SparseMatrix* m1) {
    Element* data=m1->data;
    int k=0;
    for (int i=0; i<m1->rows; i++) {
        for (int j=0; j<m1->cols; j++) {
            if (k<m1->num_nonzero && data[k].row==i && data[k].col==j) {
                printf("%d ", data[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

SparseMatrix* addSparseMatrix(SparseMatrix* m1, SparseMatrix* m2) {
    if (m1->rows!=m2->rows || m1->cols!=m2->cols) {
        printf("Invalid dimensions!\n");
        exit(0);
    }
    int rows=m1->rows, cols=m1->cols;
    SparseMatrix* m3=createSparseMatrix(rows, cols, m1->num_nonzero+m2->num_nonzero);

    int i=0, j=0, k=0;

    while (i<m1->num_nonzero && j<m2->num_nonzero) {
        if (m1->data[i].row<m2->data[j].row || ((m1->data[i].row==m2->data[j].row) && (m1->data[i].col<m2->data[j].col))) {
            m3->data[k++]=m1->data[i++];
        } else if (m2->data[j].row<m1->data[i].row || ((m2->data[j].row==m1->data[i].row) && (m2->data[j].col<m1->data[i].col))) {
            m3->data[k++]=m2->data[j++];
        } else {
            int sum=m1->data[i].value+m2->data[j].value;
            if (sum!=0) {
                m3->data[k].row=m1->data[i].row;
                m3->data[k].col=m1->data[i].col;
                m3->data[k].value=sum;
                k++;
            }
            i++;
            j++;
        }    
    }

    while(i<m1->num_nonzero) {
        m3->data[k++]=m1->data[i++];
    }
    while (j<m2->num_nonzero) {
        m3->data[k++]=m2->data[j++];
    }
    return m3;
}

SparseMatrix* multiplySparseMatrix(SparseMatrix* m1, SparseMatrix* m2) {
    if (m1->cols!=m2->rows) {
        printf("Invalid dimensions!\n");
        exit(0);
    }

    int rows=m1->rows, cols=m2->cols;
    SparseMatrix* m3=createSparseMatrix(rows, cols, m1->num_nonzero*m2->num_nonzero);

    int k=0;

    for (int i=0; i<m1->num_nonzero; i++) {
        for (int j=0; j<m2->num_nonzero; j++) {
            if (m1->data[i].col==m2->data[j].row) {
                int r=m1->data[i].row;
                int c=m2->data[j].col;
                int value=m1->data[i].value*m2->data[j].value;

                int found=0;

                for (int x=0; x<k; x++) {
                    if (m3->data[x].row==r && m3->data[x].col==c) {
                        m3->data[x].value+=value;
                        found=1;
                        break;
                    }
                }

                if (!found) {
                    m3->data[k].row=r;
                    m3->data[k].col=c;
                    m3->data[k].value=value;
                    k++;
                }
            }
        }
    }
    m3->num_nonzero=k;
    return m3;

}

SparseMatrix* readSparseMatrixFromFile(char* fn) {
    FILE *fp;
    fp=fopen(fn, "r");

    int r, c, n;
    fscanf(fp, "%d %d %d", &r, &c, &n);
    SparseMatrix* m=createSparseMatrix(r, c, n);

    for (int i=0; i<n; i++) {
        fscanf(fp, "%d %d %d", &m->data[i].row, &m->data[i].col, &m->data[i].value);
    }

    fclose(fp);
    return m;
}
int main () {
    SparseMatrix* m1=readSparseMatrixFromFile("m1.txt");
    SparseMatrix* m2=readSparseMatrixFromFile("m2.txt");
    displaySparseMatrix(m1);
    displaySparseMatrix(m2);

    SparseMatrix* m3=multiplySparseMatrix(m1, m2);
    displaySparseMatrix(m3);
}
