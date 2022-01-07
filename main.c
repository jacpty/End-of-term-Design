/*CSGO��Ʒ�������*/

/*��ɫ���ձ�
0 = ��ɫ                8 = ��ɫ����
1 = ��ɫ                9 = ����ɫ
2 = ��ɫ                10 = ����ɫ
3 = ����ɫ              11 = ��ǳ��ɫ
4 = ��ɫ                12 = ����ɫ
5 = ��ɫ                13 = ����ɫ
6 = ��ɫ                14 = ����ɫ
7 = ��ɫ                15 = ����ɫ*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#define WIDTH 120 //���������
#define STAR "******************************" //30���Ǻ�
#define LINE "------------------------------" //30������

typedef struct Item_mode //��Ʒģ��
{
	char numbering[10]; //��Ʒ���
	char origin[10];    //��������
	char name[40];      //��Ʒ����
	int level;          //��Ʒϡ�ж�
	int model;          //�����ͺ�
	int price;          //��Ʒ�۸�
	int inventory;      //�������
	int ordered;        //�Ѷ�������

	struct Item_mode* next;  //ָ����һ�ṹ���ָ��
}Item;

void set_color(int level);        //�ı䴰�ڱ�����ɫ��������ɫ
void output_split(char kind);     //��ӡ��ӭ�����еķָ���
void output_space(char str[]);    //��ӡ��ӭ�����еĿո�
void output_command(char str[]);  //��ӡ�����ÿ�����������ĸ���
void welcome(void);               //��ӭ���漯��
void welcome_admin(void);         //����Ա���漯��
void welcome_find(void);          //���ҽ��漯��
void welcome_item(void);          //���ҽ����ͷ
void print_cart(void);            //������ﳵ
int admin(void);				  //����Ա�˻�����
Item *add_item(int n);            //¼����Ʒ
void write_info(Item *node);      //��¼�����Ʒ���浽�ļ���
Item *read_info(void);            //���ļ��ж�ȡ��Ʒ��Ϣ
void delete_info(Item *node, char numb[]); //ɾ���ļ���ָ������Ʒ��Ϣ
void delete_cart(Item* node, char numb[]); //ɾ���ļ���ָ������Ʒ��Ϣ
void write_cart(Item* node);      //���û����빺�ﳵ������¼�뵽�ļ���
Item* read_cart(void);            //���ļ��ж�ȡ���ﳵ��Ϣ
void free_linked(Item *h);        //�ͷ��ڴ�

void set_color(int level) //�ı䴰�ڱ�����ɫ��������ɫ
{
	int number1, number2, number3, number4, number5;
	number1 = 240; //�׵׺���
	number2 = 244; //�׵׺���
	number3 = 253; //�׵׷���
	number4 = 245; //�׵�����
	number5 = 249; //�׵�����

	if (level == 0)      //�׵׺���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number1);
	else if (level == 1) //�׵׺���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number2);
	else if (level == 2) //�׵׷���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number3);
	else if (level == 3) //�׵�����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number4);
	else if (level == 4) //�׵�����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number5);
}

void output_split(char kind) //��ӡ��ӭ�����еķָ���
{
	int i;
	if (kind == 's')
	{
		for (i = 0; i < 4; i++)
			printf(STAR);
	}
	else if (kind == 'l')
	{
		for (i = 0; i < 4; i++)
			printf(LINE);
	}
}

void output_space(char str[]) //��ӡ��ӭ�����еĿո�
{
	int i, front, len;
	len = strlen(str);
	front = (WIDTH - len) / 2;
	for (i = 0; i < front; i++)
		printf(" ");
}

void output_command(char str[]) //��ӡ�����ÿ�����������ĸ���
{
	int i;
	for (i = 1; str[i] != '\0'; i++)
	{
		if (str[i - 1] == ' ' && isalpha(str[i])) //�ж�'str[i]'�Ƿ������������ĸ
		{
			set_color(1);
			printf("%c", str[i]);
			set_color(0);
		}
		else
			printf("%c", str[i]);
	}
	printf("\n");
}

int admin(void) //����Ա�˻�����
{
	char temp[100] = { 0 };    
	char account[10] = { 0 };  //�����û�������˻�
	char password[10] = { 0 }; //�����û����������
	int i, j, next = 0;

	//�����˺�
	for (i = 0; i < 3; i++)
	{
		printf("���������Ա�˺�: ");
		scanf_s("%s", temp, 10);
		strncpy(account, temp, 9); //��ȡǰ9����
		if (strcmp(account, "admin") == 0) //�ж��˻��Ƿ���ȷ
		{
			system("cls");
			printf("���������Ա����: ");
			memset(temp, 0, 100);
			next++;
			break;
		}
		else
		{
			system("cls");
			printf("���޴��˻������������룡\n");
		}
	}
	//��������
	if (next != 1)
		return 0;
	else
	{
		for (j = 0; j < 3; j++)
		{
			scanf_s("%s", temp, 10);
			strncpy(password, temp, 9); //��ȡǰ9����
			if (strcmp(password, "admin") == 0) //�ж������Ƿ���ȷ
				return 1;
			else
			{
				system("cls");
				printf("����������������룡\n");
				printf("����������: ");
			}
		}
	}
	return 0;
}

Item* add_item(int n) //¼����Ʒ���ļ���
{
	Item* head, * node, * end;
	int i;
	head = (Item*)malloc(sizeof(Item));
	end = head;

	for (i = 0; i < n; i++)
	{
		node = (Item*)malloc(sizeof(Item));
		printf("��%d����Ʒ\n", i+1);
		printf("���: ");
		scanf_s("\n");
		gets_s(node->numbering, 10);         //���
		printf("����: ");
		gets_s(node->name, 40);              //����
		printf("ϡ�ж�: ");
		scanf_s("%d", &node->level);         //ϡ�ж�
		printf("�ͺ�: ");
		scanf_s("%d", &node->model);         //�ͺ�
		printf("�۸�: ");
		scanf_s("%d", &node->price);         //�۸�
		printf("�������: ");
		scanf_s("%d", &node->inventory);     //�������
		printf("�Ѷ�������: ");
		scanf_s("%d", &node->ordered);       //�Ѷ�������
		printf("����: ");
		scanf_s("\n");
		gets_s(node->origin, 10);            //����
		printf("\n");
		write_info(node);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void write_info(Item *node) //��¼�����Ʒ���浽�ļ���
{
	FILE* fw_item = fopen("Item_info.txt", "a");
	if (fw_item == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	fprintf(fw_item, "%s\n", node->numbering);
	fprintf(fw_item, "%s\n", node->origin);
	fprintf(fw_item, "%s\n", node->name);
	fprintf(fw_item, "%d\n", node ->level);
	fprintf(fw_item, "%d\n", node->model);
	fprintf(fw_item, "%d\n", node->price);
	fprintf(fw_item, "%d\n", node->inventory);
	fprintf(fw_item, "%d\n", node->ordered);
	fclose(fw_item);
}

Item *read_info(void) //����ȡ��������д�뵽������
{
	FILE* fr_item = fopen("Item_info.txt", "r"); //���ļ�
	Item* head, * node, * end;
	int i = 0;
	int last;
	char numbering[10] = { 0 }; //��Ʒ���
	char origin[10] = { 0 };    //��������
	char name[40] = { 0 };      //��Ʒ����
	char empty;

	if (fr_item == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	head = (Item*)malloc(sizeof(Item));
	end = head;
	while (!feof(fr_item))
	{
		node = (Item*)malloc(sizeof(Item));
		//��Ʒ���
		fgets(numbering, 9, fr_item);
		last = strlen(numbering);
		numbering[last - 1] = '\0';
		strcpy(node->numbering, numbering);
		//��������
		fgets(origin, 9, fr_item);
		last = strlen(origin);
		origin[last - 1] = '\0';
		strcpy(node->origin, origin);
		//��Ʒ����
		fgets(name, 39, fr_item);
		last = strlen(name);
		name[last - 1] = '\0';
		strcpy(node->name, name);
		//��Ʒϡ�ж�
		fscanf_s(fr_item, "%d", &node->level);
		//�����ͺ�
		fscanf_s(fr_item, "%d", &node->model);
		//��Ʒ�۸�
		fscanf_s(fr_item, "%d", &node->price);
		//�������
		fscanf_s(fr_item, "%d", &node->inventory);
		//�Ѷ�������
		fscanf_s(fr_item, "%d", &node->ordered);
		fscanf_s(fr_item, "\t", &empty); //һ����ֵ�ԭ����Ҫ����ȥ����һ���Ʊ��

		end->next = node;
		end = node;
	}
	end->next = NULL;
	fclose(fr_item);

	return head;
}

void write_cart(Item* node) //��¼�����Ʒ���浽�ļ���
{
	FILE* fw_cart = fopen("Cart_info.txt", "a");
	if (fw_cart == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	fprintf(fw_cart, "%s\n", node->numbering);
	fprintf(fw_cart, "%s\n", node->origin);
	fprintf(fw_cart, "%s\n", node->name);
	fprintf(fw_cart, "%d\n", node->level);
	fprintf(fw_cart, "%d\n", node->model);
	fprintf(fw_cart, "%d\n", node->price);
	fprintf(fw_cart, "%d\n", node->inventory);
	fprintf(fw_cart, "%d\n", node->ordered);
	fclose(fw_cart);
}

void delete_info(Item *node, char numb[10]) //ɾ���ļ��е�����
{
	FILE* fw_item = fopen("Item_info.txt", "w+");
	if (fw_item == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	while (node->next != NULL)
	{
		node = node->next;
		if (strcmp(numb, node->numbering) != 0)
		{
			fprintf(fw_item, "%s\n", node->numbering);
			fprintf(fw_item, "%s\n", node->origin);
			fprintf(fw_item, "%s\n", node->name);
			fprintf(fw_item, "%d\n", node->level);
			fprintf(fw_item, "%d\n", node->model);
			fprintf(fw_item, "%d\n", node->price);
			fprintf(fw_item, "%d\n", node->inventory);
			fprintf(fw_item, "%d\n", node->ordered);
		}
		fclose(fw_item);
	}
}

void delete_cart(Item* node, char numb[10]) //ɾ�����ﳵ�е�����
{
	FILE* fw_cart = fopen("Cart_info.txt", "w+");
	if (fw_cart == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	while (node->next != NULL)
	{
		node = node->next;
		if (strcmp(numb, node->numbering) != 0)
		{
			fprintf(fw_cart, "%s\n", node->numbering);
			fprintf(fw_cart, "%s\n", node->origin);
			fprintf(fw_cart, "%s\n", node->name);
			fprintf(fw_cart, "%d\n", node->level);
			fprintf(fw_cart, "%d\n", node->model);
			fprintf(fw_cart, "%d\n", node->price);
			fprintf(fw_cart, "%d\n", node->inventory);
			fprintf(fw_cart, "%d\n", node->ordered);
		}
		fclose(fw_cart);
	}
}

Item* read_cart(void) //����ȡ��������д�뵽������
{
	FILE* fr_cart = fopen("Cart_info.txt", "r"); //���ļ�
	Item* head, * node, * end;
	int i = 0;
	int last;
	char numbering[10] = { 0 }; //��Ʒ���
	char origin[10] = { 0 };    //��������
	char name[40] = { 0 };      //��Ʒ����
	char empty;

	if (fr_cart == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	head = (Item*)malloc(sizeof(Item));
	end = head;
	while (!feof(fr_cart))
	{
		node = (Item*)malloc(sizeof(Item));
		//��Ʒ���
		fgets(numbering, 9, fr_cart);
		last = strlen(numbering);
		numbering[last - 1] = '\0';
		strcpy(node->numbering, numbering);
		//��������
		fgets(origin, 9, fr_cart);
		last = strlen(origin);
		origin[last - 1] = '\0';
		strcpy(node->origin, origin);
		//��Ʒ����
		fgets(name, 39, fr_cart);
		last = strlen(name);
		name[last - 1] = '\0';
		strcpy(node->name, name);
		//��Ʒϡ�ж�
		fscanf_s(fr_cart, "%d", &node->level);
		//�����ͺ�
		fscanf_s(fr_cart, "%d", &node->model);
		//��Ʒ�۸�
		fscanf_s(fr_cart, "%d", &node->price);
		//�������
		fscanf_s(fr_cart, "%d", &node->inventory);
		//�Ѷ�������
		fscanf_s(fr_cart, "%d", &node->ordered);
		fscanf_s(fr_cart, "\t", &empty); //һ����ֵ�ԭ����Ҫ����ȥ����һ���Ʊ��

		end->next = node;
		end = node;
	}
	end->next = NULL;
	fclose(fr_cart);

	return head;
}


void welcome(void) //��ӭ����
{
	char welcome1[] = { "��ӭ���� CSGO ��Ʒ�̵꣡" };
	char welcome2[] = { "��������Զ�����Ʒ��" };
	char welcome3[] = { "��������Ĵ�д��ĸִ�����" }; //��ʾ��������ķ���
	char welcome4[] = { " Admin:�������Ա�˻�    Find:������Ʒ    Shoppingcart:�鿴���ﳵ" }; //��ʾ����

	output_split('s');
	output_space(welcome1);  //��һ��
	printf("%s\n", welcome1);
	output_space(welcome2);  //�ڶ���
	printf("%s\n", welcome2);
	output_space(welcome3);  //������
	printf("%s\n", welcome3);
	output_space(welcome4);  //���ľ�
	output_command(welcome4);
	output_split('s');
	printf("\n");
}

void welcome_admin(void) //����ԱȨ�޻�ӭ����
{
	char admin1[] = { "�������Ѿ�ӵ���˹���ԱȨ�ޣ�" };
	char admin2[] = { "���:1��ǹ 2�������� 3���ǹ 4��ǹ 5��" };
	char admin3[] = { "ϡ�ж�:1���� 2���� 3���� 4���漶" };
	char admin4[] = { " Add:������Ʒ    Delete:ɾ����Ʒ" };

	output_split('s');
	output_space(admin1);
	printf("%s\n", admin1);
	output_space(admin2);
	printf("%s\n", admin2);
	output_space(admin3);
	printf("%s\n", admin3);
	output_space(admin4);
	output_command(admin4);
	output_split('s');
	printf("\n");
}

void welcome_find(void) //���һ�ӭ����
{
	char find1[] = { "��������԰����¼��ַ�ʽ��ѯ����Ҫ����Ʒ��" };
	char find2[] = { " All:չʾȫ��    Model:���ͺŲ���    Name:�����ֲ���    Type:�����Ͳ���" };
	output_split('s');
	output_space(find1);
	printf("%s\n", find1);
	output_space(find2);
	output_command(find2);
	output_split('s');
	printf("\n");
}

void welcome_item(void) //��Ʒ��ͷ
{
	system("cls");
	output_split('l');
	printf("���\t����\t\t\t\t�ͺ�\t�۸�\t�������\t�Ѷ�������\t����\n");
	output_split('l');
}

void free_linked(Item *h) //�ͷ��ڴ�
{
	Item* temp;

	while (h->next != NULL)
	{
		temp = h->next;
		free(h);
		h = NULL;
		h = temp;
	}

	free(h);
	h = NULL;
}

/*������*/
int main(void)
{
	//�����ڸ�Ϊ�׵׺���
	system("color F0"); //��ȫ�ֱ�����Ϊ��ɫ�������Ϊ��ɫ
	set_color(0); //��������Ϊ�׵׺���
	welcome(); //��ӭ����

	//�û�ʹ�ý���
	char command1, command2, command3;

	printf("����������(����'q'�˳�ϵͳ): ");
	while (scanf_s("\n%c", &command1, 1) == 1) //��\n����ȡ��û����Ϣ
	{
		if (command1 == 'q') //�˳�����
			break;
		else if (command1 == 'A') //����Ա�˻�
		{
			system("cls");
			if (admin())
			{
				system("cls");
				welcome_admin(); //����ԱȨ�޻�ӭ����
				printf("����������(����'q'�˳�ϵͳ): ");
				while (scanf_s("\n%c", &command2, 1) == 1) //��\n����ȡ��û����Ϣ
				{
					if (command2 == 'q')
					{
						system("cls");
						welcome();
						break;
					}
					else if (command2 == 'A')
					{
						int frequency = 0;
						printf("��Ҫ¼����Ʒ���ݵ�����: ");
						scanf_s("%d", &frequency);
						add_item(frequency);
						printf("����������(����'q'�˳�ϵͳ):");
					}
					else if (command2 == 'D')
					{
						Item* h;
						char numb[10];

						h = read_info();
						system("cls");
						welcome_item();
						int colour;

						while (h->next != NULL)
						{
							h = h->next;
							colour = h->level;
							set_color(colour);
							printf("%s\t", h->numbering);
							printf("%s\t\t", h->name);
							printf("%d\t", h->model);
							printf("%d\t", h->price);
							printf("%d\t\t", h->inventory);
							printf("%d\t\t", h->ordered);
							printf("%s\t\n", h->origin);
							set_color(0);
						}
						h = read_info();
						printf("������Ҫɾ����Ʒ�ı��(����'q'�˳�ϵͳ): ");
						while (1)
						{
							if (scanf_s("\n%s", numb, 10) > 1)
							{
								printf("����������������룡\n");
								printf("������Ҫɾ����Ʒ�ı��(����'q'�˳�ϵͳ): ");
							}
							else
								break;
						}
						delete_info(h, numb); //ɾ����Ʒ

						printf("����Ʒ�Ѿ��ɹ�ɾ����(3 ����˻ص���һ������)");
						Sleep(3000);
						system("cls");
						welcome_admin();
						printf("����������(����'q'�˳�ϵͳ): ");
					}
					else
						printf("���޴������������ȷ������: ");
				}
			}
			else
			{
				printf("���Ѿ����̫����ˣ�\n");
				printf("���Ժ�����!\n");
			}
		}
		else if (command1 == 'F') //������Ʒ
		{
			Item* h;
			char judge[10], quit[2] = "q";
			h = read_info();

			system("cls");
			welcome_find();
			printf("����������(����'q'�˳�ϵͳ): ");
			
			while (scanf_s("\n%c", &command3, 1) == 1)
			{
				if (command3 == 'q')
				{
					break;
					system("cls");
					welcome();
				}
				else if (command3 == 'A') //ȫ�����
				{
					welcome_item();
					int colour;

					while (h->next != NULL)
					{
						h = h->next;
						colour = h->level;
						set_color(colour);
						printf("%s\t", h->numbering);
						printf("%s\t\t", h->name);
						printf("%d\t", h->model);
						printf("%d\t", h->price);
						printf("%d\t\t", h->inventory);
						printf("%d\t\t", h->ordered);
						printf("%s\t\n", h->origin);
						set_color(0);
					}
					h = read_info(); //��ָ������ָ��head
					printf("��������빺�ﳵ����Ʒ���(����'q'�˳�ϵͳ): ");

				}
				else if (command3 == 'M') //�ͺ�
				{
					int colour, mo;

					printf("��������Ҫ���ҵ���Ʒ�ͺ�: ");
					scanf_s("%d", &mo);
					welcome_item();
					while (h->next != NULL)
					{
						h = h->next;
						if (h->model == mo)
						{
							colour = h->level;
							set_color(colour);
							printf("%s\t", h->numbering);
							printf("%s\t\t", h->name);
							printf("%d\t", h->model);
							printf("%d\t", h->price);
							printf("%d\t\t", h->inventory);
							printf("%d\t\t", h->ordered);
							printf("%s\t\n", h->origin);
							set_color(0);
						}
					}
					h = read_info();
					printf("��������빺�ﳵ����Ʒ���(����'q'�˳�ϵͳ): ");
				}
				else if (command3 == 'N') //����
				{
					int colour, length;
					char na[20];

					printf("��������Ҫ���ҵ���Ʒ����: ");
					scanf_s("%s", na, 20);
					length = strlen(na);
					na[length] = '\0';
					welcome_item();
					while (h->next != NULL)
					{
						h = h->next;
						if (strstr(h->name, na))
						{
							colour = h->level;
							set_color(colour);
							printf("%s\t", h->numbering);
							printf("%s\t\t", h->name);
							printf("%d\t", h->model);
							printf("%d\t", h->price);
							printf("%d\t\t", h->inventory);
							printf("%d\t\t", h->ordered);
							printf("%s\t\n", h->origin);
							set_color(0);
						}
					}
					h = read_info();
					printf("��������빺�ﳵ����Ʒ���(����'q'�˳�ϵͳ): ");
				}
				else if (command3 == 'T') //����
				{
					int colour;
					char ty;

					printf("��������Ҫ���ҵ���Ʒ�ͺ�: ");
					scanf_s("\n%c", &ty, 1);
					welcome_item();
					while (h->next != NULL)
					{
						h = h->next;
						if (h->numbering[0] == ty)
						{
							colour = h->level;
							set_color(colour);
							printf("%s\t", h->numbering);
							printf("%s\t\t", h->name);
							printf("%d\t", h->model);
							printf("%d\t", h->price);
							printf("%d\t\t", h->inventory);
							printf("%d\t\t", h->ordered);
							printf("%s\t\n", h->origin);
							set_color(0);
						}
					}
					h = read_info();
					printf("��������빺�ﳵ����Ʒ���(����'q'�˳�ϵͳ): ");

				}
				else
					printf("���޴������������ȷ������: ");

					int len, count = 0;
					scanf_s("\n%s", judge, 10); //������빺�ﳵ��Ʒ�ı��
					len = strlen(judge);
					judge[len] = '\0'; //�����ַ�����ֹ����

					while (h->next != NULL)
					{
						h = h->next;
						if (strcmp(h->numbering, judge) == 0) //�ж��Ƿ��������Ʒ
						{
							count += 1;
							write_cart(h);
							break;
						}
					}
					h = read_info();

					if (strcmp(judge, quit) == 0) //����������
					{
						system("cls");
						welcome_find();
					}
					else if (count == 1) //��Ʒ����
					{
						printf("����ӵ����ﳵ��(3 ��󽫻ص�������)");
						Sleep(3000);
						system("cls");
						welcome_find();
					}
					else //��Ʒ������
					{
						printf("���޴���Ʒ��(3 ��󽫻ص�������)");
						Sleep(3000);
						system("cls");
						welcome_find();
					}
					count = 0;

					printf("����������(����'q'�˳�ϵͳ): ");
					
			}
		}
		else if (command1 == 'S') //�鿴���ﳵ 
		{
			Item* h;
			h = read_cart();

			while (1)
			{
				int colour;
				char order;
				welcome_item();
				while (h->next != NULL)
				{
					h = h->next;
					colour = h->level;
					set_color(colour);
					printf("%s\t", h->numbering);
					printf("%s\t\t", h->name);
					printf("%d\t", h->model);
					printf("%d\t", h->price);
					printf("%d\t\t", h->inventory);
					printf("%d\t\t", h->ordered);
					printf("%s\t\n", h->origin);
					set_color(0);
				}
				h = read_cart();

				printf("\n�Ƿ��µ�(Y/N)(����'q'�˳�ϵͳ)?\n");
				scanf_s("\n%c", &order, 1);

				if (order == 'q')
					break;
				else if (order == 'Y')
				{
					char country[20], province[20], city[20], area[20], street[20], address[100];
					printf("��������ĵ�ַ��\n");
					printf("���ң�");
					scanf_s("%s", country, 20);
					printf("ʡ�ݣ�");
					scanf_s("%s", province, 20);
					printf("���У�");
					scanf_s("%s", city, 20);
					printf("���ڵ�����");
					scanf_s("%s", area, 20);
					printf("�ֵ���");
					scanf_s("%s", street, 20);
					printf("��ϸ��ַ��");
					scanf_s("%s", address, 100);

					system("cls");
					int colour;
					char order;
					welcome_item();
					while (h->next != NULL)
					{
						h = h->next;
						colour = h->level;
						set_color(colour);
						printf("%s\t", h->numbering);
						printf("%s\t\t", h->name);
						printf("%d\t", h->model);
						printf("%d\t", h->price);
						printf("%d\t\t", h->inventory);
						printf("%d\t\t", h->ordered);
						printf("%s\t\n", h->origin);
						set_color(0);
					}
					h = read_cart();

					printf("\n%s%s%s%s%s%s", country, province, city, area, street, address); //��ӡ��ַ
					printf("\n�Ƿ��µ�(Y/N)?\n");
					while (scanf_s("\n%c", &order, 1) == 1)
					{
						if (order == 'Y')
						{
							printf("���ڴ�������...\n");
							Sleep(1000);
							printf("�Բ�������˻���û���㹻�Ľ�(5 ���ص�������)"); //��Ī��Ǯ
							Sleep(5000);
							break;
						}
						else if (order == 'N')
							break;
						else
							printf("��������ȷ�����\n");
					}

				}
				else if (order == 'N')
				{
					Item* h;
					char numb[10];

					h = read_cart();
					system("cls");
					welcome_item();
					int colour;

					while (h->next != NULL)
					{
						h = h->next;
						colour = h->level;
						set_color(colour);
						printf("%s\t", h->numbering);
						printf("%s\t\t", h->name);
						printf("%d\t", h->model);
						printf("%d\t", h->price);
						printf("%d\t\t", h->inventory);
						printf("%d\t\t", h->ordered);
						printf("%s\t\n", h->origin);
						set_color(0);
					}
					h = read_cart();
					printf("������Ҫ�Ƴ����ﳵ����Ʒ���(����'q'�˳�ϵͳ): ");
					while (1)
					{
						if (scanf_s("\n%s", numb, 10) > 1)
						{
							printf("����������������룡\n");
							printf("������Ҫ�Ƴ����ﳵ����Ʒ���(����'q'�˳�ϵͳ): ");
						}
						else
							break;
					}
					delete_cart(h, numb); //ɾ����Ʒ

					printf("����Ʒ�Ѿ��ɹ�ɾ����(3 ����˻ص���һ������)");
					Sleep(3000);
					system("cls");
					welcome_admin();
					printf("����������(����'q'�˳�ϵͳ): ");

				}

				system("cls");
			}
		}
		else
		{
			printf("���޴������������ȷ������: ");
		}

		system("cls");
		welcome();
		printf("����������(����'q'�˳�ϵͳ): ");
	}
	printf("лл�ݹˣ�ϣ�����´�������");

	return 0;
}