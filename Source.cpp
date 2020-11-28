#include<stdio.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)

struct customer {
	char username[20];
	long int phone_number;
	char address[200];
	customer* next;
};

struct food {
	char name[20];
	int price;
	food* next;
};

struct food_row {
	char name[20];
	int quantity;
	food_row* next;
};

struct order {
	int order_number;
	char username[20];
	food_row* Food_row;
	time_t mytime;
	order* next_node;
};

struct Akbar_joojeh {
	customer* customer;
	food* Food;
	order* Order;
};

void print_foods(food* food_list) {
	food* cur_node = food_list;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad 
	{
		printf("\n");
		printf("\tFood name: "); // esme ghaza ra chap konad
		puts(cur_node->name);
		printf("\tPrice: "); // gheymat ra chap konad
		printf("%d\n", cur_node->price); 
		cur_node = cur_node->next; // boro ghere baadi
	}
	printf("\n");
}

void print_customers(customer* customer_root)
{
	customer* cur_node = customer_root;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad  
	{
		printf("\n");
		printf("\tUsername: ");
		for (int i = 0; cur_node->username[i] != NULL; i++)
		{
			printf("%c", cur_node->username[i]);
		}
		printf("\tPhone Number: ");
		printf("%d\n",cur_node->phone_number);
		printf("\tAdress: ");
		for (int i = 0; cur_node->address[i] != NULL; i++)
		{
			printf("%c", cur_node->address[i]);
		}
		cur_node = cur_node->next; // boro ghere baadi
	}
	printf("\n");
}

int insert_customer(customer* customer_root, customer* new_node)
{
	if (new_node == NULL)
	{
		printf("ok");
		return 0;
	}

	customer* cur_node = customer_root;
	customer* pre_node = customer_root;

	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad 
	{
		if (strcmp(cur_node->username, new_node->username) > 0 || cur_node->next == NULL) // sharte ezafe kardan
		{
			new_node->next = pre_node->next;
			pre_node->next = new_node;
			return 1;
		}
		cur_node = cur_node->next; // boro ghere baadi
	}
	return 0;
}

customer* search_customer(customer* customer_root, char username[])
{
	customer* cur_node = customer_root;
	customer* pre_node = customer_root;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad 
	{
		if (cur_node->username[0] == username[0]) // check kardane username gharefte shode ba username har ghere
		{
			for (int i = 0; cur_node->username[i] == username[i]; i++)
			{
				if(cur_node->username[i+1] == NULL || username[i+1] == NULL)
				return cur_node;
			}
		}
		pre_node = cur_node; // be ghere baadi mire
		cur_node = cur_node->next;
	}
	return NULL;
}

food* search_food(food* food_list, char name[])
{
	food* cur_node = food_list;
	food* pre_node = food_list;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad 
	{
		if (cur_node->name[0] == name[0]) // check kardane esme gharefte shode ba esme har ghere
		{
			for (int i = 0; cur_node->name[i] == name[i]; i++)
			{
				if (cur_node->name[i + 1] == NULL || name[i + 1] == NULL)
					return cur_node;
			}
		}
		pre_node = cur_node; // be ghere baadi mire
		cur_node = cur_node->next;
	}
	return NULL;
}

int remove_customer(Akbar_joojeh* akbar_joojeh, char username[])
{
	customer* cur_Remove_customer = NULL;
	customer* pre_Remove_customer = NULL;
	customer* cur_node = akbar_joojeh->customer;
	customer* pre_node = akbar_joojeh->customer;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad
	{
		if (cur_node->username[0] == username[0]) // check kardane esme gharefte shode ba esme har ghere
		{
			for (int i = 0; cur_node->username[i] == username[i]; i++)
			{
				if (cur_node->username[i + 1] == NULL || username[i + 1] == NULL)
				{
					cur_Remove_customer = cur_node; // hazf mikone
					pre_Remove_customer = pre_node;
					pre_Remove_customer->next = cur_Remove_customer->next;
					cur_Remove_customer = cur_Remove_customer->next;
				}
			}
		}
		pre_node = cur_node; // raftan be ghere baadi
		cur_node = cur_node->next;
	}


	order* cur_Remove_order = NULL;
	order* pre_Remove_order = NULL;
	order* cur_node_order = akbar_joojeh->Order;
	order* pre_node_order = akbar_joojeh->Order;
	while (cur_node_order != NULL) // ta vaghti ke be akharin ghere baresad
	{
		if (cur_node_order->username[0] == username[0]) // check kardane esme gharefte shode ba esme har ghere
		{
			for (int i = 0; cur_node_order->username[i] == username[i]; i++)
			{
				if (cur_node_order->username[i + 1] == NULL || username[i + 1] == NULL)
				{
					cur_Remove_order = cur_node_order;
					pre_Remove_order = pre_node_order;
					pre_Remove_order->next_node = cur_Remove_order->next_node;
					cur_Remove_order = cur_Remove_order->next_node;
					return 1;
				}
			}
		}
		pre_node_order = cur_node_order; // raftan be ghere baadi
		cur_node_order = cur_node_order->next_node;
	}
	return 0;
}

void print_orders(Akbar_joojeh* akbar_joojeh) {
	customer* cur_customer = akbar_joojeh->customer;
	order* cur_order = akbar_joojeh->Order;
	int order_number = akbar_joojeh->Order->order_number;

	while (cur_customer != NULL) // ta vaghti ke be akharin ghere baresad
	{
		int total = 0;
		printf("\n");
		printf("Order number: %d\t", order_number);
		printf("Date : ");
		time_t time = akbar_joojeh->Order->mytime;
		printf(ctime(&time));
		printf("\n");
		printf("Username: ");
		puts(cur_customer->username);
		while (cur_order->next_node != NULL)
		{
			if (cur_customer->username[0] == cur_order->username[0]) // yeki yeki moshtari ha ra check mikonad
			{
				for (int i = 0; cur_customer->username[i] == cur_order->username[i]; i++)
				{
					if (cur_customer->username[i + 1] == NULL || cur_order->username[i + 1] == NULL)
					{
						for (int i = 0; cur_order->Food_row->name[i] != NULL ; i++)
						{
							printf("%c", cur_order->Food_row->name[i]);
						}
						food* Search_food = search_food(akbar_joojeh->Food, cur_order->Food_row->name);
						printf("\t%d\t%d\n", cur_order->Food_row->quantity, Search_food->price);
						total = total + (cur_order->Food_row->quantity*Search_food->price); // mohasebe gheymate nahayi
					}
				}
			}
			cur_order = cur_order->next_node;
		}
		printf("Total: %d", total);
		printf("\n**************************************************************\n");
		cur_customer = cur_customer->next; // mire moshtari baadi
	}
}

int remove_order(order* order_list, int order_number)
{
	order* cur_Remove_order = NULL;
	order* pre_Remove_order = NULL;
	order* cur_node_order = order_list;
	order* pre_node_order = order_list;
	while (cur_node_order != NULL) // ta vaghti ke be akharin ghere baresad
	{
		if (cur_node_order->order_number == order_number) // sharte hazf kardan
		{
			cur_Remove_order = cur_node_order; // hazf mikone
			pre_Remove_order = pre_node_order;
			pre_Remove_order->next_node = cur_Remove_order->next_node;
			cur_Remove_order = cur_Remove_order->next_node;
			return 1;
		}
		pre_node_order = cur_node_order; // mire ghere baadi
		cur_node_order = cur_node_order->next_node;
		return 0;
	}
}

int add_food(food* food_list, food* new_food)
{
	if (new_food == NULL)
	{
		return 0;
	}

	food* cur_node = food_list;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad
	{
		if (cur_node->next == NULL)
		{
			cur_node->next = new_food;
			new_food->next = NULL;
			return 1;
		}
		cur_node = cur_node->next;
	}
	return 0;
}

int add_order(Akbar_joojeh* akbar_joojeh, order* new_order)
{
	if (new_order == NULL)
	{
		return 0;
	}

	order* cur_node = akbar_joojeh->Order;
	while (cur_node != NULL) // ta vaghti ke be akharin ghere baresad
	{
		if (cur_node->next_node == NULL)
		{
			cur_node->next_node = new_order; // ezafe mikone
			new_order->next_node = NULL;
			return 1;
		}
		cur_node = cur_node->next_node; // mire ghere baadi
	}
	return 0;
}

int main()
{
	
	/* taarife dummy node ha */

	Akbar_joojeh akbar_joojeh;

	customer customer_root;
	customer* Customer_root = &customer_root;

	customer customer_root_1;
	customer* Customer_root_1 = &customer_root_1;

	for (int i = 0; i < 20; i++)
	{
		customer_root.username[i] = NULL;
	}
	for (int i = 0; i < 20; i++)
	{
		customer_root.address[i] = NULL;
	}

	for (int i = 0; i < 20; i++)
	{
		customer_root_1.username[i] = NULL;
	}
	for (int i = 0; i < 20; i++)
	{
		customer_root_1.address[i] = NULL;
	}
	
	customer_root.username[0] = 'n';
	customer_root.phone_number = -1;
	customer_root.address[0] = 'n';
	customer_root.next = Customer_root_1;

	customer_root_1.username[0] = 'b';
	customer_root_1.phone_number = -1;
	customer_root_1.address[0] = 'b';
	customer_root_1.next = NULL;


	food food_list;
	food* Food_list = &food_list;

	for (int i = 0; i < 20; i++)
	{
		food_list.name[i] = NULL;
	}

	food_list.name[0] = 'n';
	food_list.price = -1;
	food_list.next = NULL;

	order order_list;
	order* Order_list = &order_list;

	for (int i = 0; i < 20; i++)
	{
		order_list.username[i] = NULL;
	}

	order_list.mytime = NULL;
	order_list.next_node = NULL;
	order_list.order_number = -1;
	order_list.username[0] = 'n';

	Akbar_joojeh* Akbar_Joojeh = &akbar_joojeh;
	akbar_joojeh.customer = Customer_root;
	akbar_joojeh.Food = Food_list;
	akbar_joojeh.Order = Order_list;

	int choice; // ghozineyi ke karbar mikhahad
	int order_id = 1;

	while (true)
	{
		printf("\n ** what do you want to do:\n\t1 for adding a customer\n\t2 for removing a 
		customer\n\t3 for searching a customer\n\t4 for printing all the customers\n\t5 for adding a new 
		food\n\t6 for searching a food\n\t7 for printing all foods\n\t8 for adding a new order\n\t9 for removing an 
		order\n\t10 for printing all orders\n\t0 for exiting\n");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			customer new_customer;
			customer* New_customer;
			New_customer = &new_customer;

			char username[20];
			int phone_number;
			char address[250];
			for (int i = 0; i < 20; i++)
			{
				username[i] = NULL;
			}
			for (int i = 0; i < 20; i++)
			{
				address[i] = NULL;
			}

			// ejade yek ghere ba moshakhasati ke karbar mikhahad

			printf("Enter username:\n");
			gets_s(username);
			gets_s(username);
			printf("Enter phone number:\n");
			scanf_s("%d", &phone_number);
			printf("Enter adress:\n");
			gets_s(address);
			gets_s(address);
			for (int i = 0; i < 20; i++)
			{
				new_customer.username[i] = username[i];
			}
			new_customer.phone_number = phone_number;
			for (int i = 0; i < 20; i++)
			{
				new_customer.address[i] = address[i];
			}
			int a;
			new_customer.next = NULL;
			a = insert_customer(Customer_root, New_customer);
			/*if (a != 0)
			{
				print_customers(Customer_root);
			}*/
		}
		if (choice == 2)
		{
			char remove_username[20];
			printf("Enter the customer username you want to remove:\n");
			gets_s(remove_username);
			gets_s(remove_username);
			int a;
			a = remove_customer(Akbar_Joojeh, remove_username);
			if (a == 1)
				printf("customer successfully deleted\n");
			else
				printf("customer not found\n");
		}
		if (choice == 3)
		{
			customer* customer_you_want = NULL;
			char username_1[20];
			printf("Enter username:\n");
			gets_s(username_1);
			gets_s(username_1);
			customer_you_want = search_customer(Customer_root, username_1);
			if (customer_you_want != NULL)
			{
				printf("\n");
				printf("\tUsername: ");
				for (int i = 0; customer_you_want->username[i] != NULL; i++)
				{
					printf("%c", customer_you_want->username[i]);
				}
				printf("\tPhone Number: ");
				printf("%d\n", customer_you_want->phone_number);
				printf("\tAdress: ");
				for (int i = 0; customer_you_want->address[i] != NULL; i++)
				{
					printf("%c", customer_you_want->address[i]);
				}
				printf("\n");
			}
			else
				printf("customer not found\n");
		}
		if (choice == 4)
		{
			print_customers(Customer_root);
		}
		if (choice == 5)
		{
			// ejade yek ghere ba moshakhasati ke karbar mikhahad

			char name_1[20];
			int price;
			food new_food;
			food* New_food = &new_food;
			printf("Enter food name:\n");
			gets_s(name_1);
			gets_s(name_1);
			printf("Enter food price:\n");
			printf("%d\n", &price);
			for (int i = 0; name_1[i] != NULL; i++)
				new_food.name[i] = name_1[i];
			new_food.price = price;
			new_food.next = NULL;
			add_food(Food_list, New_food);
		}
		if (choice == 6)
		{
			food* food_you_want = NULL;
			char name[20];
			printf("Enter username:\n");
			gets_s(name);
			gets_s(name);
			food_you_want = search_food(Food_list, name);

			printf("\n");
			printf("\tFood name: ");
			puts(food_you_want->name);
			printf("\tPrice: ");
			printf("%d\n", food_you_want->price);
		}
		if (choice == 7)
		{
			print_foods(Food_list);
		}

		if (choice == 8)
		{
			order new_order;
			order* New_order = &new_order;
			food_row food_Row[20];
			food_row* Food_row = &food_Row[0];
			for (int i = 0; i < 20; i++)
			{
				for (size_t j = 0; j < 20; j++)
				{
					food_Row[i].name[j] = NULL;
				}
				food_Row[i].quantity = NULL;
			}

			// ejade yek ghere ba moshakhasati ke karbar mikhahad

			char username_2[20];
			printf("Enter username:\n");
			gets_s(username_2);
			gets_s(username_2);
			printf("Enter food name:\n");
			gets_s(food_Row[0].name);
			printf("Enter food quantity\n");
			scanf_s("%d", &food_Row[0].quantity);
			for (int i = 1; food_Row[i-1].name[0] != '0' || i == 18 ; i++)
			{
				printf("Enter food name\n");
				gets_s(food_Row[i].name);
				gets_s(food_Row[i].name);
				printf("Enter food quantity\n");
				scanf_s("%d", &food_Row[0].quantity);
				if (food_Row[i].name[0] != '0' || i == 18) {
					food_Row[i].next = NULL;
					break;
				}
				else
				{
					food_Row[i].next = &food_Row[i + 1];
				}
			}
			new_order.mytime = time(NULL);
			new_order.Food_row = &food_Row[0];
			new_order.order_number = order_id;
			order_id ++;
			new_order.next_node = NULL;
			order_list.Food_row = &food_Row[0];
			int a;
			a = add_order(Akbar_Joojeh, New_order);
			if (a == 1)
				printf("Order successfully added\n");
			else
				printf("Order not found\n");
		}

		if (choice == 9)
		{
			int order_number;
			printf("Enter the order number you want to remove:\n");
			scanf_s("%d", &order_number);
			int a;
			a = remove_order(Order_list, order_number);
			if (a == 1)
				printf("Order successfully deleted\n");
			else
				printf("Order not found\n");
		}
		if (choice == 10)
		{
			print_orders(Akbar_Joojeh);
		}
		if (choice == 0)
		{
			break;
		}
	}
}
