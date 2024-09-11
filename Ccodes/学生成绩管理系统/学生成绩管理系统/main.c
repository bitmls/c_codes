//----------------------------------------------------------------------------------------
//----------------------------------学生管理系统-------------------------------------------
//----------------------------------------------------------------------------------------
// 1.登录系统（需要输入密码判断是否可以登录）
// 2.录入学生信息（若输入学号相同则修改当前信息，学生成绩包括三门课程，C语言，高数，英语）
// 3.删除学生信息（1.依据学号删除，2.依据姓名删除）
// 4.查询学生信息
// 5.查询学生成绩
// 6.修改学生成绩
// 7.查询所有学生信息
// 8.查询所有学生成绩
// 9.排序学生成绩（冒泡，1.按C语言成绩排序，2.高数，3.英语）
// 10.查看班级平均分
// 11.根据学号排序
// 12.从文件导入学生信息
// 13.保存学生信息到文件
// 14.退出系统
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

// 仅 visual studio 编译环境需添加此行代码
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#define STUDENT_MAX  100

// 定义成绩类
typedef struct {
	int c_language;			// C语言成绩
	int math;				// 高数成绩
	int english;			// 英语成绩
}Score;

// 定义学生类
typedef struct {
	int id;					// 学号
	char name[20];			// 姓名
	char sex[10];			// 性别
	int age;				// 年龄
	Score score;			// 学生成绩
}Student;

// 定义班级类
typedef struct {
	Student students[STUDENT_MAX];	// 班级内学生
	int student_max;				// 当前班内已有人数
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
	// 系统是否运行
	int is_running = 1;

	Class class_1;

	class_init(&class_1);

	// 输入密码阶段
	while (1) {
		int key = 0;
		printf("请输入登录密码：");
		scanf("%d", &key);
		if (key == 1234) {
			printf("登录成功！\n");

			// 暂停函数
			system("pause");
			// 清屏函数
			system("cls");

			break;
		}
		else {
			printf("密码错误，请重新输入\n");

			system("pause");
			system("cls");
		}
	}

	while (is_running) {
		int input;

		system("cls");

		menu();
		printf("请输入：");
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
		default:	printf("输入错误\n");						break;
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
	printf(" ***     学生成绩管理系统     *** \n");
	printf("-----------------------------------\n");
	printf("***********************************\n");
	printf("*****  1.录入学生信息         *****\n");
	printf("*****  2.删除学生信息         *****\n");
	printf("*****  3.查询学生信息         *****\n");
	printf("*****  4.查询学生成绩         *****\n");
	printf("*****  5.修改学生成绩         *****\n");
	printf("*****  6.查询所有学生信息     *****\n");
	printf("*****  7.查询所有学生成绩     *****\n");
	printf("*****  8.排序学生成绩         *****\n");
	printf("*****  9.查看班级平均分       *****\n");
	printf("*****  10.根据学号排序        *****\n");
	printf("*****  11.从文件导入学生信息  *****\n");
	printf("*****  12.保存学生信息到文件  *****\n");
	printf("*****  0.退出系统             *****\n");
	printf("***********************************\n");
}

void insert_student_infomation(Class* class) {
	// 判断是否超出容量上限
	if (class->student_max >= STUDENT_MAX) {
		printf("班级人数超过上限，无法添加\n");
		return;
	}

	// 创建学生临时变量
	Student current_student;
	// 需要插入学生列表的位置
	int current_index = class->student_max;

	printf("请输入学号：");
	scanf("%d", &current_student.id);
	printf("请输入姓名：");
	scanf("%s", &current_student.name);
	printf("请输入性别：");
	scanf("%s", &current_student.sex);
	printf("请输入年龄：");
	scanf("%d", &current_student.age);
	printf("请输入C语言成绩：");
	scanf("%d", &current_student.score.c_language);
	printf("请输入高数成绩：");
	scanf("%d", &current_student.score.math);
	printf("请输入英语成绩：");
	scanf("%d", &current_student.score.english);

	// 判断输入的学生id是否已经存在于列表中，若存在，则直接修改当前学生信息
	for (int i = 0; i < class->student_max; i++)
		if (class->students[i].id == current_student.id)
			current_index = i;

	// 将输入好的学生信息传入班级结构体
	class->students[current_index] = current_student;
	// 若不为修改信息，信息传入完成后，将班级人数加1
	if(current_index == class->student_max)
		class->student_max++;

	system("cls");
	
	printf("学生信息添加成功，当前班级人数为%d\n", class->student_max);

	system("pause");
}

void delete_student_infomation(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	int input;
	int id;				// 用于存储输入的id
	char name[20];		// 用于存储输入的姓名

	system("cls");

	printf("1.按学生学号删除\n");
	printf("2.按学生姓名删除\n");
	printf("0.退出\n");
	printf("请输入：");
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("请输入学号：");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// 若查找到对应学生 id 号
			if (id == class->students[i].id) {
				// 将要删除学生后面的学生信息向前移动并覆盖前面的信息
				for (int j = i; j <= class->student_max - 1; j++) {
					class->students[j] = class->students[j + 1];
				}
				// 将学生人数减 1
				class->student_max--;
				printf("删除成功！\n");
				break;
			}
			// 若查询到最后一个学生都没有找到对应 id 号
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 2:
		printf("请输入姓名：");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// 注意！！！ strcmp 判断两个字符串如果是相同则返回 0
			if (!strcmp(name, class->students[i].name)) {
				// 将要删除学生后面的学生信息向前移动并覆盖前面的信息
				for (int j = i; j <= class->student_max - 1; j++) {
					class->students[j] = class->students[j + 1];
				}
				// 将学生人数减 1
				class->student_max--;
				printf("删除成功！\n");
				break;
			}
			// 若查询到最后一个学生都没有找到对应 姓名
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 0:
		printf("退出\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	system("pause");
}

void check_student_infomation(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	int input;
	int id;				// 用于存储输入的 id
	char name[20];		// 用于存储输入的 姓名

	system("cls");

	printf("1.按学生学号查询\n");
	printf("2.按学生姓名查询\n");
	printf("0.退出\n");
	printf("请输入：");
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("请输入学号：");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// 若查找到对应学生 id 号
			if (id == class->students[i].id) {
				printf("当前学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// 若查询到最后一个学生都没有找到对应 id 号
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 2:
		printf("请输入姓名：");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// 注意！！！ strcmp 判断两个字符串如果是相同则返回 0
			if (!strcmp(name, class->students[i].name)) {
				printf("当前学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// 若查询到最后一个学生都没有找到对应姓名
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 0:
		printf("退出\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	system("pause");
}

void check_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	int input;
	int id;				// 用于存储输入的id
	char name[20];		// 用于存储输入的姓名

	printf("1.按学生学号查询\n");
	printf("2.按学生姓名查询\n");
	printf("0.退出\n");
	printf("请输入：");
	scanf("%d", &input);

	system("cls");

	switch (input) {
	case 1:
		printf("请输入学号：");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// 若查找到对应学生 id 号
			if (id == class->students[i].id) {
				printf("当前学生 C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// 若查询到最后一个学生都没有找到对应id号
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 2:
		printf("请输入姓名：");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// 注意！！！ strcmp 判断两个字符串如果是相同则返回 0
			if (!strcmp(name, class->students[i].name)) {
				printf("当前学生 C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				break;
			}
			// 若查询到最后一个学生都没有找到对应姓名
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 0:
		printf("退出\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	system("pause");
}

void modify_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	int input;
	int id;				// 用于存储输入的 id
	char name[20];		// 用于存储输入的 姓名

	system("cls");

	printf("1.按学生学号查询\n");
	printf("2.按学生姓名查询\n");
	printf("0.退出\n");
	printf("请输入：");
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("请输入学号：");
		scanf("%d", &id);
		for (int i = 0; i < class->student_max; i++) {
			// 若查找到对应学生 id 号
			if (id == class->students[i].id) {
				printf("当前学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				printf("请输入修改后的信息：\n");

				// 创建学生临时变量
				Student current_student;

				printf("请输入学号：");
				scanf("%d", &current_student.id);
				printf("请输入姓名：");
				scanf("%s", &current_student.name);
				printf("请输入性别：");
				scanf("%s", &current_student.sex);
				printf("请输入年龄：");
				scanf("%d", &current_student.age);
				printf("请输入C语言成绩：");
				scanf("%d", &current_student.score.c_language);
				printf("请输入高数成绩：");
				scanf("%d", &current_student.score.math);
				printf("请输入英语成绩：");
				scanf("%d", &current_student.score.english);

				class->students[i] = current_student;

				break;
			}
			// 若查询到最后一个学生都没有找到对应 id 号
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 2:
		printf("请输入姓名：");
		scanf("%s", name);
		for (int i = 0; i < class->student_max; i++) {
			// 注意！！！ strcmp 判断两个字符串如果是相同则返回 0
			if (!strcmp(name, class->students[i].name)) {
				printf("当前学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
					class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
					class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
				printf("请输入修改后的信息：\n");

				// 创建学生临时变量
				Student current_student;

				printf("请输入学号：");
				scanf("%d", &current_student.id);
				printf("请输入姓名：");
				scanf("%s", &current_student.name);
				printf("请输入性别：");
				scanf("%s", &current_student.sex);
				printf("请输入年龄：");
				scanf("%d", &current_student.age);
				printf("请输入C语言成绩：");
				scanf("%d", &current_student.score.c_language);
				printf("请输入高数成绩：");
				scanf("%d", &current_student.score.math);
				printf("请输入英语成绩：");
				scanf("%d", &current_student.score.english);

				class->students[i] = current_student;

				break;
			}
			// 若查询到最后一个学生都没有找到对应姓名
			if (i == class->student_max - 1)
				printf("未查询到该学生\n");
		}
		break;
	case 0:
		printf("退出\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	system("pause");
}

void check_all_student_infomation(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	printf("班级人数为 %d\n", class->student_max);
	for (int i = 0; i < class->student_max; i++) {
		printf("学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
			class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
			class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
	}

	system("pause");
}

void check_all_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	printf("班级人数为 %d\n", class->student_max);
	for (int i = 0; i < class->student_max; i++) {
		printf("学生 姓名 %s ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
			class->students[i].name, class->students[i].score.c_language,
			class->students[i].score.math, class->students[i].score.english);
	}

	system("pause");
}

void sort_by_student_score(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	int input;

	printf("1.按C语言成绩排序\n");
	printf("2.按高数成绩排序\n");
	printf("3.按英语成绩排序\n");
	printf("0.退出\n");
	printf("请输入：");
	scanf("%d", &input);

	system("cls");

	switch (input) {
	// 按 C语言成绩 从高到低排序
	case 1:
		// 冒泡排序
		for (int i = 0; i < class->student_max - 1; i++) {
			for (int j = 0; j < class->student_max - i - 1; j++) {
				if (class->students[j].score.c_language < class->students[j + 1].score.c_language) {
					Student temp = class->students[j];
					class->students[j] = class->students[j + 1];
					class->students[j + 1] = temp;
				}
			}
		}

		// 排序结束后打印结果
		printf("班级人数为 %d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			printf("学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
				class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
				class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
		}

		break;
	// 按 高数成绩 从高到低排序
	case 2: 
		// 冒泡排序
		for (int i = 0; i < class->student_max - 1; i++) {
			for (int j = 0; j < class->student_max - i - 1; j++) {
				if (class->students[j].score.math < class->students[j + 1].score.math) {
					Student temp = class->students[j];
					class->students[j] = class->students[j + 1];
					class->students[j + 1] = temp;
				}
			}
		}

		// 排序结束后打印结果
		printf("班级人数为 %d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			printf("学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
				class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
				class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
		}
		break;
	// 按 英语成绩 从高到底排序
	case 3:
		// 冒泡排序
		for (int i = 0; i < class->student_max - 1; i++) {
			for (int j = 0; j < class->student_max - i - 1; j++) {
				if (class->students[j].score.english < class->students[j + 1].score.english) {
					Student temp = class->students[j];
					class->students[j] = class->students[j + 1];
					class->students[j + 1] = temp;
				}
			}
		}

		// 排序结束后打印结果
		printf("班级人数为 %d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			printf("学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
				class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
				class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
		}
		break;
	case 0:
		printf("退出\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	system("pause");
}

void check_average_score(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	// 三门课程的平均成绩
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

	printf("班级平均成绩 C语言 %.2f ，高数 %.2f ，英语 %.2f\n",
		average_score_c_language, average_score_math, average_score_english);

	system("pause");
}

void sort_by_student_id(Class* class) {
	if (class->student_max <= 0) {
		printf("当前学生列表为空\n");

		system("pause");

		return;
	}

	// 冒泡排序，从小到大排列
	for (int i = 0; i < class->student_max - 1; i++) {
		for (int j = 0; j < class->student_max - i - 1; j++) {
			if (class->students[j].id > class->students[j + 1].id) {
				Student temp = class->students[j];
				class->students[j] = class->students[j + 1];
				class->students[j + 1] = temp;
			}
		}
	}

	// 排序结束后打印结果
	printf("班级人数为 %d\n", class->student_max);
	for (int i = 0; i < class->student_max; i++) {
		printf("学生 id %d ，姓名 %s ，性别 %s ，年龄 %d ，C语言成绩 %d ，高数成绩 %d ，英语成绩 %d\n",
			class->students[i].id, class->students[i].name, class->students[i].sex, class->students[i].age,
			class->students[i].score.c_language, class->students[i].score.math, class->students[i].score.english);
	}

	system("pause");
}

void import_student_infomatin(Class* class) {
	// 定义一个 FILE 类型的指针
	FILE* fp;

	// 以只读模式打开文件
	fp = fopen("student_infomation.txt", "r");

	if (fp != NULL) {
		fscanf(fp, "%d", &class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			fscanf(fp, "%d %s %s %d %d %d %d", &class->students[i].id, &class->students[i].name,
				&class->students[i].sex, &class->students[i].id, &class->students[i].score.c_language,
				&class->students[i].score.math, &class->students[i].score.english);
		}

		printf("写入成功！\n");
	}
	else {
		printf("文件不存在\n");
	}

	fclose(fp);

	system("pause");
}

void save_student_infoamtion(Class* class) {
	// 定义一个 FILE 类型的指针
	FILE* fp;

	// 以只写模式打开文件，若文件存在则将原文件删除重写
	fp = fopen("student_infomation.txt", "w");

	// 判断文件是否创建成功
	if (fp != NULL) {
		// 若创建成功则将学生信息以下列格式写入文件
		fprintf(fp, "%d\n", class->student_max);
		for (int i = 0; i < class->student_max; i++) {
			fprintf(fp, "%d %s %s %d %d %d %d\n", class->students[i].id, class->students[i].name,
				class->students[i].sex, class->students[i].id, class->students[i].score.c_language,
				class->students[i].score.math, class->students[i].score.english);
		}
	}

	fclose(fp);

	printf("保存成功！\n");

	system("pause");
}

void exit_system(int* is_running) {
	*is_running = 0;

	printf("退出成功\n");

	system("pause");
}
