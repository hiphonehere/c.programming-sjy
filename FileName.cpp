#include <stdio.h>

int main() {
    int num_products;  // ��ǰ ���� ��
    int stock[100] = { 0 };  // ��� ������ �迭 (�ִ� 100���� ��ǰ)
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

    // 1. ��ǰ ���� ����
    printf("�Ǹ��� ��ǰ�� ���� ���� �Է��ϼ��� (1~100): ");
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > 100) {
        printf("��ǰ�� ������ 1���� 100 ���̿��� �մϴ�.\n");
        return 0;  // �߸��� �Է� �� ���α׷� ����
    }

    while (1) {
        printf("���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.��ǰ��Ȳ, 4.��ǰ�� �Է�, 5.����): ");
        scanf("%d", &ch);

        if (ch == 1) { // �԰�
            int option;
            printf("�԰���� �Է�: ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����: ");
            scanf("%d", &option);

            if (option == 1) { // ��ü ��ǰ �԰� ���� �Է�
                int total_quantity;
                printf("��ü ��ǰ�� �԰� ������ �Է��ϼ���: ");
                scanf("%d", &total_quantity);
                for (int i = 0; i < num_products; i++) {
                    quantity[i] += total_quantity;
                    sum1 += total_quantity;
                }
            }
            else if (option == 2) { // �� ��ǰ �԰� ���� �Է�
                for (int i = 0; i < num_products; i++) {
                    printf("��ǰ ID %d�� �԰� ������ �Է��ϼ���: ", i + 1);
                    scanf("%d", &quantity[i]);
                    sum1 += quantity[i];
                }
            }
        }
        else if (ch == 2) { // �Ǹ�
            int option;
            printf("�Ǹż��� �Է�: ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����: ");
            scanf("%d", &option);

            if (option == 1) { // ��� ��ǰ �Ǹ� �Է�
                printf("��ü ��ǰ�� �Ǹ� ������ �Է��ϼ���: ");
                scanf("%d", &total_sales);
                for (int i = 0; i < num_products; i++) {
                    sales[i] += total_sales;
                    sum += total_sales;
                    quantity[i] -= total_sales;
                }
            }
            else if (option == 2) { // ���� ��ǰ �Ǹ� �Է�
                while (1) {
                    printf("�Ǹ��� ��ǰ�� ID�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
                    scanf("%d", &product_id);
                    if (product_id == 0) break;  // �Է��� 0�̸� ����

                    if (product_id < 1 || product_id > num_products) {
                        printf("�߸��� ��ǰ ID�Դϴ�.\n");
                        continue;  // �߸��� ��ǰ ID�� ��� �ٽ� �Է¹���
                    }

                    printf("��ǰ ID %d�� �Ǹ� ������ �Է��ϼ���: ", product_id);
                    int sale_qty;
                    scanf("%d", &sale_qty);

                    if (sale_qty > quantity[product_id - 1]) {
                        printf("��ǰ ID %d : ������(%d)\n", product_id, sale_qty - quantity[product_id - 1]);
                    }
                    else {
                        sales[product_id - 1] += sale_qty;
                        quantity[product_id - 1] -= sale_qty;
                        sum += sale_qty;  // �� �Ǹŷ��� �߰�
                    }
                }
            }
        }
        else if (ch == 3) { // ��ǰ ��Ȳ ���
            printf("��� ����:\n");
            for (int i = 0; i < num_products; i++) {
                printf("��ǰ ID %d: %d\n", i + 1, quantity[i]);
            }

            // �Ǹ��� ���
            if (sum1 > 0) {
                margin = (sum / (double)sum1) * 100;
                printf("�� �Ǹŷ�: %d (�Ǹ���: %.2lf%%)\n", sum, margin);
            }

            // ���� ���� �Ǹŵ� ��ǰ ã��
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

            printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", max_id, max_quantity);
            printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", min_id, min_quantity);
        }
        else if (ch == 4) {
            for (int j = 0;j < num_products;j++) {
                printf("ID %d ��ǰ��:", j + 1);
                scanf("%s", &item_name[j]);

            }
           
        }
        else if (ch == 5) { // ����
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }

    return 0;
}


