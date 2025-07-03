#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char tennghesy[30];
	char sodienthoai[15];
	int catxe;
}nghesy;

void xoaxuongdong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void sapxep(int n, nghesy *ns){
	for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
			if(ns[j].catxe < ns[j + 1].catxe){
				nghesy temp = ns[j];
				ns[j] = ns[j + 1];
				ns[j + 1] = temp;
			}
		}
	}
	printf("Danh sach nghe sy co cat-xe giam dan la:\n");
	for (int i = 0; i < n; i++){
		printf("%-20s %-20s %d\n", ns[i].tennghesy, ns[i].sodienthoai, ns[i].catxe);
	}	
}

void tongtien(int n, nghesy *ns){
	int tong = 0;
	for (int i = 0; i < n; i++){
		tong += ns[i].catxe;
	}
	printf("Tong tien cua cac nghe sy la: %d", tong);
}

void docfile(char tenfile[30],int *n, nghesy **ns){
	FILE *f = fopen(tenfile, "r");
	
	fscanf(f, "%d\n", n);
	*ns = (nghesy*)malloc(*n * sizeof(nghesy));
	
	for(int i = 0; i < *n; i++){
		fgets((*ns)[i].tennghesy, sizeof((*ns)[i].tennghesy), f);
        fgets((*ns)[i].sodienthoai, sizeof((*ns)[i].sodienthoai), f);
        fscanf(f, "%d\n", &(*ns)[i].catxe);

        xoaxuongdong((*ns)[i].tennghesy);
        xoaxuongdong((*ns)[i].sodienthoai);
	}
	fclose(f);
}
	
void in(int n, nghesy *ns){
	printf("Danh sach nghe sy la:\n");
	printf("%-20s %-20s %-20s\n", "Ten nghe sy", "So dien thoai", "Cat-xe");
	for(int i = 0; i < n; i++){
		printf("%-20s %-20s %d\n", ns[i].tennghesy, ns[i].sodienthoai, ns[i].catxe);
	}
}

int main(){
	int n;
	nghesy *ns = NULL;
	char tenfile[30];
	
	printf("Nhap ten file: ");
    fgets(tenfile, sizeof(tenfile), stdin);
    xoaxuongdong(tenfile);
    
	docfile(tenfile, &n, &ns);
	in(n, ns);
	sapxep(n, ns);
	tongtien(n, ns);
	
	free(ns);
}

