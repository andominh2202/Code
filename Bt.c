#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tensach[50];
    char tacgia[30];
    int nxb;
} sach;

void xoaxuongdong(char s[]) {
    s[strcspn(s, "\n")] = 0;
}

int main() {
    FILE *fin = fopen("sach.txt", "r");
    if (fin == NULL) {
        printf("Khong mo duoc file sach.txt\n");
        return 1;
    }

    int n;
    fscanf(fin, "%d\n", &n);
    sach *s = (sach*)malloc(n * sizeof(sach));
    
    for (int i = 0; i < n; i++) {
        fgets(s[i].tensach, sizeof(s[i].tensach), fin);
        fgets(s[i].tacgia, sizeof(s[i].tacgia), fin);
        fscanf(fin, "%d\n", &s[i].nxb);

        xoaxuongdong(s[i].tensach);
        xoaxuongdong(s[i].tacgia);
    }
    fclose(fin);

    printf("Danh sach sach la:\n");
    printf("%-20s %-20s %-20s\n", "Ten sach", "Tac gia", "Nam xuat ban");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-20s %d\n", s[i].tensach, s[i].tacgia, s[i].nxb);
    }

    char tencantim[50];
    int x = 0;
    printf("Nhap ten sach can tim: ");
    fgets(tencantim, sizeof(tencantim), stdin);
    xoaxuongdong(tencantim);

    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].tensach, tencantim) == 0) {
            printf("Tim thay sach: %s, %s, %d\n", s[i].tensach, s[i].tacgia, s[i].nxb);
            x = 1;
            break;
        }
    }
    if (x == 0) {
        printf("Khong tim thay sach: %s\n", tencantim);
    }

    FILE *fout = fopen("sachout.txt", "w");
    if (fout == NULL) {
        printf("Khong mo duoc file sachout.txt\n");
        return 1;
    }

    printf("\nDanh sach sach xuat ban truoc nam 2000 la:\n");
    for (int i = 0; i < n; i++) {
        if (s[i].nxb < 2000) {
            printf("%s, %s, %d\n", s[i].tensach, s[i].tacgia, s[i].nxb);
            fprintf(fout, "%s, %s, %d\n", s[i].tensach, s[i].tacgia, s[i].nxb);
        }
    }

    fclose(fout);
    free(s);
    
    return 0;
}
