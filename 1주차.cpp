#include <stdio.h>

int main() {
    int num_products;  // 상품 종류 수
    int stock[100] = { 0 };  // 재고를 저장할 배열 (최대 100개의 상품)
    int product_id, quantity, total_stock = 0;

    // 1. 상품 종류 설정
    printf("판매할 상품의 종류 수를 입력하세요 (1~100): ");
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > 100) {
        printf("상품의 종류는 1에서 100 사이여야 합니다.\n");
        return 0;  // 잘못된 입력 시 프로그램 종료
    }

    // 2. 각 상품의 입고 수량 입력
    for (int i = 0; i < num_products; i++) {
        printf("상품 ID %d의 입고 수량을 입력하세요: ", i + 1);
        scanf("%d", &quantity);
        stock[i] = quantity;  // 재고 배열에 저장
    }

    // 3. 판매 수량 입력
    while (1) {
        printf("판매할 상품의 ID를 입력하세요 (종료하려면 0 입력): ");
        scanf("%d", &product_id);

        if (product_id == 0) {
            break;  // 입력이 0이면 반복문 종료
        }

        if (product_id < 1 || product_id > num_products) {
            printf("잘못된 상품 ID입니다.\n");
            continue;  // 잘못된 상품 ID일 경우 다시 입력받음
        }

        printf("상품 ID %d의 판매 수량을 입력하세요: ", product_id);
        scanf("%d", &quantity);

        // 4. 재고 확인 및 판매 처리
        if (stock[product_id - 1] >= quantity) {
            stock[product_id - 1] -= quantity;
            printf("상품 ID %d의 남은 재고: %d\n", product_id, stock[product_id - 1]);
        }
        else {
            printf("재고가 부족합니다. 현재 재고: %d\n", stock[product_id - 1]);
        }

        // 5. 전체 재고 수량 출력
        total_stock = 0;
        for (int i = 0; i < num_products; i++) {
            total_stock += stock[i];
        }
        printf("전체 재고 수량: %d\n", total_stock);
    }

    return 0;
}
