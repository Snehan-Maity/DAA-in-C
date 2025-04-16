#include <stdio.h>
#include <string.h>

typedef struct {
    char id;
    int p;
    int d;
} Job;

void merge(Job arr[], int left, int mid, int right) {
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (arr[i].p >= arr[j].p) {
            i++;
        } else {
            Job temp = arr[j];
            int k = j;
            
            while (k > i) {
                arr[k] = arr[k - 1];
                k--;
            }
            arr[i] = temp;

            i++;
            mid++;
            j++;
        }
    }
}

void mergeSort(Job arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int findmd(Job jobs[], int n) {
    int md = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].d > md)
            md = jobs[i].d;
    }
    return md;
}

int jobScheduling(Job jobs[], int n, char s[]) {
    mergeSort(jobs, 0, n - 1);

    int md = findmd(jobs, n);
    char slot[md];
    int totalp = 0;

    for (int i = 0; i < md; i++)
        slot[i] = '-';

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].d - 1; j >= 0; j--) {
            if (slot[j] == '-') {
                slot[j] = jobs[i].id;
                totalp += jobs[i].p;
                break;
            }
        }
    }
    for (int i = 0; i < md; i++)
        s[i] = slot[i];

    return totalp;
}

int main() {
    int n;
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];

    printf("Enter Job IDs, ps, and ds:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d (ID p d): ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].p, &jobs[i].d);
    }8

    char s[findmd(jobs, n)];
    int maxp = jobScheduling(jobs, n, s);

    printf("\nsd Jobs: ");
    for (int i = 0; i < findmd(jobs, n); i++)
        printf("%c ", s[i]);

    printf("\nMaximum Profit : %d\n", maxp);
    
    return 0;
}
