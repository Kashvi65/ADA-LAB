


typedef struct {
    int *ppp;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *qqq = (NumArray *)malloc(sizeof(NumArray));
    qqq->ppp = (int *)malloc(numsSize * sizeof(int));
    int i;
    for(i = 0;i < numsSize;i++){
        qqq->ppp[i] = nums[i];
    }
    return qqq;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int i;
    int summ = 0;
    for(i = left;i <= right;i++){
        summ += obj->ppp[i];
    }
    return summ;
}

void numArrayFree(NumArray* obj) {
    free(obj->ppp);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
