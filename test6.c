#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < numsSize; ++i) {
        two |= one & nums[i];
        one ^= nums[i];
        three = one & two;
        one &= ~three;
        two &= ~three;
    }
    return one;
}

int singleNumberFive(int* nums, int numsSize){
    int one = 0, two = 0, three = 0, four = 0, five = 0;
    for (int i = 0; i < numsSize; ++i){
        four |= one & two & three & nums[i];
        three ^= one & two & nums[i];
        two ^= one & nums[i];
        one ^= nums[i];
        five = one & two & three & four;
        one &= ~five;
        two &= ~five;
        three &= ~five;
        four &= ~five;
    }
    return one;
}

int main(){
    int nums[16] = {1,2,3,3,1,2,2,8,1,3,1,2,3,3,2,1};
    int s = singleNumberFive(nums, 16);
    printf("%d\n",s);
}