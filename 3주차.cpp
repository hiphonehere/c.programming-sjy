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

    int ch;

    printf("���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.��ǰ��Ȳ, 4.����):");
    ch = getchar();
    

    
    // 1. ��ǰ ���� ����
    printf("�Ǹ��� ��ǰ�� ���� ���� �Է��ϼ��� (1~100): ");
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > 100) {
        printf("��ǰ�� ������ 1���� 100 ���̿��� �մϴ�.\n");
        return 0;  // �߸��� �Է� �� ���α׷� ����
    }
    printf("�԰���� �Է�:")
    // 1. ��ü ��ǰ �԰� ���� �Է�
    // 2. �� ��ǰ�� �԰� ���� �Է�
    for (int i = 0; i < num_products; i++) {
        printf("��ǰ ID %d�� �԰� ������ �Է��ϼ���: ", i + 1);
        scanf("%d", &quantity[i]);
        sum1 += quantity[i]; // �� �԰� ����
    }

    // 3. �Ǹ� ���� �Է�
    while (1) {
        printf("�Ǹ��� ��ǰ�� ID�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
        scanf("%d", &product_id);
        if (product_id == 0) {
            break;  // �Է��� 0�̸� �ݺ��� ����
        }
        if (product_id < 1 || product_id > num_products) {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
            continue;  // �߸��� ��ǰ ID�� ��� �ٽ� �Է¹���
        }
        printf("��ǰ ID %d�� �Ǹ� ������ �Է��ϼ���: ", product_id);
        int sales;
        scanf("%d", &sales);

        // 4. ��� ���� Ȯ��
        if (sales > quantity[product_id - 1]) {
            int shortage = sales - quantity[product_id - 1];
            printf("��ǰ ID %d : ������(%d)\n", product_id, shortage);
        }
        else {
            dequantity[product_id - 1] += sales;  // �Ǹ� ���� ���
        }
    }

    // 5. ���� ����/���� �Ǹŵ� ��ǰ ã�� �� ��ü ��� ���� ���
    min_quantity = dequantity[0];  // ù ��ǰ�� �Ǹŷ����� �ʱ�ȭ
    min_id = 1;  // ù ��ǰ ID�� �ʱ�ȭ

    for (int i = 0; i < num_products; i++) {
        sum += dequantity[i];  // �� �Ǹŷ�

        // ���� ���� �Ǹŵ� ��ǰ Ȯ��
        if (dequantity[i] > max_quantity) {
            max_quantity = dequantity[i];
            max_id = i + 1;  // ��ǰ ID�� 1���� ����
        }

        // ���� ���� �Ǹŵ� ��ǰ Ȯ��
        if (dequantity[i] < min_quantity) {
            min_quantity = dequantity[i];
            min_id = i + 1;  // ��ǰ ID�� 1���� ����
        }
    }

    margin = (sum / (double)sum1) * 100;  // �Ǹ���

    // 6. ��� ���� ���
    printf("��� ����: ");
    for (int i = 0; i < num_products; i++) {
        int remaining_stock = quantity[i] - dequantity[i];
        printf("%d\t", remaining_stock);
    }

    printf("\n");
    printf("�� �Ǹŷ�: %d (�Ǹ���: %.3lf%%)\n", sum, margin);

    // 7. ���� ���� �Ǹŵ� ��ǰ ���
    if (max_quantity > 0) {
        printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", max_id, max_quantity);
    }
    else {
        printf("�Ǹŵ� ��ǰ�� �����ϴ�.\n");
    }

    // 8. ���� ���� �Ǹŵ� ��ǰ ���
    if (min_quantity > 0) {
        printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", min_id, min_quantity);
    }

    return 0;
}

