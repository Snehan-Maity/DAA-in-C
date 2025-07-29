#include<stdio.h>
#include<stdlib.h>
struct item {
    int profit, weight;
    float ppw;
    int index;  // To store the original position
};
void bubble(struct item list[], int n) {
    int i, j;
    struct item temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(list[j].ppw < list[j+1].ppw) {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
void FractionalKnapsack(struct item list[], int n, float m) {
    bubble(list, n);
    float x[n];           // Fractions for sorted list
    float result[n];      // Fractions in original order
    float totalProfit = 0.0;
    float u = m;
    int i;
    for(i = 0; i < n; i++) {
        x[i] = 0.0;
        result[i] = 0.0;
    }
    for(i = 0; i < n; i++) {
        if(list[i].weight <= u) {
            x[i] = 1.0;
            totalProfit += list[i].profit;
            u -= list[i].weight;
        } else {
            x[i] = u / list[i].weight;
            totalProfit += x[i] * list[i].profit;
            break;
        }
    }
    // Map fractions back to original order
    for(i = 0; i < n; i++) {
        result[list[i].index] = x[i];
    }
    printf("\nFractions taken for each item (in original order): \n");
    for(i = 0; i < n; i++) {
        printf("%f\t", result[i]);
    }
    printf("\nTotal Profit: %.2f\n", totalProfit);
}
int main() {
    int n, i;
    float m;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the Knapsack capacity: ");
    scanf("%f", &m);
    struct item list[n];
    printf("Enter the profit and weight of the items: \n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &list[i].profit, &list[i].weight);
    }
    for(i = 0; i < n; i++) {
        list[i].ppw = (float)list[i].profit / list[i].weight;
        list[i].index = i;
    }
    FractionalKnapsack(list, n, m);
    return 0;
}
