//----------------------------------------------------------------------------------------
//----------------------------------ѧ������ϵͳ-------------------------------------------
//----------------------------------------------------------------------------------------
// 1.��¼ϵͳ����Ҫ���������ж��Ƿ���Ե�¼��
// 2.¼��ѧ����Ϣ��������ѧ����ͬ���޸ĵ�ǰ��Ϣ��ѧ���ɼ��������ſγ̣�C���ԣ�������Ӣ�
// 3.ɾ��ѧ����Ϣ��1.����ѧ��ɾ����2.��������ɾ����
// 4.��ѯѧ����Ϣ
// 5.��ѯѧ���ɼ�
// 6.�޸�ѧ���ɼ�
// 7.��ѯ����ѧ����Ϣ
// 8.��ѯ����ѧ���ɼ�
// 9.����ѧ���ɼ���ð�ݣ�1.��C���Գɼ�����2.������3.Ӣ�
// 10.�鿴�༶ƽ����
// 11.����ѧ������
// 12.���ļ�����ѧ����Ϣ
// 13.����ѧ����Ϣ���ļ�
// 14.�˳�ϵͳ
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

// �� visual studio ���뻷������Ӵ��д���
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#define STUDENT_MAX  100

// ����ɼ���
typedef struct {
	int c_language;			// C���Գɼ�
	int math;				// �����ɼ�
	int english;			// Ӣ��ɼ�
}Score;

// ����ѧ����
typedef struct {
	int id;					// ѧ��
	char name[20];			// ����
	char sex[10];			// �Ա�
	int age;				// ����
	Score score;			// ѧ���ɼ�
}Student;

// ����༶��
typedef struct {
	Student students[STUDENT_MAX];	// �༶��ѧ��
	int student_max;				// ��ǰ������������
}Class;

void class_init(Class* class);
void menu();
void insert_student_infomation(Class* class);
void delete_student_infomation(Class* class);
void check_student_infomation(Class* class);
void check_student_score(Class* class);
void modify_student_score(Class* class);
void check_all_student_infomation(Class* class);
void check_all_student_score(Class* class);
void sort_by_student_score(Class* class);
void check_average_score(Class* class);
void sort_by_student_id(Class* class);
void import_student_infomatin(Class* class);
void save_student_infoamtion(Class* class);
void exit_system(int* is_running);


int main() {
	// ϵͳ�Ƿ�����
	int is_running = 1;

	Class class_1;

	class_init(&class_1);

	// ��������׶�
	while (1) {
		int key = 0;
		printf("�������¼���룺");
		scanf("%d", &key);
		if (key == 1234) {
			printf("��¼�ɹ���\n");

			// ��ͣ����
			system("pause");
			// ��������
			system("cls");

			break;
		}
		else {
			printf("�����������������\n");

			system("pause");
			system("cls");
		}
	}

	while (is_running) {
		int input;

		system("cls");

		menu();
		printf("�����룺");
		scanf("%d", &input);

		system("cls");

		switch (input) {
		case 1:		insert_student_infomation(&class_1);		break;
		case 2:		delete_student_infomation(&class_1);		break;
		case 3:		check_student_infomation(&class_1);			break;
		case 4:		check_student_score(&class_1);				break;
		case 5:		modify_student_score(&class_1);				break;
		case 6:		check_all_student_infomation(&class_1);		break;
		case 7:		check_all_student_score(&class_1);			break;
		case 8:		sort_by_student_score(&class_1);			break;
		case 9:		check_average_score(&class_1);				break;
		case 10:	sort_by_student_id(&class_1);				break;
		case 11:	import_student_infomatin(&class_1);			break;
		case 12:	save_student_infoamtion(&class_1);			break;
		case 0:		exit_system(&is_running);					break;
		default:	printf("�������\n");						break;
		}
	}

	return 0;
}

void class_init(Class* class) {
	class->student_max = 0;
	for (int i = 0; i < STUDENT_MAX; i++) {
		class->students[i].id = -1;
		strcpy(class->students[i].name, "empty");
		strcpy(class->students[i].sex, "empty");
		class->students[i].age = 0;
		class->students[i].score.c_language = 0;
		class->students[i].score.math = 0;
		class->students[i].score.english = 0;
	}
}

void menu() {
	printf("-----------------------------------\n");
	printf(" ***     ѧ���ɼ�����ϵͳ     *** \n");
	printf("-----------------------------------\n");
	printf("***********************************\n");
	printf("*****  1.¼��ѧ����Ϣ         *****\n");
	printf("*****  2.ɾ��ѧ����Ϣ         *****\n");
	printf("*****  3.��ѯѧ����Ϣ         *****\n");
	printf("*****  4.��ѯѧ���ɼ�         *****\n");
	printf("*****  5.�޸�ѧ���ɼ�         *****\n");
	printf("*****  6.��ѯ����ѧ����Ϣ     *****\n");
	printf("*****  7.��ѯ����ѧ���ɼ�     *****\n");
	printf("*****  8.����ѧ���ɼ�         *****\n");
	printf("*****  9.�鿴�༶ƽ����       *****\n");
	printf("*****  10.����ѧ������        *****\n");
	printf("*****  11.���ļ�����ѧ����Ϣ  *****\n");
	printf("*****  12.����ѧ����Ϣ���ļ�  *****\n");
	printf("*****  0.�˳�ϵͳ             *****\n");
	printf("***********************************\n");
}

void insert_student_infomation(Class* class) {
	// �ж��Ƿ񳬳���������
	if (class->student_max >= STUDENT_MAX) {
		printf("�༶�����������ޣ��޷����\n");
		return;
	}

	// ����ѧ����ʱ����
	Student current_student;
	// ��Ҫ����ѧ���б��λ��
	int current_index = class->student_max;

	printf("������ѧ�ţ�");
	scanf("%d", &current_student.id);
	printf("������������");
	scanf("%s", &current_student.name);
	printf("�������Ա�");
	scanf("%s", &current_student.sex);
	printf("���������䣺");
	scanf("%d", &current_student.age);
	printf("������C���Գɼ���");
	scanf("%d", &current_student.score.c_language);
	printf("����������ɼ���");
	scanf("%d", &current_student.score.math);
	printf("������Ӣ��ɼ���");
	scanf("%d", &current_student.score.english);

	// �ж������ѧ��id�Ƿ��Ѿ��������б��У������ڣ���ֱ���޸ĵ�ǰѧ����Ϣ
	for (int i = 0; i < class->student_max; i++)
		if (class->students[i].id == current_student.id)
			current_index = i;

	// ������õ�ѧ����Ϣ����༶�ṹ��
	class->students[current_index] = current_student;
	// ����Ϊ�޸���Ϣ����Ϣ������ɺ󣬽��༶������1
	if(current_index == class->student_max)
		class->student_max++;

	system("cls");
	
	printf("ѧ����Ϣ��ӳɹ�����ǰ�༶����Ϊ%d\n", class->student_max);

	system("pause");
}

void delete_student_infomation(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	int input;
	int id;				// ���ڴ洢�����id
	char name[20];		// ���ڴ洢���������

	system("cls");

	printf("1.��ѧ��ѧ��ɾ��\n");
	printf("2.��ѧ������ɾ��\n");
	printf("0.�˳�\n");
	printf("�����룺");
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("������ѧ�ţ�");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// �����ҵ���Ӧѧ�� id ��
			if (id == class->students[i].id) {
				// ��Ҫɾ��ѧ�������ѧ����Ϣ��ǰ�ƶ�������ǰ�����Ϣ
				for (int j = i; j <= class->student_max - 1; j++) {
					class->students[j] = class->students[j + 1];
				}
				// ��ѧ�������� 1
				class->student_max--;
				printf("ɾ���ɹ���\n");
				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ id ��
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 2:
		printf("������������");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// ע�⣡���� strcmp �ж������ַ����������ͬ�򷵻� 0
			if (!strcmp(name, class->students[i].name)) {
				// ��Ҫɾ��ѧ�������ѧ����Ϣ��ǰ�ƶ�������ǰ�����Ϣ
				for (int j = i; j <= class->student_max - 1; j++) {
					class->students[j] = class->students[j + 1];
				}
				// ��ѧ�������� 1
				class->student_max--;
				printf("ɾ���ɹ���\n");
				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ ����
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 0:
		printf("�˳�\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	system("pause");
}

void check_student_infomation(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	int input;
	int id;				// ���ڴ洢����� id
	char name[20];		// ���ڴ洢����� ����

	system("cls");

	printf("1.��ѧ��ѧ�Ų�ѯ\n");
	printf("2.��ѧ��������ѯ\n");
	printf("0.�˳�\n");
	printf("�����룺");
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("������ѧ�ţ�");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// �����ҵ���Ӧѧ�� id ��
			if (id == class->students[i].id) {
				printf("��ǰѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ id ��
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 2:
		printf("������������");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// ע�⣡���� strcmp �ж������ַ����������ͬ�򷵻� 0
			if (!strcmp(name, class->students[i].name)) {
				printf("��ǰѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ����
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 0:
		printf("�˳�\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	system("pause");
}

void check_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	int input;
	int id;				// ���ڴ洢�����id
	char name[20];		// ���ڴ洢���������

	printf("1.��ѧ��ѧ�Ų�ѯ\n");
	printf("2.��ѧ��������ѯ\n");
	printf("0.�˳�\n");
	printf("�����룺");
	scanf("%d", &input);

	system("cls");

	switch (input) {
	case 1:
		printf("������ѧ�ţ�");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// �����ҵ���Ӧѧ�� id ��
			if (id == class->students[i].id) {
				printf("��ǰѧ�� C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧid��
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 2:
		printf("������������");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// ע�⣡���� strcmp �ж������ַ����������ͬ�򷵻� 0
			if (!strcmp(name, class->students[i].name)) {
				printf("��ǰѧ�� C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ����
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 0:
		printf("�˳�\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	system("pause");
}

void modify_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	int input;
	int id;				// ���ڴ洢����� id
	char name[20];		// ���ڴ洢����� ����

	system("cls");

	printf("1.��ѧ��ѧ�Ų�ѯ\n");
	printf("2.��ѧ��������ѯ\n");
	printf("0.�˳�\n");
	printf("�����룺");
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("������ѧ�ţ�");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// �����ҵ���Ӧѧ�� id ��
			if (id == class->students[i].id) {
				printf("��ǰѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				printf("�������޸ĺ����Ϣ��\n");

				// ����ѧ����ʱ����
				Student current_student;

				printf("������ѧ�ţ�");
				scanf("%d", &current_student.id);
				printf("������������");
				scanf("%s", &current_student.name);
				printf("�������Ա�");
				scanf("%s", &current_student.sex);
				printf("���������䣺");
				scanf("%d", &current_student.age);
				printf("������C���Գɼ���");
				scanf("%d", &current_student.score.c_language);
				printf("����������ɼ���");
				scanf("%d", &current_student.score.math);
				printf("������Ӣ��ɼ���");
				scanf("%d", &current_student.score.english);

				class->students[i] = current_student;

				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ id ��
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 2:
		printf("������������");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// ע�⣡���� strcmp �ж������ַ����������ͬ�򷵻� 0
			if (!strcmp(name, class->students[i].name)) {
				printf("��ǰѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				printf("�������޸ĺ����Ϣ��\n");

				// ����ѧ����ʱ����
				Student current_student;

				printf("������ѧ�ţ�");
				scanf("%d", &current_student.id);
				printf("������������");
				scanf("%s", &current_student.name);
				printf("�������Ա�");
				scanf("%s", &current_student.sex);
				printf("���������䣺");
				scanf("%d", &current_student.age);
				printf("������C���Գɼ���");
				scanf("%d", &current_student.score.c_language);
				printf("����������ɼ���");
				scanf("%d", &current_student.score.math);
				printf("������Ӣ��ɼ���");
				scanf("%d", &current_student.score.english);

				class->students[i] = current_student;

				break;
			}
			// ����ѯ�����һ��ѧ����û���ҵ���Ӧ����
			if (i == class->student_max - 1)
				printf("δ��ѯ����ѧ��\n");
		}
		break;
	case 0:
		printf("�˳�\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	system("pause");
}

void check_all_student_infomation(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	printf("�༶����Ϊ %d\n", class->student_max);
	for (int i = 0; i < class->student_max; i++) {
		printf("ѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
			class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
			class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
	}

	system("pause");
}

void check_all_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	printf("�༶����Ϊ %d\n", class->student_max);
	for (int i = 0; i < class->student_max; i++) {
		printf("ѧ�� ���� %s ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
			class->students[i].name, class->students[i].score.c_language,
			class->students[i].score.math, class->students[i].score.english);
	}

	system("pause");
}

void sort_by_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	int input;

	printf("1.��C���Գɼ�����\n");
	printf("2.�������ɼ�����\n");
	printf("3.��Ӣ��ɼ�����\n");
	printf("0.�˳�\n");
	printf("�����룺");
	scanf("%d", &input);

	system("cls");

	switch (input) {
	// �� C���Գɼ� �Ӹߵ�������
	case 1:
		// ð������
		for (int i = 0; i < class->student_max - 1; i++) {
			for (int j = 0; j < class->student_max - i - 1; j++) {
				if (class->students[j].score.c_language < class->students[j + 1].score.c_language) {
					Student temp = class->students[j];
					class->students[j] = class->students[j + 1];
					class->students[j + 1] = temp;
				}
			}
		}

		// ����������ӡ���
		printf("�༶����Ϊ %d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			printf("ѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
				class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
				class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
		}

		break;
	// �� �����ɼ� �Ӹߵ�������
	case 2: 
		// ð������
		for (int i = 0; i < class->student_max - 1; i++) {
			for (int j = 0; j < class->student_max - i - 1; j++) {
				if (class->students[j].score.math < class->students[j + 1].score.math) {
					Student temp = class->students[j];
					class->students[j] = class->students[j + 1];
					class->students[j + 1] = temp;
				}
			}
		}

		// ����������ӡ���
		printf("�༶����Ϊ %d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			printf("ѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
				class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
				class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
		}
		break;
	// �� Ӣ��ɼ� �Ӹߵ�������
	case 3:
		// ð������
		for (int i = 0; i < class->student_max - 1; i++) {
			for (int j = 0; j < class->student_max - i - 1; j++) {
				if (class->students[j].score.english < class->students[j + 1].score.english) {
					Student temp = class->students[j];
					class->students[j] = class->students[j + 1];
					class->students[j + 1] = temp;
				}
			}
		}

		// ����������ӡ���
		printf("�༶����Ϊ %d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			printf("ѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
				class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
				class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
		}
		break;
	case 0:
		printf("�˳�\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	system("pause");
}

void check_average_score(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	// ���ſγ̵�ƽ���ɼ�
	float average_score_c_language = 0;
	float average_score_math = 0;
	float average_score_english = 0;

	for (int i = 0; i < class->student_max; i++) {
		average_score_c_language += (float)class->students[i].score.c_language;
		average_score_math += (float)class->students[i].score.math;
		average_score_english += (float)class->students[i].score.english;
	}

	average_score_c_language /= class->student_max;
	average_score_math /= class->student_max;
	average_score_english /= class->student_max;

	printf("�༶ƽ���ɼ� C���� %.2f ������ %.2f ��Ӣ�� %.2f\n",
		average_score_c_language, average_score_math, average_score_english);

	system("pause");
}

void sort_by_student_id(Class* class) {
	if (class->student_max <= 0) {
		printf("��ǰѧ���б�Ϊ��\n");

		system("pause");

		return;
	}

	// ð�����򣬴�С��������
	for (int i = 0; i < class->student_max - 1; i++) {
		for (int j = 0; j < class->student_max - i - 1; j++) {
			if (class->students[j].id > class->students[j + 1].id) {
				Student temp = class->students[j];
				class->students[j] = class->students[j + 1];
				class->students[j + 1] = temp;
			}
		}
	}

	// ����������ӡ���
	printf("�༶����Ϊ %d\n", class->student_max);
	for (int i = 0; i < class->student_max; i++) {
		printf("ѧ�� id %d ������ %s ���Ա� %s ������ %d ��C���Գɼ� %d �������ɼ� %d ��Ӣ��ɼ� %d\n",
			class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
			class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
	}

	system("pause");
}

void import_student_infomatin(Class* class) {
	// ����һ�� FILE ���͵�ָ��
	FILE* fp;

	// ��ֻ��ģʽ���ļ�
	fp = fopen("student_infomation.txt", "r");

	if (fp != NULL) {
		fscanf(fp, "%d", &class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			fscanf(fp, "%d %s %s %d %d %d %d", &class->students[i].id, &class->students[i].name,
				&class->students[i].sex, &class->students[i].id, &class->students[i].score.c_language,
				&class->students[i].score.math, &class->students[i].score.english);
		}

		printf("д��ɹ���\n");
	}
	else {
		printf("�ļ�������\n");
	}

	fclose(fp);

	system("pause");
}

void save_student_infoamtion(Class* class) {
	// ����һ�� FILE ���͵�ָ��
	FILE* fp;

	// ��ֻдģʽ���ļ������ļ�������ԭ�ļ�ɾ����д
	fp = fopen("student_infomation.txt", "w");

	// �ж��ļ��Ƿ񴴽��ɹ�
	if (fp != NULL) {
		// �������ɹ���ѧ����Ϣ�����и�ʽд���ļ�
		fprintf(fp, "%d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			fprintf(fp, "%d %s %s %d %d %d %d\n", class->students[i].id, class->students[i].name,
				class->students[i].sex, class->students[i].id, class->students[i].score.c_language,
				class->students[i].score.math, class->students[i].score.english);
		}
	}

	fclose(fp);

	printf("����ɹ���\n");

	system("pause");
}

void exit_system(int* is_running) {
	*is_running = 0;

	printf("�˳��ɹ�\n");

	system("pause");
}
