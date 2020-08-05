#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(prices_len*sizeof(int));
    
    for(int i=0; i<prices_len; i++)
    {
        int cnt=0;
        int val=prices[i];
        
        for(int j=i+1; j<prices_len; j++)
        {
            cnt++;
            if(prices[j]<val)   break;
        }
        answer[i]=cnt;
    }
    
    return answer;
}