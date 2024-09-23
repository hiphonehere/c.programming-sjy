#include <stdio.h>

int main() {
    int num_products;  // 상품 종류 수
    int stock[100] = { 0 };  // 재고를 저장할 배열 (최대 100개의 상품)
    int product_id, total_stock = 0;
    int quantity[100] = { 0 };
    int dequantity[100] = { 0 };
    int sum = 0;
    int sum1 = 0;
    int max_id = 0, max_quantity = 0;
    int min_id = 0, min_quantity = 0;
    double margin = 0.0;

    int ch;

    printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.상품현황, 4.종료):");
    ch = getchar();
    

    
    // 1. 상품 종류 설정
    printf("판매할 상품의 종류 수를 입력하세요 (1~100): ");
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > 100) {
        printf("상품의 종류는 1에서 100 사이여야 합니다.\n");
        return 0;  // 잘못된 입력 시 프로그램 종료
    }
    printf("입고수량 입력:")
    // 1. 전체 상품 입고 수량 입력
    // 2. 각 상품의 입고 수량 입력
    for (int i = 0; i < num_products; i++) {
        printf("상품 ID %d의 입고 수량을 입력하세요: ", i + 1);
        scanf("%d", &quantity[i]);
        sum1 += quantity[i]; // 총 입고 수량
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
        int sales;
        scanf("%d", &sales);

        // 4. 재고 부족 확인
        if (sales > quantity[product_id - 1]) {
            int shortage = sales - quantity[product_id - 1];
            printf("상품 ID %d : 재고부족(%d)\n", product_id, shortage);
        }
        else {
            dequantity[product_id - 1] += sales;  // 판매 수량 기록
        }
    }

    // 5. 가장 많이/적게 판매된 상품 찾기 및 전체 재고 수량 계산
    min_quantity = dequantity[0];  // 첫 상품의 판매량으로 초기화
    min_id = 1;  // 첫 상품 ID로 초기화

    for (int i = 0; i < num_products; i++) {
        sum += dequantity[i];  // 총 판매량

        // 가장 많이 판매된 상품 확인
        if (dequantity[i] > max_quantity) {
            max_quantity = dequantity[i];
            max_id = i + 1;  // 상품 ID는 1부터 시작
        }

        // 가장 적게 판매된 상품 확인
        if (dequantity[i] < min_quantity) {
            min_quantity = dequantity[i];
            min_id = i + 1;  // 상품 ID는 1부터 시작
        }
    }

    margin = (sum / (double)sum1) * 100;  // 판매율

    // 6. 재고 수량 출력
    printf("재고 수량: ");
    for (int i = 0; i < num_products; i++) {
        int remaining_stock = quantity[i] - dequantity[i];
        printf("%d\t", remaining_stock);
    }

    printf("\n");
    printf("총 판매량: %d (판매율: %.3lf%%)\n", sum, margin);

    // 7. 가장 많이 판매된 상품 출력
    if (max_quantity > 0) {
        printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", max_id, max_quantity);
    }
    else {
        printf("판매된 상품이 없습니다.\n");
    }

    // 8. 가장 적게 판매된 상품 출력
    if (min_quantity > 0) {
        printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", min_id, min_quantity);
    }

    return 0;
}

