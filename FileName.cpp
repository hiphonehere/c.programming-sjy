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
    int sales[100] = { 0 };
    int ch;
    int total_sales = 0;
    char item_name[] = { 0 };

    // 1. 상품 종류 설정
    printf("판매할 상품의 종류 수를 입력하세요 (1~100): ");
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > 100) {
        printf("상품의 종류는 1에서 100 사이여야 합니다.\n");
        return 0;  // 잘못된 입력 시 프로그램 종료
    }

    while (1) {
        printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.상품현황, 4.상품명 입력, 5.종료): ");
        scanf("%d", &ch);

        if (ch == 1) { // 입고
            int option;
            printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택: ");
            scanf("%d", &option);

            if (option == 1) { // 전체 상품 입고 수량 입력
                int total_quantity;
                printf("전체 상품의 입고 수량을 입력하세요: ");
                scanf("%d", &total_quantity);
                for (int i = 0; i < num_products; i++) {
                    quantity[i] += total_quantity;
                    sum1 += total_quantity;
                }
            }
            else if (option == 2) { // 각 상품 입고 수량 입력
                for (int i = 0; i < num_products; i++) {
                    printf("상품 ID %d의 입고 수량을 입력하세요: ", i + 1);
                    scanf("%d", &quantity[i]);
                    sum1 += quantity[i];
                }
            }
        }
        else if (ch == 2) { // 판매
            int option;
            printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택: ");
            scanf("%d", &option);

            if (option == 1) { // 모든 상품 판매 입력
                printf("전체 상품의 판매 수량을 입력하세요: ");
                scanf("%d", &total_sales);
                for (int i = 0; i < num_products; i++) {
                    sales[i] += total_sales;
                    sum += total_sales;
                    quantity[i] -= total_sales;
                }
            }
            else if (option == 2) { // 개별 상품 판매 입력
                while (1) {
                    printf("판매할 상품의 ID를 입력하세요 (종료하려면 0 입력): ");
                    scanf("%d", &product_id);
                    if (product_id == 0) break;  // 입력이 0이면 종료

                    if (product_id < 1 || product_id > num_products) {
                        printf("잘못된 상품 ID입니다.\n");
                        continue;  // 잘못된 상품 ID일 경우 다시 입력받음
                    }

                    printf("상품 ID %d의 판매 수량을 입력하세요: ", product_id);
                    int sale_qty;
                    scanf("%d", &sale_qty);

                    if (sale_qty > quantity[product_id - 1]) {
                        printf("상품 ID %d : 재고부족(%d)\n", product_id, sale_qty - quantity[product_id - 1]);
                    }
                    else {
                        sales[product_id - 1] += sale_qty;
                        quantity[product_id - 1] -= sale_qty;
                        sum += sale_qty;  // 총 판매량에 추가
                    }
                }
            }
        }
        else if (ch == 3) { // 상품 현황 출력
            printf("재고 수량:\n");
            for (int i = 0; i < num_products; i++) {
                printf("상품 ID %d: %d\n", i + 1, quantity[i]);
            }

            // 판매율 계산
            if (sum1 > 0) {
                margin = (sum / (double)sum1) * 100;
                printf("총 판매량: %d (판매율: %.2lf%%)\n", sum, margin);
            }

            // 가장 많이 판매된 상품 찾기
            max_quantity = sales[0];
            min_quantity = sales[0];
            max_id = 1;
            min_id = 1;

            for (int i = 1; i < num_products; i++) {
                if (sales[i] > max_quantity) {
                    max_quantity = sales[i];
                    max_id = i + 1;
                }
                if (sales[i] < min_quantity) {
                    min_quantity = sales[i];
                    min_id = i + 1;
                }
            }

            printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", max_id, max_quantity);
            printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", min_id, min_quantity);
        }
        else if (ch == 4) {
            for (int j = 0;j < num_products;j++) {
                printf("ID %d 상품명:", j + 1);
                scanf("%s", &item_name[j]);

            }
           
        }
        else if (ch == 5) { // 종료
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}


