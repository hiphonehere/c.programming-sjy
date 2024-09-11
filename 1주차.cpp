#include <stdio.h>

int main() {
    int num_products;  // ��ǰ ���� ��
    int stock[100] = { 0 };  // ��� ������ �迭 (�ִ� 100���� ��ǰ)
    int product_id, quantity, total_stock = 0;

    // 1. ��ǰ ���� ����
    printf("�Ǹ��� ��ǰ�� ���� ���� �Է��ϼ��� (1~100): ");
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > 100) {
        printf("��ǰ�� ������ 1���� 100 ���̿��� �մϴ�.\n");
        return 0;  // �߸��� �Է� �� ���α׷� ����
    }

    // 2. �� ��ǰ�� �԰� ���� �Է�
    for (int i = 0; i < num_products; i++) {
        printf("��ǰ ID %d�� �԰� ������ �Է��ϼ���: ", i + 1);
        scanf("%d", &quantity);
        stock[i] = quantity;  // ��� �迭�� ����
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
        scanf("%d", &quantity);

        // 4. ��� Ȯ�� �� �Ǹ� ó��
        if (stock[product_id - 1] >= quantity) {
            stock[product_id - 1] -= quantity;
            printf("��ǰ ID %d�� ���� ���: %d\n", product_id, stock[product_id - 1]);
        }
        else {
            printf("��� �����մϴ�. ���� ���: %d\n", stock[product_id - 1]);
        }

        // 5. ��ü ��� ���� ���
        total_stock = 0;
        for (int i = 0; i < num_products; i++) {
            total_stock += stock[i];
        }
        printf("��ü ��� ����: %d\n", total_stock);
    }

    return 0;
}
