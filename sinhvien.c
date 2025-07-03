#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char ht[20], que[20], hl[10];
} SV;

void xoaxuongdong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void doc(int *n, SV **sv) {
    FILE *f;
    char tentep[50];
    printf("Nhap ten tep: ");
    fgets(tentep,sizeof(tentep), stdin);
    tentep[strcspn(tentep, "\n")] = '\0';

    f = fopen(tentep, "r");
    if (f == NULL) {
        printf("Loi: khong mo duoc tep.\n");
        return;
    }

    fscanf(f, "%d\n", n);
    *sv = (SV *)malloc(*n * sizeof(SV));
    for (int i = 0; i < *n; i++) {
        fgets((*sv)[i].ht, sizeof((*sv)[i].ht), f);
        xoaxuongdong((*sv)[i].ht);

        fgets((*sv)[i].hl, sizeof((*sv)[i].hl), f);
        xoaxuongdong((*sv)[i].hl);

        fgets((*sv)[i].que, sizeof((*sv)[i].que), f);
        xoaxuongdong((*sv)[i].que);
    }
    fclose(f);
}

void in(int n, SV *sv) {
    printf("\n%5s %-20s %-12s %-12s\n", "STT", "Ho Ten", "Hoc luc", "Que quan");
    for (int i = 0; i < n; i++) {
        printf("%5d %-20s %-12s %-12s\n", i + 1, sv[i].ht, sv[i].hl, sv[i].que);
    }
}

void tim(int n, SV *sv) {
	char tentim[50];
	int x = 0; 
	printf(" Nhap ten sinh vien can tim:");
	fgets(tentim,sizeof(tentim),stdin);
	xoaxuongdong(tentim);
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].ht, tentim) == 0) {
            printf("\n Thong tin sinh vien tim thay:\n");
            printf("Hoc luc : %s\n", sv[i].hl);
            printf("Que quan: %s\n", sv[i].que);
            x = 1;
            break;
        }
    }

    if (x == 0) {
        printf("Khong tim thay sinh vien \"%s\"\n", tentim);
    }
}

int main() {
    int n,i;
    SV *sv = NULL;
    doc(&n, &sv);
    in(n,sv);
    tim(n,sv);
    
    free(sv);

    return 0;
}

