#include <stdio.h>
#include <stdbool.h>

int main() {
    int NOP, NOR, i, j;

    printf("Enter no. of Processes:\t");
    scanf("%d", &NOP);
    printf("Enter no. of Resource Types:\t");
    scanf("%d", &NOR);

    int Available[NOR], Maximum[NOP][NOR], Allocation[NOP][NOR], Need[NOP][NOR], work[NOR], SafeSequence[NOP];
    bool Finish[NOP], isSafe = true;

    printf("\nEnter Allocation Matrix\n");
    for (i = 0; i < NOP; i++) {
        for (j = 0; j < NOR; j++) {
            printf("Enter Allocation of P[%d] R[%d]:\t", i, j);
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix\n");
    for (i = 0; i < NOP; i++) {
        for (j = 0; j < NOR; j++) {
            printf("Enter Max Need of P[%d] R[%d]:\t", i, j);
            scanf("%d", &Maximum[i][j]);
        }
    }

    printf("\nEnter Available Resources\n");
    for (j = 0; j < NOR; j++) {
        printf("Enter Resources Available for R[%d]:\t", j);
        scanf("%d", &Available[j]);
    }

    for (i = 0; i < NOP; i++) {
        Finish[i] = false;
    }

    for (i = 0; i < NOP; i++) {
        for (j = 0; j < NOR; j++) {
            Need[i][j] = Maximum[i][j] - Allocation[i][j];
        }
    }

    for (j = 0; j < NOR; j++) {
        work[j] = Available[j];
    }

    int k = 0;
    while (k < NOP) {
        bool found = false;
        for (i = 0; i < NOP; i++) {
            if (!Finish[i]) {
                bool canAllocate = true;
                for (j = 0; j < NOR; j++) {
                    if (Need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (j = 0; j < NOR; j++) {
                        work[j] += Allocation[i][j];
                    }
                    SafeSequence[k++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            isSafe = false;
            break;
        }
    }

    if (isSafe) {
        printf("System is in Safe State\n");
        printf("Safe Sequence: ");
        for (i = 0; i < NOP; i++) {
            printf("P[%d] ", SafeSequence[i]);
        }
    } else {
        printf("\nSystem is in Unsafe State");
    }

    return 0;
}