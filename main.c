#include <stdio.h>
#include <stdlib.h>

struct pair {
    int start;
    int end;
};

int compare (const void *x_void, const void *y_void){

    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y;
}

int main() {
    int start[] = {10, 12, 20};
    int end[] = {20, 29, 25};
    int n = sizeof(start) / sizeof(start[0]);

    qsort(end,n,sizeof(int),compare);







    struct pair set[n];

    // Populate the array
    for (int i = 0; i < n; i++) {
        set[i].start = start[i];
        set[i].end = end[i];
    }

    // Print the pairs
    printf("Pairs are:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", set[i].start, set[i].end);
    }

    int count = 1;
    int last_end_time = set[0].end;


    for(int i = 0;i<n;i++){

        if(set[i].end<=last_end_time){
            count++;
            last_end_time = set[i].end;
        }
    }

    printf("Count of valid relationships: %d\n", count);

    return 0;
}
